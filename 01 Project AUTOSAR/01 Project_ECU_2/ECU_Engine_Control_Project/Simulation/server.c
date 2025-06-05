/*
 * simple_server.c
 *  - GET  /       -> phục vụ trang index.html
 *  - GET  /data   -> phục vụ dữ liệu JSON chuyển từ data.csv
 *  - Mỗi 1s: thread client gọi GET /data nhưng không in body
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <winsock2.h>      // Thay cho sys/socket.h

#include <windows.h>       // Thay cho unistd.h, cần cho Sleep()

#include <ws2tcpip.h>      // Thay cho arpa/inet.h, netinet/in.h
#include <process.h>       // Thay cho pthread.h trên Windows (_beginthreadex)

#define PORT 8080
#define BUFFER_SIZE 8192
#define MAX_LINES 200

#pragma comment(lib, "Ws2_32.lib") // Liên kết thư viện Winsock

// —————— Helper functions (Hàm trợ giúp cho server) ——————

// Đọc file vào bộ nhớ và trả về chuỗi chứa nội dung file
char *read_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f)
    {
        perror("fopen");
        return NULL;
    }
    if (fseek(f, 0, SEEK_END) != 0)
    {
        perror("fseek");
        fclose(f);
        return NULL;
    }
    long len = ftell(f);
    if (len < 0)
    {
        perror("ftell");
        fclose(f);
        return NULL;
    }
    rewind(f);

    // Cấp phát bộ nhớ và đọc nội dung file
    char *buf = malloc(len + 1);
    if (!buf)
    {
        perror("malloc");
        fclose(f);
        return NULL;
    }
    if (fread(buf, 1, len, f) != (size_t)len)
    {
        perror("fread");
        free(buf);
        fclose(f);
        return NULL;
    }
    buf[len] = '\0'; // Đảm bảo chuỗi kết thúc bằng null
    fclose(f);
    return buf;
}

// Hàm chuyển đổi tên key từ snake_case sang camelCase
char *snake_to_camel(const char *key)
{
    size_t len = strlen(key);
    char *out = malloc(len + 1);
    if (!out)
        return NULL;
    int j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (key[i] == '_' && i + 1 < len)
        {
            out[j++] = toupper((unsigned char)key[++i]); // Chuyển ký tự sau dấu '_' thành chữ hoa
        }
        else
        {
            out[j++] = key[i];
        }
    }
    out[j] = '\0';
    return out;
}

// Kiểm tra xem một chuỗi có phải là số hợp lệ (có dấu chấm thập phân không)
int is_number(const char *s)
{
    int seen_dot = 0, seen_digit = 0;
    for (const char *p = s; *p; p++)
    {
        if (*p == '.')
        {
            if (seen_dot)
                return 0; // Nếu đã gặp dấu chấm thì không hợp lệ
            seen_dot = 1;
        }
        else if (!isdigit((unsigned char)*p))
        {
            return 0; // Nếu không phải chữ số và không phải dấu chấm thì không hợp lệ
        }
        else
        {
            seen_digit = 1;
        }
    }
    return seen_digit;
}

// Chuyển đổi CSV sang JSON
char *csv_to_json(const char *csv_path)
{
    FILE *f = fopen(csv_path, "r");
    if (!f)
    {
        perror("fopen csv");
        return NULL;
    }

    size_t cap = 1024, len = 0;
    char *json = malloc(cap);
    if (!json)
    {
        perror("malloc json");
        fclose(f);
        return NULL;
    }
    json[len++] = '{'; // Mở dấu ngoặc nhọn

    int first = 1;
    char line[512];
    while (fgets(line, sizeof(line), f))
    {
        size_t l = strlen(line);
        while (l > 0 && (line[l - 1] == '\n' || line[l - 1] == '\r'))
            line[--l] = '\0'; // Loại bỏ ký tự newline
        if (l == 0)
            continue; // Bỏ qua dòng trống

        // Tách key và value của dòng CSV
        char *comma = strchr(line, ',');
        if (!comma)
            continue; // Dòng không có dấu ',' thì bỏ qua
        *comma = '\0';
        char *rk = line, *rv = comma + 1;

        char *key = snake_to_camel(rk); // Chuyển key từ snake_case sang camelCase
        if (!key)
            continue;
        int numeric = is_number(rv); // Kiểm tra xem giá trị là số hay chuỗi

        // Tính toán độ dài cần thiết cho JSON
        size_t need = (first ? 0 : 1) + 1 + strlen(key) + 2 + (numeric ? strlen(rv) : (2 + strlen(rv))) + 1;
        if (len + need + 1 > cap)
        {
            cap = (len + need + 1) * 2;
            char *t = realloc(json, cap);
            if (!t)
            {
                perror("realloc");
                free(json);
                free(key);
                fclose(f);
                return NULL;
            }
            json = t;
        }

        if (!first)
            json[len++] = ','; // Thêm dấu phẩy giữa các phần tử
        first = 0;

        json[len++] = '"';
        memcpy(json + len, key, strlen(key));
        len += strlen(key);
        json[len++] = '"';
        json[len++] = ':';

        // Thêm giá trị (numeric hoặc chuỗi)
        if (numeric)
        {
            memcpy(json + len, rv, strlen(rv));
            len += strlen(rv);
        }
        else
        {
            json[len++] = '"';
            memcpy(json + len, rv, strlen(rv));
            len += strlen(rv);
            json[len++] = '"';
        }
        free(key);
    }
    fclose(f);

    json[len++] = '}'; // Đóng dấu ngoặc nhọn
    json[len] = '\0';  // Kết thúc chuỗi
    return json;
}


/*
 * Đọc toàn bộ CSV vào mảng key/value, rồi ghi đè file với
 * chỉ những key có trong JSON được cập nhật giá trị mới.
 */
int updateCsvWithJson(const char *csv_path, const char *json_str) {
    // 1) Load CSV cũ vào bộ nhớ
    FILE *fin = fopen(csv_path, "r");
    if (!fin) {
        perror("fopen for read");
        return -1;
    }

    // Tạm lưu tối đa 200 dòng
    #define MAX_LINES 200
    char *keys[MAX_LINES], *vals[MAX_LINES];
    int  count = 0;

    char line[512];
    while (fgets(line, sizeof(line), fin) && count < MAX_LINES) {
        // trim newline
        size_t L = strlen(line);
        while (L > 0 && (line[L-1]=='\n' || line[L-1]=='\r')) line[--L] = 0;
        if (L==0) continue;

        char *comma = strchr(line, ',');
        if (!comma) continue;
        *comma = 0;
        keys[count] = strdup(line);
        vals[count] = strdup(comma+1);
        count++;
    }
    fclose(fin);

    // 2) Parse JSON thủ công và cập nhật
    //    JSON flat: {"k1":"v1","k2":"v2",...}
    //    loại bỏ { }
    char *jb = strdup(json_str);
    if (!jb) return -1;
    size_t nl = strlen(jb);
    if (jb[0]=='{') memmove(jb, jb+1, nl--);
    if (nl>0 && jb[nl-1]=='}') jb[nl-1]=0;

    // tokenize theo dấu ,
    char *saveptr = NULL, *tok = strtok_r(jb, ",", &saveptr);
    while (tok) {
        // tách key:value
        char *c = strchr(tok, ':');
        if (c) {
            *c = 0;
            char *k = tok, *v = c+1;
            // trim " và spaces
            while (*k==' '||*k=='"') k++;
            char *ke = k+strlen(k)-1;
            while (ke>k && (*ke==' '||*ke=='"')) *ke--=0;
            while (*v==' '||*v=='"') v++;
            char *ve = v+strlen(v)-1;
            while (ve>v && (*ve==' '||*ve=='"')) *ve--=0;

            // tìm trong mảng CSV
            for (int i=0; i<count; i++) {
                if (strcmp(keys[i], k)==0) {
                    free(vals[i]);
                    vals[i] = strdup(v);
                    break;
                }
            }
        }
        tok = strtok_r(NULL, ",", &saveptr);
    }
    free(jb);

    // 3) Ghi ngược lại file CSV, giữ nguyên thứ tự
    FILE *fout = fopen(csv_path, "w");
    if (!fout) {
        perror("fopen for write");
        return -1;
    }
    for (int i=0; i<count; i++) {
        fprintf(fout, "%s,%s\n", keys[i], vals[i]);
        free(keys[i]);
        free(vals[i]);
    }
    fclose(fout);
    return 0;
}


// Hàm gửi phản hồi HTTP cho client
void send_response(int client, const char *status,
                   const char *content_type, const char *body)
{
    char header[BUFFER_SIZE];
    int blen = strlen(body);
    int hlen = snprintf(header, sizeof(header),
                        "HTTP/1.1 %s\r\n"
                        "Content-Type: %s\r\n"
                        "Content-Length: %d\r\n"
                        "Connection: close\r\n"
                        "\r\n",
                        status, content_type, blen);
    if (send(client, header, hlen, 0) < 0)
        perror("send header");
    if (send(client, body, blen, 0) < 0)
        perror("send body");
}

// --- Xử lý POST /save-data --------------------------------------------------

void handle_post_save_data(int client, const char *buffer, int len)
{
    // 1) Lấy Content-Length
    int content_length = 0;
    char *cl = strstr(buffer, "\r\nContent-Length: ");
    if (cl)
        sscanf(cl, "\r\nContent-Length: %d", &content_length);

    // 2) Tìm vị trí bắt đầu của body (sau "\r\n\r\n")
    char *body_start = strstr(buffer, "\r\n\r\n");
    int header_len = body_start ? (int)(body_start - buffer) + 4 : len;

    // 3) Sao chép phần body đã có
    int body_read = len - header_len;
    char *body = malloc(content_length + 1);
    if (!body)
    {
        send_response(client, "500 Internal Server Error", "text/plain", "Server OOM");
        return;
    }
    memcpy(body, buffer + header_len, body_read);

    // 4) Đọc thêm nếu còn thiếu
    while (body_read < content_length)
    {
        int r = recv(client, body + body_read, content_length - body_read, 0);
        if (r <= 0)
            break;
        body_read += r;
    }
    body[content_length] = '\0';

    // 5) Xử lý dữ liệu

    // sau khi đã đọc lên body[]
    if (updateCsvWithJson("data.csv", body) == 0) {
        send_response(client, "200 OK", "text/plain", "Data saved");
    } else {
        send_response(client, "500 Internal Server Error", "text/plain", "Save failed");
    }
    free(body);

    // 6) Gửi phản hồi xác nhận
    send_response(client, "200 OK", "text/plain", "Data received successfully");
}

// —————— Thread client mỗi 1s gọi GET /data NHƯNG KHÔNG IN BODY ——————

unsigned __stdcall client_thread(void *arg)
{
    (void)arg; // Để tránh cảnh báo unused parameter
    while (1)
    {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0)
        {
            perror("client socket");
            goto wait;
        }

        struct sockaddr_in srv = {
            .sin_family = AF_INET,
            .sin_port = htons(PORT),
            .sin_addr.s_addr = inet_addr("127.0.0.1")};
        if (connect(sock, (struct sockaddr *)&srv, sizeof(srv)) < 0)
        {
            perror("client connect");
            closesocket(sock);
            goto wait;
        }

        // Gửi GET /data
        const char *req =
            "GET /data HTTP/1.1\r\n"
            "Host: localhost:8080\r\n"
            "Connection: close\r\n"
            "\r\n";
        if (send(sock, req, strlen(req), 0) < 0)
        {
            perror("client write");
            closesocket(sock);
            goto wait;
        }

        // Đọc response và bỏ qua (không in)
        char buf[BUFFER_SIZE];
        while (recv(sock, buf, sizeof(buf), 0) > 0)
        {
            // discard
        }
        closesocket(sock);

    wait:
        Sleep(1000); // Đợi 1 giây trước khi gọi lại
    }
    return 0;
}

int main()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) 
    {
        fprintf(stderr, "WSAStartup failed\n");
        return 1;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        WSACleanup();
        return 1;
    }

    char opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr = 
    {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    if (listen(server_fd, 5) < 0)
    {
        perror("listen");
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }

    printf(" Server run at:\n"
           "   - http://localhost:%d/\n"
           "   - http://localhost:%d/data\n\n",
           PORT, PORT);

    uintptr_t tid = _beginthreadex(NULL, 0, client_thread, NULL, 0, NULL);

    if (tid == 0)
    {
        perror("pthread_create");
        // tiếp tục chạy server chính
    }

    while (1)
    {
        int client = accept(server_fd, NULL, NULL);
        if (client < 0)
        {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE];
        int len = recv(client, buffer, sizeof(buffer) - 1, 0);
        if (len <= 0)
        {
            closesocket(client);
            continue;
        }
        buffer[len] = '\0';

        char method[16], path[256];
        sscanf(buffer, "%s %s", method, path);

        if (strcmp(method, "GET") == 0)
        {
            if (strcmp(path, "/") == 0)
            {
                char *html = read_file("index.html");
                if (html)
                {
                    send_response(client, "200 OK", "text/html", html);
                    free(html);
                }
                else
                {
                    send_response(client, "404 Not Found", "text/plain", "Not Found");
                }
            }
            else if (strcmp(path, "/styles.css") == 0)
            {
                char *css = read_file("styles.css");
                if (css)
                {
                    send_response(client, "200 OK", "text/css", css);
                    free(css);
                }
                else
                {
                    send_response(client, "404 Not Found", "text/plain", "Not Found");
                }
            }
            else if (strcmp(path, "/script.js") == 0)
            {
                char *js = read_file("script.js");
                if (js)
                {
                    send_response(client, "200 OK", "application/javascript", js);
                    free(js);
                }
                else
                {
                    send_response(client, "404 Not Found", "text/plain", "Not Found");
                }
            }
            else if (strcmp(path, "/data") == 0)
            {
                char *json = csv_to_json("data.csv"); // hoặc read_file tạm thời
                if (json)
                {
                    send_response(client, "200 OK", "application/json", json);
                    free(json);
                }
                else
                {
                    send_response(client, "500 Internal Server Error", "text/plain", "Error reading CSV");
                }
            }
            else
            {
                send_response(client, "404 Not Found", "text/plain", "Not Found");
            }
        }else if (strcmp(method, "POST") == 0 && strcmp(path, "/save-data") == 0)
        {
            
            handle_post_save_data(client, buffer, len);
        }

        closesocket(client);
    }

    closesocket(server_fd);
    WSACleanup();
    return 0;
}
