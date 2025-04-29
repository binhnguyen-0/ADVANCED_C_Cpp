<a name="top"></a>
# 📖 ADVANCED_C_Cpp
----
<details>
<summary>🔖 <b>BÀI 1: COMPILER - MACRO</b></summary>
 
### 📑 I. Compiler:
- Trình biên dịch là chương trình chuyển đổi source code C thành mã máy để máy tính có thể thực thi.
- Quá trình biên dịch gồm 4 giai đoạn:
  - Preprocess (Tiền xử lý):
    - **Lệnh tạo _file.i_ từ _file.c_ với trình gcc trong VS Code:** `gcc -E file.c -o file.i`.
    - **Xử lý các loại chỉ thị tiền xử lý:** `#include`, `#define`, `#ifdef`, etc.
    - **Xóa các comment:** `// comment`, `/* comment */`.
  - Compiler (Quá trình biên dịch):
    - **Lệnh tạo _file.s_ từ _file.i_:** `gcc -S file.i -o file.s`.
    - **File.s là file assembly code (mã hợp ngữ):** là ngôn ngữ bậc thấp, giúp điều khiển phần cứng dễ dàng.
  - Assembler (Quá trình dịch hợp ngữ):
    - **Lệnh tạo _file.o_ từ _file.s_:** `gcc -c file.s -o file.o`.
    - **File.o là file Object:** dịch Assembly code thành mã máy mà máy tính có thể hiểu được.
  - Linker (Quá trình liên kết):
    - **Lệnh tạo _file.exe_ từ các _file.o_:** `gcc file1.o file2.o -o filemain`.
    - **Lệnh chạy _file.exe_:** `./filemain`.
    - **Liên kết các file.o:** Tất cả các file.o sẽ được liên kết lại và tạo thành 1 file.exe để có thể chạy được chương trình.

![Image](https://github.com/user-attachments/assets/3a955cb2-1589-4680-a75e-5d2ec4b280ac)

### 📑 II. Preprocessor Directives (Chỉ thị tiền xử lý):
- Là các instructors cho Preprocessor để thực hiện các nhiệm vụ như thay thế văn bản, mở rộng macro, thêm header file, và các nhiệm vụ khác.
- Bắt đầu bằng `#`.
- Các loại chỉ thị tiền xử lý:<br>

|📋 Preprocessor Directives|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**`#define`**|Dùng để define Macro|`#define PI 3.14` <br>`#define SQUARE(x) ((x) * (x))`<br>`#define MAX(x, y) ((x) > (y) ? (x) : (y))`<br>`#define SUM(a,b,c) \`<br>  `(a + b+ c)`: dùng dấu gạch chéo `\` để báo rằng macro vẫn tiếp tục ở dòng dưới|
|**`#undef`**|Dùng để hủy định nghĩa Macro|`#define SENSOR_DATA 42`: định nghĩa macro<br>`#undef SENSOR_DATA `: hủy định nghĩa<br>`#define SENSOR_DATA 50`: định nghĩa lại bằng giá trị khác|
|**`#include`**|Dùng để đưa các tệp bên ngoài vào chương trình hiện tại|`#include <stdio.h>`: yêu cầu Compiler tìm kiếm file trong Standard Directory của Compiler<br>`#include "file.h"`: tìm kiếm trong directory của source file|
|**`#if`**|Kiểm tra điều kiện được chỉ định|`#define STM32 0`<br>`#define ATMEGA 1`<br>`#define PIC 2`<br>`#if MCU == STM32`|
|**`#elif`**|Thêm 1 điều kiện nữa trong **#if & #else**|`#elif MCU == ATMEGA`: nếu điều kiện của **#if** sai thì xét điều kiện của **#elif**|
|**`#else`**|Thực thi mã thay thế khi điều kiện của **#if hay #elif** sai||
|**`#endif`**|Dùng để đánh dấu sự kết thúc của **#if & #ifdef & #ifndef**||
|**`#ifdef`**|Kiểm tra 1 Macro đã được định nghĩa hay không, có thì thực thi mã bên dưới.|`#define DEBUG`<br>`#ifdef DEBUG`<br>`...`<br>`#endif`|
|**`#ifndef`**|Kiểm tra 1 Macro chưa được định nghĩa, nếu đúng mã bên dưới sẽ được thực thi|`#ifndef PI`<br>`#define PI 3.14159`<br>`#endif`|
- Một số các toán tử trong Macro:<br>

|📋 Macro of Operators|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**`#`**|Biến tham số thàng dạng chuỗi (string literal)|`#define TO_STRING(X) #X`<br>`printf("%s\n", TO_STRING(Hello World));`: TO_STRING(Hello World) sẽ thành chuỗi "Hello World" khi biên dịch|
|**`##`**|Nối 2 tham số|`#define VAR(name,num) name##num`<br>`int var1 = 10;`<br>`int var2 = 20;`<br>`printf("var1 = %d, var2 = %d", VAR(var,1), VAR(var,2));`: nối var với 1 thành var1 và tương tự với var2|
|**`Variadic`**|Toán tử `__VA_ARGS__` được dùng khi Macro nhận nhiều tham số không xác định|`#define sum(...) \`<br>`int arr[__VA_ARGS__]; \`<br>`int result = 0; \`<br>`for (int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) \`<br>`{ result += arr[i]; } \`<br>`printf("Sum = %d\n", result);`<br>--> `sum(1,2,3,4);`: tính tổng 1+2+3+4|
<br>

[🔼 _UP_](#top)

  </details>
<details>
<summary>🔖 <b>BÀI 2: STDARG - ASSERT</b></summary>
 
### 📑 I. Thư viện STDARG:
- Cung cấp các Macro để xử lý các hàm với số lượng tham số không xác định.
- Thư viện có các Macro chính như sau:<br>

|📋 Macro of STDARG|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**`va_list list;`**|Tạo danh sách tham số biến - Khai báo 1 biến kiểu valist để lưu trữ thông tin cần thiết để truy xuất các tham số bổ sung.|`#include <stdio.h>`<br>`#include <stdarg.h>`<br>`int sum(int count, ...)`: cho phép truyền các tham số biến và để truy cập các tham số biến đó phải dùng các Macro.<br>`{`<br>`va_list args`: khai báo 1 biến args kiểu va_list|
|**`va_start(list, fixed_argument)`**|Khởi tạo danh sách đối số - Khởi tạo list để truy xuất các tham số trong phần tham số biến (...)|`va_start(args,count);`: khởi tạo list args và tham số fixed_argument cuối cùng trước các tham số biến (...)|
|**`va_arg(list, type)`**|Truy xuất tham số - Trả về tham số tiếp theo từ list & type: kiểu dữ liệu của tham số để truy xuất|`int result = 0;`<br>`for (int i = 0; i < count; i++)`<br>`{result += va_arg(args, int);}`: dùng va_arg để **truy xuất từng tham số trong danh sách sau mỗi lần gọi** và cộng dồn lên vào result ta được tổng tất cả các tham số|
|**`va_end(list)`**|Dọn dẹp va_list|`va_end(args);`<br>`return result;`<br>`}`|
<br>

- Ví dụ kết hợp **STDARG** với **__VA_ARGS__**:<br>

|📋 STDARG & __VA_ARGS__|📄 Description|
|:----------------------|:-------------|
|`#define tong(...) sum(__VA_ARGS__,'\n')`|: |
|`int sum(int count,...)`<br>`{`|: khởi tạo hàm sum truyền vào 1 fixed argument và các tham số chưa biết trước|
|`va_list args;`<br>`va_list check;`<br>`va_copy(check, args);`<br>`va_start(args, count;)`<br>`int result = count;`|: khai báo biến args kiểu va_list dùng để tính tổng.<br>: khai báo biến check sử dụng để kiểm tra điều kiện mà không phải gọi thêm va_arg(args, int).<br>: sao chép dữ liệu từ args vào check<br>: khởi tạo list args và tham số cuối count.<br>: khởi tạo biến result = tham số cuối count để tính tổng từ count trở đi.|
|`while ((va_arg(check, char*)) != (char*)'\n')`<br>`{ result += va_arg(args, int);}`|: dùng hàm while để kiểm tra điều kiện dừng check = '\n'.<br>: dùng va_arg để truy xuất từng tham số trong danh sách sau mỗi lần gọi và cộng dồn lên vào result ta được tổng tất cả các tham số|
|`va_end(args);`|: dọn sạch args. Có thể dùng va_end(check) thay thế.|
|`int main()`<br>`{`<br>`printf("Tổng: %d\n", tong(3, 2, 4, 0, 6));`<br>`return 0;`<br>`}`|: tính tổng tất cả các số trong gọi hàm.|

### 📑 II. Thư viện Assert:
- Cung cấp Macro để kiểm tra điều kiện, nếu điều kiện sai = 0 thì chương trình dừng và thông báo lỗi ở file nào và dòng nào.
- Ví dụ:<br>

|📋 assert.h|📄 Description|
|:----------------------|:-------------|
|`assert(x == 5 && "x phải bằng 5")`|: sử dụng assert để kiểm tra xem liệu có thỏa mãn điều kiện thì mới cho chương trình chạy tiếp còn không thì dừng lại và thông báo lỗi|
|`define LOG(condition, cmd) assert(condition && #cmd)`|: có thể kết hợp với define|
<br>

[🔼 _UP_](#top)

</details>

<details>
<summary>🔖 <b>BÀI 3: BITMASK</b></summary>
 
- Bitmask là một kỹ thuật thao tác trên các bit của dữ liệu để kiểm tra, đặt hoặc xóa bit cụ thể.
 
### 📑 I. Các toán tử bitwise:

👉 1. NOT bitwise:
   - Truth table:

|A|~A|
|:-----:|:-----:|
|0|1|
|1|0|

👉 2. AND bitwise:
   - Truth table:

|A|B|A&B|
|:-:|:-:|:-:|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

👉 3. OR bitwise:
   - Truth table:

|A|B|A&B|
|:-:|:-:|:-:|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

👉 4. XOR bitwise:
   - Truth table: **Bằng 1** nếu 2 bit khác nhau, **bằng 0** nếu 2 bit giống nhau.

|A|B|A&B|
|:-:|:-:|:-:|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

👉 5. Dịch trái `<<`, dịch phải `>>`:
   - Dịch trái là nhân với 2^n, n - số bit dịch, xóa bit bên trái ngoài cùng và thêm 0 vào đuôi bên phải ngoài cùng.
   - Dịch phải là chia với 2^n, n - số bit dịch, xóa bit bên phải ngoài cùng và thêm 0 hoặc 1 (tùy thuộc vào bit MSB)  vào đuôi bên trái ngoài cùng.
   
|A|A' = A << 1|A' >> 1|
|:-:|:-:|:-:|
|0001 (1)|0010 (2)|0001 (1)|
|0010 (2)|0100 (4)|0010 (2)|
|0100 (4)|1000 (8)|0100 (4)|

- Ví dụ: 
<br>

```C
#define GENDER 1 << 0    // 0b00000001
#define TSHIRT 1 << 1    // 0b00000010
#define HAT 1 << 2       // 0b00000100
#define SHOES 1 << 3     // 0b00001000
#define FEATURES 1 << 4  // 0b00010000

/* Hàm bật tính năng */
void enableFeature(uint8_t *options, uint8_t feature)
{
  *options |= feature;     // Bật tính năng cho options sử dụng phép OR.
}

/* Hàm tắt tính năng */
void disableFeature(uint8_t *options, uint8_t feature)
{
  *options &= ~feature;   // Tắt tính năng sử dụng phép AND với ~feature.
}

/* Hàm kiểm tra tính năng đã bật hay chưa*/
int8_t isFeatureEnabled(uint8_t options, uint8_t feature)
{
    return (options & feature) != 0;    // Đọc xem các bit tính năng có bằng 0 hay không dùng phép AND.
}

/* In ra những tính năng đã bật*/
void listSelectedFeatures(uint8_t options)
{
  printf("Selected Features: \n");
  const char* featureName[] =
  {
    "Gender",
    "Shirt",
    "Hat",
    "Shoes",
    "Additional feature"
  };
  for (int i = 0; i < 8; i++)
  {
    if ((options >> i) & 1)
    {
      printf("%s\n", featureName[i]);     // Kiểm tra xem options dịch phải i lần & với 1 = 1 thì in ra phần tử chuỗi thứ i của mảng featureName.
    }
  }
}

int main(int argc, char const *argv[])
{
  uint8_t options = 0;
  enableFeature(&options, GENDER | TSHIRT | HAT);    // truyền vào địa chỉ options, và các giá trị tính năng cần thiết để bật tính năng.
  disableFeature(&options, HAT | TSHIRT);    // loại bỏ 2 tính năng đã bật trước đó
}
  listSelectedFeatures(options);    // truyền vào giá trị sao chép của options sau khi đã bật cá tính năng để in ra các tính năng đó.
  return 0;
```
[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 4: POINTER</b></summary>
 
<br>

|📋 Pointer|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**Khái niệm**|Là một biến chứa giá trị là địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm).||
|**Address Operator (&)**|Được sử dụng để lấy địa chỉ của một biến hoặc để truy cập địa chỉ của một biến tới con trỏ.|`int x =10;`<br>`int *ptr = &x;`: biến con trỏ ptr lưu trữ địa chỉ của biến x|
|**Dereferencing Operator (*)**|Được sử dụng để khai báo biến con trỏ và truy cập giá trị được lưu trữ trong địa chỉ.|`int x =10;`<br>`int *ptr = &x;`<br>`int y = *ptr;`: biến y sẽ bằng giá trị của biến x;|
|**Kích thước**|Phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc là kiến trúc của vi xử lý.|Với máy tính có 64 bit operating system thì thường là pointer sẽ có kích thước là 8 bytes (64 bit).|
|**Format Specifier %p**|Dùng để in địa chỉ được lưu trữ trong con trỏ. Định dạng địa chỉ bộ nhớ luôn ở dạng thập lục phân (0x...)|`printf("%p\n", ptr);`|
|**Declare pointer**|Để khai báo 1 con trỏ, ta dùng Dereferencing Operator (*).|`int *ptr;`|
|**Initialize Pointer**|Để khởi tạo 1 con trỏ, ta dùng Address Operator (&) để gán giá trị địa chỉ của 1 biến vào con trỏ.|`*ptr = &variable;`|
|**Pointer Definition**|Có thể vừa khai báo vừa khởi tạo trong một bước - định nghĩa con trỏ.|`int *ptr = &variable;`|

### I. Con trỏ thường:
- Con trỏ có thể trỏ tới bất kỳ kiểu dữ liệu nguyên thủy nào.
- Cách 1 biến được lưu trữ trong bộ nhớ:
  - Ví dụ 1 biến int 32 bit (4 byte) được lưu trữ thành 1 nhóm địa chỉ, mỗi địa chỉ lưu trữ 8 bit (1 byte) giá trị bắt đầu từ LSB đến MSB.
 ![Cách lưu trữ địa chỉ và giá trị của biến int](https://github.com/user-attachments/assets/3f4514ad-3758-4354-9fec-4e81327a2e0c)
- Cách 1 con trỏ được lưu trữ trong bộ nhớ:
  - Ví dụ 1 con trỏ trỏ tới 1 biến int, mỗi địa chỉ của con trỏ sẽ lưu trữ 1 giá trị là địa chỉ của biến int đó, và những địa chỉ còn lại sẽ được mặc định là chứa 0x00 (địa chỉ mặc định này có thể chứa giá trị rác).
![image](https://github.com/user-attachments/assets/ead4d1e7-bd97-4098-bb93-aa32a198e32a)

### II. Array Pointer - Con trỏ mảng:

- Con trỏ mảng là con trỏ trỏ tới phần tử đầu tiên của mảng hoặc là trỏ tới toàn bộ mảng.
<br>

|📋 Array Pointer|📄 Description|
|:------------------------|:------------------------|
|`int main() {`<br>`int arr[5] = {1, 2, 3, 4, 5};`<br>`int *ptr = arr;`<br>`int (*ptr_arr)[5] = &arr;`|<br><br>: ptr là con trỏ trỏ tới phần tử đầu tiên của mảng.<br>: ptr_arr là con trỏ trỏ đến toàn bộ mảng|
|`int n = sizeof(arr)/sizeof(arr[0]);`<br>`for (int i; i < n; i++)`<br>`printf("%d", (*ptr)[i]);`<br>`for (int i; i < n; i++)`<br>`printf("%d", ptr+i);`|: n = số phần tử trong mảng.<br><br>: truy cập từng phần tử trong mảng đối với con trỏ trỏ đến toàn bộ mảng<br><br>: truy cập phần tử trong mảng đối với con trỏ trỏ đến thành phần đầu tiên của mảng.|

### III. Void Pointer:
- Là con trỏ không có kiểu dữ liệu liên kết với nó. Nó có thể trỏ tới bất kỳ địa chỉ nào thuộc bất kỳ kiểu dữ liệu nào.
- Ví dụ:
  - Con trỏ void không thể giải tham chiếu để lấy giá trị nên phải sử dụng ép kiểu và sau đó là giải tham chiếu cho nó.
```c
int main()
{
  int a = 10;
  char b = 'N';
  char arr[] = "Hello World";

  void *ptr = &a;
  printf("Địa chỉ: %p - Giá trị: %d\n", ptr, *(int*)ptr);

  ptr = &b;
  printf("Địa chỉ: %p - Giá trị: %c\n", ptr, *(char*)ptr);

  ptr = arr;
  for (int i=0; i < (sizeof(arr)/sizeof(arr[1])); i++)
    printf("Địa chỉ: %p - Giá trị: %s\n", ptr, *(char*)(ptr+i));

  /* Mảng con trỏ */
  void *ptr1[] = {&a, &b, arr};
  printf("Địa chỉ: %p - Giá trị: %d\n", ptr1[0], *(int*)ptr1[0]);
  printf("Địa chỉ: %p - Giá trị: %c\n", ptr1[1], *(char*)ptr1[1]);
  return 0;
}
```

### IV. Function Pointer - Con trỏ hàm:

<br>

|📋 Function Pointer|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**Khái niệm**|Con trỏ hàm lưu trữ địa chỉ của một hàm, cho phép hàm được truyền dưới dạng tham số cho một hàm khác, hoặc là truyền hàm như một giá trị trả về từ một hàm khác.||
|**Declaration**|Cú pháp khai báo:<br>`<return type> (*pointer_name) (parameter_types)`.|`int sum(int a, int b)<br>{return a+b;}`<br>-->`int (*ptr) = (int, int);`: con trỏ hàm phải được khai báo sao cho trùng khớp với kiểu trả về, số lượng và loại tham số của hàm.|
|**Initialization**|Sau khai báo con trỏ hàm thì đến bước khởi tạo nó.|`ptr = &sum`<br>hoặc `ptr = sum;`|
|**Function call**|Có 3 cách gọi hàm khi có con trỏ hàm: <br>1. `sum(1, 2);`<br>2. `ptr(1,2);`: gọi trực tiếp giống gọi hàm.<br>3. `(*ptr)(1,2);`: dùng `*` để giải tham chiếu.||

<br>

- Ví dụ:
```c
void tong(int a, int b) {printf("Tổng là: %d", a+b);}
void hieu(int a, int b) {printf("Hiệu là: %d", a-b);}
void tich(int a, int b) {printf("Tích là: %d", a*b);}
void thuong(int a, int b) {printf("Thương là: %d", (double)a/b);}
void tinhtoan(void (*ptr_arg)(int, int), int a, int b) {ptr_arg(a,b);} // Định nghĩa hàm tinhtoan chứa tham số là con trỏ hàm.

int main ()
{
  void (*ptr)(int, int);  // Khai báo con trỏ hàm
  ptr = tong;  // Khởi tạo con trỏ hàm là hàm tong
  ptr(1,2);
  ptr = hieu;  // Khởi tạo con trỏ hàm là hàm hieu
  ptr(1,2);

  void (*ptr_arr[])(int, int) = {tong, hieu, tich, thuong};  // Định nghĩa một mảng con trỏ hàm chứa địa chỉ của các hàm.
  ptr_arr[0](1,2);  // Gọi hàm tổng
  ptr_arr[1](1,2);  // Gọi hàm hiệu

  tinhtoan(tong, 1, 2);  // Truyền tham số là hàm tong để tính tổng.
  tinhtoan(hieu, 1, 2);  // Truyền tham số là hàm hieu để tính hiệu.
}
```

### V. Pointer & Constant - Con trỏ & Hằng số:

|📋 Đặc điểm |Pointer to Constant|Constant Pointer|Constant Pointer to Constant|
|:------------------------:|:------------------------:|:------------------------:|:------------------------:|
|**Cách khai báo**|`const int *ptr;`<br>`int const *ptr;`|`int *const ptr;`|`const int *const ptr;`|
|**Giá trị biến**|❌ Không thể thay đổi|✔️ Có thể thay đổi|❌ Không thể thay đổi|
|**Địa chỉ trỏ tới**|✔️ Có thể thay đổi|❌ Không thể thay đổi|❌ Không thể thay đổi|

### VI. NULL Pointer - Con trỏ NULL:

<br>

|📋 NULL Pointer|📄 Description|💡 Examples|
|:------------------------:|:------------------------|:------------------------|
|**Khái niệm**|Con trỏ NULL là con trỏ không trỏ đến bất cứ 1 địa chỉ nào ngoài NULL.||
|**Declaration**|Cú pháp khai báo:<br>`<type> (*pointer_name) = NULL;`<br>`<type> (*pointer_name) = 0;`.||
|**Uses**|1. Khai báo 1 con trỏ mà chưa cần dùng tới ngay.<br>2. Gán NULL cho con trỏ khi sử dụng xong để tránh thay đổi giá trị của một biến nó trỏ tới.|`int *ptr = NULL;`: trỏ tới địa chỉ 0x00|

### VII. Pointer to Pointer - Con trỏ trỏ đến con trỏ:
- Là con trỏ lưu trữ địa chỉ của con trỏ khác - con trỏ kép.
- Để truy cập giá trị được trỏ bởi con trỏ kép ta phải giải tham chiếu 2 lần:
![Image](https://github.com/user-attachments/assets/65958e2e-2243-45f0-81b4-dd802755b3f6)
- Được ứng dụng trong:
  - Kiểu dữ liệu JSON.
  - Cấu trúc dữ liệu danh sách liên kết.

[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 5: STORAGE CLASSES</b></summary>

- Storage class xác định phạm vi (scope), thời gian tồn tại (lifetime), và khả năng hiển thị của biến - chỉ định vị trí lưu trữ của biến, giá trị tồn tại trong bao lâu và cách truy cập giúp theo dõi sự tồn tại của 1 biến trong thời gian chạy chương trình.
- Có 4 lớp lưu trữ chính:
  - `auto`
  - `register`
  - `static`
  - `extern`

|📋 Storage Class |`auto`|`extern`|`static`<br>(Local)|`static`<br>(Global)|`register`|
|:------------------------:|:------------------------:|:------------------------:|:------------------------:|:------------------------:|:------------------------:|
|**Default value**|Giá trị rác|0|0|0|Giá trị rác|
|**Scope**|Local|Global|Local|Global<br>(chỉ trong file hiện tại)|Local|
|**Life time**|Cho đến khi kết thúc phạm vi của nó|Đến khi kết thúc chương trình|Đến khi kết thúc chương trình|Đến khi kết thúc chương trình|Cho đến khi kết thúc phạm vi của nó|
|**Memory location**|RAM|RAM|RAM|RAM|Thanh ghi trong CPU|
|**Đặc điểm**|Sử dụng để khai báo 1 biến cục bộ với bộ nhớ tự động. Tuy nhiên trong C, các biến cục bộ sẽ theo mặc định là 1 auto nên việc thêm auto là tùy chọn.|Dùng lại biến toàn cục trong 1 hàm khác. Hoặc sử dụng biến từ file khác|Duy trì giá trị của 1 biến|Hạn chế truy cập từ file khác|Truy xuất nhanh hơn, nhưng không thể lấy địa chỉ - `&`|

### I. Từ khóa Extern:
- Cú pháp:
  - extern type var_name;
  - extern return_type func_name;
>ℹ️Khai báo trên nói Compiler biết rằng biến và hàm được định nghĩa trong file khác. Nên bước tiếp theo là phải liên kết 2 file này lại với nhau để Compiler có thể tìm thấy định nghĩa của chúng.
>`gcc file.c file1.c -o main`: tạo ra file thực thi cho các file liên kết.
>`/.main`: chạy file thực thi.
>Các biến & hàm này phải là global scope, còn nếu trong local scope thì Compiler không thể tìm thấy được.
- Ví dụ:
  - Sử dụng từ khóa `extern` để khai báo các biến và hàm trong file.h để dễ dàng thêm vào các file khác.
![Image](https://github.com/user-attachments/assets/98f450b0-f6b5-4ee3-a5d9-d873eac24129)

### II. Static local:
- Khi `static` được sử dụng với biến cục bộ thì:
  - Giữ phạm vi của biến chỉ trong hàm chứa nó.
  - Giữ giá trị của biến qua các lần gọi.
- Ví dụ:
  - Khi mỗi lần gọi hàm `count` thì kết quả biến `a` luôn = 1 bởi vì dòng khởi tạo biến luôn được thực thi nên mỗi lần gọi kết quả đều giống nhau.

![image](https://github.com/user-attachments/assets/e3d99e12-f937-4b09-88e5-60403b8dfb75)

  - Khi sử dụng từ khóa `static` thì kết quả biến `a` sẽ được giữ nguyên sau mỗi lần gọi hàm bởi vì dòng khởi tạo sẽ bị bỏ qua trong lần gọi hàm tới nên giá trị sẽ được cộng thêm.
 
![Image](https://github.com/user-attachments/assets/71b379bd-c709-4b8d-ac9d-d9a046600f3a)

>ℹ️ Không thể khai báo hàm static bên trong 1 hàm khác, từ khóa `static` chỉ áp dụng cho hàm global.<br>
>Có thể thay đổi giá trị của biến static từ bên ngoài bằng con trỏ:
```C
#include <stdio.h>

int *ptr = NULL;  // Khởi tạo 1 con trỏ kiểu NULL

void count()
{
    static int a = 0;   // Giá trị của biến a sẽ được giữ nguyên mỗi lần gọi hàm
    ptr = &a;  // Gán địa chỉ biến a vào con trỏ
    printf("a = %d\n", ++a);
}

int main()
{
    count();    // a = 1
    count();    // a = 2
    count();    // a = 3
    *ptr = 99;  // a = 99
    count();    // a = 100
    return 0;
}
```
### III. Static global:
- Khi `static` sử dụng với biến và hàm ở phạm vi global thì nó sẽ hạn chế phạm vi của biến và hàm đó chỉ được dùng trong file hiện tại.
- Ứng dụng:
  - Thiết kế file thư viện mà không muốn người dùng sử dụng đến 1 số biến hay hàm có chức năng đặc biệt.
- Ví dụ:
  - Khi sử dụng từ khóa static cho các biến `var_global` và hàm `display` trong `file1.c` thì biến và hàm đó đã bị hạn chế chỉ được sử dụng trong `file1.c` đó.
  - Dù có sử dụng thêm `extern int var_global` trong `main.c` đã được include `file1.h` để thông báo Compiler nhưng Compiler không thể tìm thấy do đặc tính của **static global**.

![Image](https://github.com/user-attachments/assets/71f2ee4a-b1f6-4481-a4fd-337aafb34f62)

### IV. Từ khóa register:
- Từ khóa `register` được sử dụng để yêu cầu Compiler lưu trữ một biến trong **thanh ghi CPU** thay vì bộ nhớ RAM, nhằm tăng tốc độ truy xuất.
- Ví dụ:
  - Tính thời gian chạy khi sử dụng `register`.
```C
#include <stdio.h>
#include <time.h>

int main()
{

  clock_t start_time = clock();  // Lưu lại thời gian bắt đầu
  int i;
  register int a = 5;
  register int b = 6;
  a = a ^ b;

  for(int i = 0; i < 2000000; ++i)
  {
    // Thực hiện hàm for
  }
  clock_t end_time = clock();  // Lưu lại thời gian kết thúc
  double time_take = ((double)(end_time - start_time))/CLOCKS_PER_SEC;  // Số thời gian cần để chạy đoạn mã trên
  printf("Time: %f giây\n", time_take);
  return 0;
}
```

>ℹ️ Không dùng toán tử `&` cho các biến `register` được vì biến lưu trữ trong thanh ghi thì không có địa chỉ.
>Không thể sử dụng từ khóa `register` cho các biến global: <br>1. Do biến được lưu trữ trên thanh ghi sẽ không có địa chỉ (do tính chất của biến global là tồn tại xuyên suốt chương trình nên phải có 1 địa chỉ cố định để có thể tham chiếu đến). <br>2. Thanh ghi có số lượng hạn chế mà biến toàn cục thì không.

### V. Type qualifier - Từ khóa định kiểu volatile:
- Trong quá trình biên dịch, Compiler thường cố gắng tối ưu hóa đầu ra để chỉ cần thực thi ít mã máy hơn, nếu mã máy đó không cần thiết khi truy cập biến cái mà không thay đổi gì xét theo quan điểm của Compiler.
- Ví dụ:
  - Tối ưu hóa vòng lặp while thành vô hạn vì bỏ qua kiểm tra biến check.
```c
int check = 1;
while (check)
{
  // Trình biên dịch có thẻ tối ưu hóa vòng lặp - sẽ không kiểm tra lại biến check trong vòng lặp tới do Compiler nghĩ là check không thay đổi.
}
```
- Từ khóa `volatile` được sử dụng để báo hiệu cho Compiler rằng 1 biến có thể thay đổi ngẫu nhiên ngoài sự kiểm soát của chương trình, nên `volatile` sẽ giúp ngăn Compiler tối ưu hóa hoặc xóa bỏ thao tác trên các biến đó, giữ cho các thao tác luôn được thực hiện như đã được định nghĩa.
- Ví dụ:
  - Không tối ưu hóa vòng lặp while thành vô hạn và luôn kiểm tra biến check.
```c
volatile int check = 1;
while (check)
{
  // Luôn kiểm tra biến check xem có bị thay đổi hay không.
}
```

[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 6: GOTO - SETJMP.H</b></summary>
 
### I. Câu lệnh goto trong C:
- Là một lệnh nhảy không điều kiện, cho phép chương trình nhảy đến 1 nhãn (label) trong cùng 1 hàm để thực thi tiếp.
- Cú pháp: 
 ```c
 goto label;
 label:
 ```
- Việc sử dụng goto là không được khuyến khích vì nó làm cho code trở nên khó đọc và khó bảo trì.
- Ví dụ:
 
```c
#include <stdio.h>

int main()
{
   int i = 0;

   start:
      if (i >= 5)
      {
         goto end;  // Nhảy đến label end khi i = 5
      }

      printf("%d ", i);
      i++;

      goto start;  // Nhảy đến label start khi i < 5

   end:
      printf("\n");
   return 0;
}
```

### II. Thư viện setjmp:
- Cung cấp 2 hàm chính là `setjump` và `longjmp`:
  - **setjmp(jmp_buf env)**: đánh dấu vị trí để quay lại bằng `longjump`.
    - Trả về `0` khi được gọi lần đầu.
    - Trả về khác `0` khi quay lại từ `longjmp`.
  - **longjmp(jmp_buf env, int value)**: nhảy về vị trí hiện tại của `setjump` và tiếp tục thực thi từ đó.
 - Ví dụ:
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;  // Biến buf kiểu jmp_buf để setjmp lưu trạng thái của chương trình.

int exception = 0;

void func2()
{
    printf("This is function 2\n");
    longjmp(buf, 2);  // Nhảy trở lại vị trí setjmp(buf) và giá trị trả về khi nhảy về setjmp() bởi longjmp(buf, 2) là 2 --> setjmp(buf) = 2.
}

void func3()
{
    printf("This is function 3\n");
    longjmp(buf, 3);  // Nhảy trở lại vị trí setjmp(buf) và giá trị trả về khi nhảy về setjmp() bởi longjmp(buf, 3) là 3 --> setjmp(buf) = 3.
}

void func1()
{
    exception = setjmp(buf);  // Khi gọi trực tiếp thì giá trị trả về là 0 (setjmp(buf) = 0).
    if (exception == 0)
    {
        printf("This is function 1\n");
        printf("exception = %d\n", exception);
        func2();  // Gọi hàm 2
    }
    else if (exception == 2)  // setjmp(buf) = 2 thực thi tiếp
    {
        printf("exception = %d\n", exception);
        func3();  // Gọi hàm 3
    }
    else if (exception == 3)  // setjmp(buf) = 3 thực thi tiếp
    {
        printf("exception = %d\n", exception);
    }
}

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}
```
- Ứng dụng xử lý lỗi của setjmp:
  - Exception Handling: Xử lý ngoại lệ là một cơ chế trong lập trình giúp phát hiện và xử lý các lỗi bất thường xảy ra trong quá trình thực thi, giúp chương trình hoạt động ổn định và không bị dừng đột ngột.
  - Những ngoại lệ gồm:
       - Chia cho 0.
       - Truy cập chỉ số của mảng mà nằm ngoài phạm vi.
       - Truy xuất con trỏ NULL.
       - Lỗi mở tập tin.
       - Lỗi cấp phát bộ nhớ.
  - C++, Java, Python, C# đều hỗ trợ xử lý ngoại lệ qua các từ khóa chính như:
       - **try**: định nghĩa một khối lệnh có thể phát sinh lỗi.
       - **catch**: xử lý ngoại lệ nếu có lỗi xảy ra.
       - **throw**: ném ra một ngoại lệ khi xảy ra lỗi.
  - Trong C chúng ta phải tự định nghĩa những từ khóa trên thông qua thư viện `setjmp`.
       - Cú pháp:

 ```c
        try
        {
          // Khối lệnh có thể có lỗi phát sinh.
        }
        catch (loại lỗi 1)
        {
          // Xử lý lỗi loại 1
        }
        catch (loại lỗi 2)
        {
          // Xử lý lỗi loại 2
        }
        catch (...)
        {
          // Xử lý tất cả các ngoại lệ khác
        }
```
  - Ví dụ:
    - Phát hiện lỗi khi chia cho 0.
```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception = 0;

/* Hàm chia 2 số nguyên */
double divide(int a, int b)
{
  if (a == 0 && b == 0)
  {
    longjmp(buf, 1);  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 1
  }
  else if (b == 0)
  {
    longjmp(buf, 2);  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 2
  }
  return (double)a/b;
}

int main()
{
  exception = setjmp(buf);
  if (exception == 0)
  {
    printf("Kết quả: %d\n", divide(2,3));  // Lần gọi trực tiếp setjmp đầu tiên luôn có kq là 0 trả về
  }
  else if (exception == 1)
  {
    printf("No exist");  // Nếu kq trả về là 1 thì hiện câu lệnh.
  }
  else if (exception == 2)
  {
    printf("Lỗi chia cho 0");  // Nếu kq trả về là 2 thì hiện câu lệnh.
  }
  return 0;
}
```
- Định nghĩa **try, catch, throw** trong C:
  - Thay vì phải sử dụng trực tiếp setjmp hay longjmp ta sẽ define chúng.
```c
#include <stdio.h>
#include <setjmp.h>

#define TRY if (exception == setjmp(buf) == 0)
#define CATCH(x) else if (exception == x)
#define THROW(x) longjmp(buf, x)

jmp_buf buf;

int exception = 0;

typedef enum
{
  NO_ERROR,
  NO_EXIST,
  DIVIDE_BY_0
}ErrorCodes;

/* Hàm chia 2 số nguyên */
double divide(int a, int b)
{
  if (a == 0 && b == 0)
  {
   THROW(NO_EXIST);  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 1
  }
  else if (b == 0)
  {
    THROW(DIVIDE_BY_0);  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 2
  }
  return (double)a/b;
}

int main()
{
  exception = NO_ERROR;
  TRY
  {
    printf("Kết quả: %d\n", divide(2,3));  // Lần gọi trực tiếp setjmp đầu tiên luôn có kq là 0 trả về
  }
  CATCH(NO_EXIST)
  {
    printf("No exist");  // Nếu kq trả về là 1 thì hiện câu lệnh.
  }
  CATCH(DIVIDE_BY_0)
  {
    printf("Lỗi chia cho 0");  // Nếu kq trả về là 2 thì hiện câu lệnh.
  }
  return 0;
}

```
[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 7: STRUCT - UNION</b></summary>

### I. Struct:
- Khái niệm:
  - Là 1 kiểu dữ liệu do người dùng tự định nghĩa. Struct được sử dụng khi muốn lưu trữ một tập hợp các kiểu dữ liệu khác nhau dưới một tên duy nhất.	
- Declaration - Cú pháp khai báo:
>✍️ Cú pháp 1:
```C
struct struct_name
{
  <datatype_1> <member1>;
  <datatype_2> <member2>; 
};
/* Ví dụ */
struct User
{
  char name;
  int age;
  float height;
};

struct User user1, user2;  // khi khai báo biến cần struct.
```
>✍️ Cú pháp 2:
```C
typedef struct
{
  <datatype_1> <member1>;
  <datatype_2> <member2>; 
}struct_name;
/* Ví dụ */
typedef struct
{
  char name;
  int age;
  float height;
}User;

User user1, user2, *user3;  // khi khai báo biến không cần thêm struct.
```
- Initialization - Khởi tạo:
>✍️ 1. Các thành viên của struct không được khởi tạo khi khai báo struct.
>  - `struct struct_name{ <datatype_1> <member1> = value1; }`: gây ra lỗi Compiler error bởi vì khi một kiểu dữ liệu được khai báo thì không có bộ nhớ nào được phân bổ cho nó , vì vậy không có không gian để lưu trữ giá trị được gán (bộ nhớ chỉ được phân bổ khi biến được tạo).<br>

>✍️ 2. Theo mặc định,
>- Nếu biến được khai báo cục bộ trong hàm thì các thành viên chưa được khởi tạo chứa giá trị rác, nhưng khi thành viên đầu tiên được khởi tạo thì những thành viên còn lại chưa được khởi tạo rõ ràng sẽ được khởi tạo bằng 0.
>- Nếu biến là global hoặc static thì các thành viên sẽ tự động gán = 0 hoặc NULLL.

>✍️ 3. Khởi tạo khi khai báo biến kiểu struct.<br>
```c
struct struct_name str = {"abc", val1, val2, ...};  // Các giá trị sẽ được gán theo thứ tự.
```
>✍️ 4. Khởi tạo chỉ 1 số thành viên.	1. 
```c
struct struct_name str = {.member1 = "abc",.member2 = val1};  // Các thành viên còn lại sẽ có giá trị 0 hoặc NULL
```
- Acess member - Cách truy cập thành viên của struct:
>✍️ 1. (.) dot operator: Toán tử dấu chấm giúp ta truy cập hoặc sửa đổi các thành viên của cấu trúc.<br>
➡️
 `struct_name.member1;`
 `struct_name.member2;`
 
>✍️ 2. (->) arrow operator: Toán tử mũi tên được sử dụng để truy cập thành viên khi có con trỏ trỏ đến cấu trúc.<br>
➡️
`struct_ptr->member1;`
`struct_ptr->member2;`

>👉 Ví dụ:
```c
typedef struct
{
  char *name;
  int age;
  char *addr
}User;

User user1, user2, *user3;  // user1,2 là biến thường và user 3 là biến con trỏ

int main()
{
  user1.name = "N";
  user2.age = 30;  // Biến thường sẽ dùng dấu chấm để truy cập các thành viên
  user3->name = "K";  // Đối với biến là con trỏ thì dùng mũi tên để truy cập các biến thành viên
}
```
- Data Structure Alignment:
  - Là cách dữ liệu sắp xếp và truy cập trong bộ nhớ máy tính. Nó gồm 3 phần riêng biệt nhưng có liên quan:
    - Data alignment: Căn chỉnh dữ liệu.
    - Data structure padding: Đệm cấu trúc dữ liệu.
    - Packing: Đóng gói.
  - Data alignment:
    - Để đọc một data có `n` byte, data đó nên đặt ở address là bội số của `n`.
  - Data structure padding:
    - Khi alignment, Compiler cần phải đệm thêm 1 số byte để đảm bảo mỗi trường bắt đầu ở đúng địa chỉ của nó. 
  - Packing:
    - Yêu cầu Compier không chèn thêm các byte đệm.
  - Cấp phát địa chỉ:
    - Compiler dựa trên kích thước member lớn nhất để cấp phát địa chỉ mỗi lần khởi tạo biến.
  - Boundary - Ranh giới:
    - Ranh giới `n` byte là địa chỉ bộ nhớ mà chia hết cho `n`.
    - Đối với kiểu `int` - ranh giới 4 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 4, 8, 12, ... `.
    - Đối với kiểu `char` - ranh giới 1 byte: đặt tại địa chỉ có kết thúc bằng `0, 1, 2, 3, 4, ... `.
    - Đối với kiểu `short` - ranh giới 2 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 2, 4, 6, 8, ... `.
    - Đối với kiểu `double` - ranh giới 8 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 8, 16, 24, ... `.
- Size of struct - Kích thước:
  - Mỗi thành viên có một vùng nhớ riêng.
  - Có thể lưu nhiều dữ liệu đồng thời.
  - Lấy kiểu dữ liệu lớn nhất trong số các thành viên làm chuẩn để cấp phát bộ nhớ.
  - Tổng kích thước bằng tổng kích thước của các thành viên + padding.
>👉 Ví dụ: Tìm kích thước của struct và in ra từng byte với địa chỉ tương ứng.
```c
#include <stdio.h>

typedef struct Data
{
    char data1;
    int data2;
    char data3;
    short data4;
}DataSet;

int main()
{
    /* Khởi tạo các thành viên của struct */
    DataSet data;
    data.data1 = 'A';
    data.data2 = 0xFFFFEEEE;
    data.data3 = 0x22;
    data.data4 = 0xABCD;
    
    /* In ra từng byte với từng địa chỉ tương ứng */
    unsigned char *ptr;
    ptr = (unsigned char*)&data;
    int totalsize = sizeof(DataSet);
    printf("Total size of struct: %d\n", totalsize);
    for (int i = 0; i < totalsize; i++)
    {
        printf(" %p,  %x\n", ptr, *ptr);
        ptr++;
    }
    return 0;
}
```
>➡️ Tổng là 12 byte (là bội số của 4):

![Image](https://github.com/user-attachments/assets/9bbd7654-4522-45cb-ba48-f8d6533e65e7)

> - Trong cấu trúc này, `int` có kích thước lớn nhất nên Compiler lấy 4 byte làm chuẩn để cấp phát 4 byte địa chỉ.
> - `char` - thành viên đầu tiên, địa chỉ bắt đầu là: `00000000005FFE84` là bội số của 1, 3 byte tiếp theo là padding: `85, 86, 87` vì không những địa chỉ này không phải là bội số của 4.
> - `int` - thành viên thứ 2, địa chỉ bắt đầu là: `00000000005FFE88` là bội số của 4, 4 byte này nằm trong boundary từ `88 -> 8B`.
> - `char` - thành viên thứ 3, địa chỉ bắt đầu là: `00000000005FFE8C` là bội số của 1, 1 byte tiếp theo là padding: `8D`.
> - `short` - thành viên thứ 4, địa chỉ bắt đầu là: `00000000005FFE8E` là bội số của 2, 2 byte này nằm trong boundary `8E, 8F`.

<br>

![Image](https://github.com/user-attachments/assets/5c57ccd9-24a5-433b-8c58-5f4bd6d96fef)

<br>

> - Tóm lại ta có 8 byte thực tế và 4 byte padding.
> 
>ℹ️ Nếu thêm một thành viên thứ 5 kiểu `char` thì tổng số byte sẽ là 16 (bội số của 4), vì 3 byte padding sẽ được thêm vào những địa chỉ cuối.

>👉 Ví dụ: Tìm kích thước của struct có thành viên là mảng.
```c
#include <stdio.h>
#include <string.h>

typedef struct Array
{
    char arr1[5];
    short arr2[4];
    int arr3[2];
}ArraySet;

int main()
{
    /* data */
    ArraySet arrayS;

    /* Member 1 */
    // Dùng strcpy để sao chép từng ký tự vào mảng arr1
    strcpy(arrayS.arr1,"Hello");  // Đối số 1 được truyền vào là con trỏ `char *` hoặc mảng kiểu `char arr[]`

    /* Member 2 */
    // Để gán giá trị cho chuỗi kiểu số nguyên thì phải gán từng thành viên một
    arrayS.arr2[0] = 0xabcd;
    arrayS.arr2[1] = 0xcdef;
    arrayS.arr2[2] = 0x1234;
    arrayS.arr2[3] = 0x4567;

    /* Member 3 */
    // Để gán giá trị cho chuỗi kiểu số nguyên thì phải gán từng thành viên một
    arrayS.arr3[0] = 0xAAAAFFFF;
    arrayS.arr3[1] = 0xBBBBEEEE;

    /* Pointer */
    unsigned char *ptr;
    ptr = (unsigned char*)&arrayS;

    int totalsize = (int)sizeof(ArraySet);
    printf("Total size of struct: %d\n", totalsize);
    for (int i = 0; i < totalsize; i++)
    {
        printf(" %p,  %x\n", ptr, *ptr);
        ptr++;
    }
    return 0;
}
```
>➡️ Tổng là 24 byte (là bội số của 4):
> - Trong cấu trúc này, `int` có kích thước lớn nhất nên Compiler lấy 4 byte làm chuẩn để cấp phát 4 byte địa chỉ.
> - Thành viên đầu có 5 phần tử `char arr1[5]` có 5 byte thực + 1 byte padding: bắt đầu từ địa chỉ `00000000005FFE70` -> `00000000005FFE75` lần lượt là giá trị của các ký tự trong chuỗi "Hello", cuối cùng là byte padding = `0`.
> - Thành viên thứ 2 có 4 phần tử kiểu short_kích thước 2 byte  `short arr2[4]` có 8 byte thực và 2 byte padding: bắt đầu từ địa chỉ `00000000005FFE76` với `76` là bội số của 2 -> `00000000005FFE7F` lần lượt là địa chỉ của các giá trị đã được gán, 2 byte padding ở cuối = `0`.
> - Thành viên thứ 3 có 2 phần tử kiểu int_kích thước 4 byte  `int arr3[2]` có 8 byte: bắt đầu từ địa chỉ `00000000005FFE80` với `80` là bội số của 4 -> `00000000005FFE87` lần lượt là địa chỉ của các giá trị đã được gán.
![Image](https://github.com/user-attachments/assets/27757309-d213-4651-ba0c-631d2b2468bb)

### II. Bit Field:
- Trong C, ta có thể chỉ định kích thước theo bit của thành viên trong 1 struct hay union.
- Cú pháp:
```c
struct
{
  data_type member : width_of_bit_field;
}
/* Ví dụ */
struct
{
  int data1 : 2;  // chỉ sử dụng 2 bit trong tổng số 4 byte
  char data2 : 4;  // chỉ sử dụng 4 bit trong tổng số 1 byte
}
```
### III. UNION:
- Khái niệm:
  - Là 1 kiểu dữ liệu do người dùng tự định nghĩa, có thể chứa các phần tử có kiểu dữ liệu khác nhau như struct.
  - Nhưng không giống cấu trúc, tất cả các thành viên của `union` được lưu trữ trong cùng một vị trí bộ nhớ, vì vậy mà chỉ có 1 thành viên mới có thể lưu trữ dữ liệu tại 1 thời điểm.
- Declaration - Cú pháp khai báo:
>✍️ Cú pháp 1:
```C
union union_name
{
  <datatype_1> <member1>;
  <datatype_2> <member2>; 
};
/* Ví dụ 1 */
union Point
{
  char x;
  int y;
  float f;
};

union Point p1, p2;  // khi khai báo biến cần thêm union.
```
>✍️ Cú pháp 2:
```C
typedef union
{
  <datatype_1> <member1>;
  <datatype_2> <member2>; 
}union_name;
/* Ví dụ */
typedef struct
{
  char x;
  int y;
  float f;
}Point;

Point p1, p2;  // khi khai báo biến không cần thêm union.
```
- Initialization - Khởi tạo:
>✍️ 1. Các thành viên của struct không được khởi tạo khi khai báo struct.
>  - `struct struct_name{ <datatype_1> <member1> = value1; }`: gây ra lỗi Compiler error bởi vì khi một kiểu dữ liệu được khai báo thì không có bộ nhớ nào được phân bổ cho nó , vì vậy không có không gian để lưu trữ giá trị được gán (bộ nhớ chỉ được phân bổ khi biến được tạo).<br>

>✍️ 2. Theo mặc định,
>- Nếu biến được khai báo cục bộ trong hàm thì các thành viên chưa được khởi tạo chứa giá trị rác, nhưng khi thành viên đầu tiên được khởi tạo thì những thành viên còn lại chưa được khởi tạo rõ ràng sẽ được khởi tạo bằng 0.
>- Nếu biến là global hoặc static thì các thành viên sẽ tự động gán = 0 hoặc NULLL.

- Acess member - Cách truy cập thành viên của struct:
>✍️ 1. (.) dot operator: Toán tử dấu chấm giúp ta truy cập hoặc sửa đổi các thành viên của `union`.<br>
➡️
 `union_name.member1;`
 `union_name.member2;`
 
>✍️ 2. (->) arrow operator: Toán tử mũi tên được sử dụng để truy cập thành viên khi có con trỏ trỏ đến `union`.<br>
➡️
`union_ptr->member1;`
`union_ptr->member2;`
- Size of union - Kích thước:
  - Trong union, tất cả các thành viên cùng chia sẻ một vùng nhớ.
  - Kích thước của union sẽ bằng với kích thước của thành viên lớn nhất.
  - Chỉ một thành viên lưu trữ giá trị tại một thời điểm nếu không dữ liệu sẽ bị ghi đè.
>👉 Ví dụ: So sánh kích thước của union với struct.
```c
#include <stdio.h>

/* Định nghĩa kiểu union */
typedef union Data
{
    char data1;
    int data2;
    char data3;
    short data4;
    char data5;
}DataUnion;

/* Định nghĩa kiểu struct */
typedef struct Data1
{
    char data1;
    int data2;
    char data3;
    short data4;
    char data5;
}DataStruct;

int main()
{
    /* Union */
    DataUnion data_union;
    data_union.data1 = 'A';
    data_union.data2 = 0xFFFFEEEE;
    data_union.data3 = 0x22;
    data_union.data4 = 0xABCD;
    data_union.data5 = 0x12;

    /* Struct */
    DataStruct data_struct;
    data_struct.data1 = 'A';
    data_struct.data2 = 0xFFFFEEEE;
    data_struct.data3 = 0x22;
    data_struct.data4 = 0xABCD;
    data_struct.data5 = 0x12;
    
    /* Pointer to union */
    unsigned char *ptr_union;
    ptr_union = (unsigned char*)&data_union;

     /* Pointer to struct */
     unsigned char *ptr_struct;
     ptr_struct = (unsigned char*)&data_struct;

     /* Union: Print address and value by byte */
    int union_size = sizeof(data_union);
    printf("Total size of union: %d\n", union_size);
    for (int i = 0; i < union_size; i++)
    {
        printf(" %p,  %x\n", ptr_union, *ptr_union);
        ptr_union++;
    }

    /* Struct: Print address and value by byte */
    int struct_size = sizeof(data_struct);
    printf("Total size of struct: %d\n", struct_size);
    for (int i = 0; i < struct_size; i++)
    {
        printf(" %p,  %x\n", ptr_struct, *ptr_struct);
        ptr_struct++;
    }
    return 0;
}
```
>➡️ Kết quả:
![Image](https://github.com/user-attachments/assets/de162709-3e48-4f89-abb9-6af26607a557)

>👉 Ví dụ: Sự khác nhau giữa đọc giá trị của các thành viên riêng lẻ và cùng lúc.
```c
#include <stdio.h>

typedef union Data
{
    char data1;
    char data2;
    char data3;
    int data4;
}DataUnion;

int main()
{
    DataUnion data_union;

    printf("/****** Đọc riêng từng thành viên data1 & data2 ******/\n");
    data_union.data1 = 34;
    printf("Data 1: %d\n", data_union.data1);
    data_union.data2 = 64;
    printf("Data 2: %d\n", data_union.data2);

    printf("/****** Đọc cùng lúc 2 thành viên data2 & data3 ******/\n");
    data_union.data2 = 64;
    data_union.data3 = 10;
    printf("Data 2: %d\n", data_union.data2);
    printf("Data 3: %d\n", data_union.data3);
    
    unsigned char *ptr;
    ptr = (unsigned char*)&data_union;
    int total_size = sizeof(data_union);
    printf("/****** Giá trị của từng byte ******/\n");
    for(int i = 0; i < sizeof(total_size); i++)
    {
        printf("Address: %p - 1 byte value: %d\n", ptr, *ptr);
        ptr++;
    }
    return 0;
}
```
>➡️ Kết quả:
>- Lý do phải gán và đọc thành viên riêng một thời điểm là do union chỉ lưu trữ giá trị trong 4 byte địa chỉ chung nên khi gán một địa chỉ cho 1 thành viên thì giá trị đó sẽ bị ghi đè lên giá trị của thành viên trước đó.
>
>![Image](https://github.com/user-attachments/assets/96e8e621-33c1-42fb-90d6-16971d344f08)

### IV. Kết hợp STRUCT và UNION:

>👉 Ví dụ: Kết hợp `struct` với `union`.
> - Để struct làm thành viên của union, để tiết kiệm (không để có byte padding) ta sẽ chỉ cần dùng `uint8_t` - 1 byte cho tất cả các thành viên của struct.

```c
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union
{
    struct
    {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;
    uint8_t frame[8];
}Data_Frame;

int main(int argc, char const *argv[])
{
    // Copy dữ liệu vào các thành viên của struct
    Data_Frame transmit_data;
    strcpy((char*)transmit_data.data.id, "10");
    strcpy((char*)transmit_data.data.data, "1234");
    strcpy((char*)transmit_data.data.check_sum, "70");

    // Copy dữ liệu của biến transmit_data vào receive_data
    Data_Frame receive_data;
    strcpy((char*)receive_data.frame, (char*)transmit_data.frame);
    return 0;

    /* In ra địa chỉ và dữ liệu của từng byte */
    // Pointer trỏ tới biến receive_data
    unsigned char *ptr;
    ptr = (unsigned char*)&receive_data;
    int total_size = sizeof(receive_data);
    // In địa chỉ và dữ liệu
    printf("/****** Giá trị của từng byte ******/\n");
    for(int i = 0; i < total_size; i++)
    {
        printf("Address: %p - 1 byte value: %c\n", ptr, *ptr);
        ptr++;
    }
    return 0;
}
```
>➡️ Kết quả:
>
![Image](https://github.com/user-attachments/assets/f340caf1-f886-4ce6-af17-7efa0c8263f4)

### V. So sánh `STRUCT` và `UNION`:

![Image](https://github.com/user-attachments/assets/b8444418-1695-4ada-9b0a-cce6271a06be)


[🔼 _UP_](#top)
</details>


<details>
<summary>🔖 <b>BÀI 8: MEMORY LAYOUT</b></summary>

<br>

- Đối với chương trình `main.exe` (trên window) được lưu vào bộ nhớ SSD, nhấn nút run chương trình trên window thì `main.exe` được copy vào bộ nhớ RAM để thực thi.
- Đối với `main.hex` (nạp vào vi điều khiển) thì được lưu vào bộ nhớ FLASH, và khi cấp nguồn cho vi điều khiển thì `main.hex` được copy vào RAM để thực thi.
- Có 5 vùng nhớ trong RAM:
  - Text segment (Code segment).
  - Data segment (Initialized data).
  - BSS segment (Uninitialized data).
  - Stack.
  - Heap.

### I. Text segment (Code segment):

|📋 Text segment|📄 Description|
|:------------------------:|:------------------------|
|**Chứa**| - Chứa mã thực thi của chương trình - mã máy đã được biên dịch.<br> - Đối với trình biên dịch Clang (macOS), còn lưu trữ biến hằng số toàn cục `const` và chuỗi hằng `char *ptr = "Hello"; // Hello là chuỗi hằng` nhưng với quyền là read-only.|
|**Quyền truy cập**|Chỉ read-only, không có quyền write - thay đổi giá trị, địa chỉ là không được phép.|

### II. Data segment (Initialized data):

|📋 Data segment|📄 Description|
|:------------------------:|:------------------------|
|**Chứa**| - Chứa biến global được khởi tạo với giá trị khác 0.<br> - Chứa biến static (global + local) được khởi tạo với giá trị khác 0.<br> - Đối với trình biên dịch GCC/G++ (Windows), còn lưu trữ biến hằng số toàn cục `const` và chuỗi hằng `char *ptr = "Hello"; // Hello là chuỗi hằng` nhưng với quyền là read-only.|
|**Quyền truy cập**|Quyền read-write, được phép đọc và thay đổi giá trị của biến.|
|**Life time**|Các biến trên sẽ bị thu hồi khi chương trình kết thúc - những địa chỉ cấp phát ra sẽ bị thu hồi.|

### III. BSS segment (Uninitialized data):

|📋 BSS segment|📄 Description|
|:------------------------:|:------------------------|
|**Chứa**| - Chứa biến global và biến static (global + local) được khởi tạo với giá trị = 0 hoặc không gán giá trị.|
|**Quyền truy cập**|Quyền read-write, được phép đọc và thay đổi giá trị của biến.|
|**Life time**|Các biến trên sẽ bị thu hồi khi chương trình kết thúc - những địa chỉ cấp phát ra sẽ bị thu hồi.|

>👉 Ví dụ: Các biến thường và biến struct lưu trữ trong memory.
```c
#include <stdio.h>

typedef struct
{
   int x;
   int y;
} Point_Data;

/* Khởi tạo biến struct (global) */
static Point_Data p1 = {0,0};   // p1: nằm ở bss -> x,y cũng nằm ở bss
Point_Data p2;                  // p2: chưa khởi tạo, nằm ở bss -> x,y nằm ở bss
Point_Data p3 = {0, 1};         // p3: khởi tạo khác 0, nằm ở data -> x,y nằm ở data

/* Khởi tạo biến thường (global) */
int zero_val_global = 0;     // nằm ở bss
int unitialized_var_global;  // nằm ở bss
int val_global = 10;         // nằm ở data

void check_memory()
{
    /* Khởi tạo biến struct trong hàm (local) */
    static Point_Data p4 = {0,1};   // p4: nằm ở data -> x,y cũng nằm ở data
    Point_Data p5;                  // p5: nằm ở stack -> x,y cũng nằm ở stack
    Point_Data p6 = {0, 1};         // p6: nằm ở stack -> x,y cũng nằm ở stack

    /* Khởi tạo biến thường (local) */
    int zero_val_local = 0;     // nằm ở stack
    int unitialized_var_local;  // nằm ở stack
    int val_local = 20;         // nằm ở stack

    /* In địa chỉ của biến struct  */
    printf("Static global struct (value = 0): Bss   %p\n", (void*)&p1);
    printf("Global uninitialized struct:      Bss   %p\n", (void*)&p2);
    printf("Global struct (value = !0):       data  %p\n", (void*)&p3);
    printf("Static local struct (value = !0): data  %p\n", (void*)&p4);
    printf("Local uninitialized struct:       Stack %p\n", (void*)&p5);
    printf("Local struct (value = !0):        Stack %p\n", (void*)&p6);

    /* In địa chỉ của biến struct  */
    printf("\nGlobal var (value = 0):   Bss   %p\n", (void*)&zero_val_global);
    printf("Global uninitialized var: Bss   %p\n", (void*)&unitialized_var_global);
    printf("Global var (value = !0):  data  %p\n", (void*)&val_global);
    printf("Local var (value = 0):    Stack %p\n", (void*)&zero_val_local);
    printf("Local uninitialized var:  Stack %p\n", (void*)&unitialized_var_local);
    printf("Local var (value = !0):   Stack %p\n", (void*)&val_local);
}

int main()
{
    check_memory();
    return 0;
}
```
>➡️ Kết quả:
>
>![Image](https://github.com/user-attachments/assets/937241d9-498f-44cb-8b68-3ac29e142c4e)

### IV. Stack:

|📋 Stack|📄 Description|
|:------------------------:|:------------------------|
|**Chứa**| - Chứa biến cục bộ (trừ static), tham số truyền vào hàm, mảng, hằng số cục bộ (thay đổi được thông qua con trỏ).|
|**Quyền truy cập**|Quyền read-write, được phép đọc và thay đổi giá trị của biến.|
|**Life time**|Sau khi ra khỏi hàm, tự động thu hồi vùng nhớ.|

>👉 Ví dụ: Cách mảng được lưu trữ trong vùng nhớ.
```c
#include <stdio.h>
#include <stdlib.h>

char global_arr[] = "Hello";    // nằm ở data segment
char *global_literal = "Hello"; // nằm ở data segment (rodata)

void check_memory()
{
    static char static_arr[] = "Hello";  // nằm ở data segment
    char local_arr[] = "Hello";          // nằm ở stack
    char *local_literal = "Hello";       // nằm ở data segment (rodata)
    char *heap_arr = (char*)malloc(sizeof(char)*10);  // nằm ở heap segment
    
    printf("Global arr:     %p\n",(void*)global_arr);
    printf("Global literal: %p\n",(void*)global_literal);

    printf("Static arr:     %p\n",(void*)static_arr);

    printf("Local arr:      %p\n",(void*)local_arr);
    printf("Local literal:  %p\n",(void*)local_literal);

    printf("Heap arr:       %p\n",(void*)heap_arr);

    /* Có thể thay dổi giá trị mảng cục bộ trong stack */
    printf("Trc thay đổi: %s\n", local_arr);
    strcpy(local_arr,"Local") ;
    printf("Thay đổi: %s\n", local_arr);

    free(heap_arr);
}

int main()
{
    check_memory();

    /* Có thể thay đổi giá trị của phần tử mảng toàn cục */
    global_arr[0] = 'A';
    printf("%s", global_arr);

    return 0;
}
```
>➡️ Kết quả:
>
>![Image](https://github.com/user-attachments/assets/3574fd7e-a74f-42aa-a11d-0135fd851b81)

### V. Heap:

|📋 Heap|📄 Description|
|:------------------------:|:------------------------|
|**Cách dùng**|- Để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.<br>- Cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu.<br>- Các hàm `malloc()`, `calloc()`, `realloc()` được sử dụng để cấp phát và `free()` để giải phóng bộ nhớ trên heap.|
|**malloc()**|Cấp phát bộ nhớ với kích thước chỉ định trước.|
|**realloc()**|Thay đổi kích thước vùng nhớ đã được cấp phát ra thông qua malloc hoặc calloc.|
|**calloc()**|Cấp phát bộ nhớ với kích thước chỉ định trước và khởi tạo bộ nhớ được phân bổ về 0.|
|**Quyền truy cập**|Quyền read-write.|
|**Life time**|- Phải thu hồi thủ công, không tự động thu hồi khi kết thúc hàm như stack.<br>- Sau khi kết thúc chương trình, tự động thu hồi vùng nhớ.|

>👉 Ví dụ: Dùng malloc(), calloc(), realloc().
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    // ***************** Cấp phát tĩnh *****************
    uint16_t arr[5];    // 5 phần tử * 2 bytes kích thước = 10 bytes.

    // ***************** Cấp phát động *****************
    // *** malloc: cấp phát bộ nhớ động mà không khởi tạo (chứa giá trị rác) ***
    int size = 5;
    printf("Stack address: %p - Value: %d\n", (void*)&size, size);
    // Để dùng malloc: 
    // - Xác định kích thước dựa trên 2 thành phần.
    // - Ép kiểu malloc vì malloc là con trỏ kiểu void (không truy xuất được) cùng kiểu với từng phần tử để có thể đọc đúng.
    // - Khai báo con trỏ để truy xuất được dữ liệu trong vùng nhớ đã cấp phát.
    uint16_t *ptr = (uint16_t*)malloc(size * sizeof(uint16_t));    // cấp phát địa chỉ bộ nhớ trong Heap
    printf("\nPtr_malloc address_stack: %p - Value_heap: %X\n\n", &ptr, ptr);

    // Kiểm tra liệu malloc có cấp phát chuẩn không
    if (ptr == NULL)
    {
        printf("Cấp phát bị lỗi\n");
        return 1;
    }
    // Khởi tạo giá trị cho các thành phần
    for (int i = 0; i < size; i++)
    {
        ptr[i] = 2*i;
    }
    // In ra địa chỉ và giá trị con trỏ trỏ tới
    for (int i = 0; i < size; i++)
    {
        printf("Heap Address: %p - Value: %d\n", ptr + i, *(ptr + i));
    }

    // *** calloc: cấp phát bộ nhớ động khởi tạo toàn bộ = 0. ***
    int size_calloc = 5;
    uint16_t *ptr_calloc = (uint16_t*)calloc(size_calloc, sizeof(uint16_t));
    printf("\nPtr_calloc address_stack: %p - Value_heap: %X\n\n", &ptr_calloc, ptr_calloc);

    // Kiểm tra liệu malloc có cấp phát chuẩn không
    if (ptr_calloc == NULL)
    {
        printf("Cấp phát bị lỗi\n");
        return 1;
    }

    // In ra địa chỉ và giá trị con trỏ trỏ tới
    for (int i = 0; i < size; i++)
    {
        printf("Heap Address: %p - Value: %d\n", ptr_calloc + i, *(ptr_calloc + i));
    }

    // ***************** Phân bổ lại cấp phát động *****************
    int new_size = 10;
    // Để dùng realloc: 
    // - Truyền vào vùng nhớ đã cấp phát và kích thước mới.
    // - Ép kiểu realloc để đồng bộ dữ liệu.
    // - Thay đổi con trỏ để trỏ tới realloc.

    uint16_t *ptr_realloc = (uint16_t*)realloc(ptr, new_size * sizeof(uint16_t));

    printf("\nPtr_realloc address_stack: %p - Value_heap: %X\n\n", &ptr_realloc, ptr_realloc);

    // Kiểm tra xem phân bổ lại có lỗi hay không
    if (ptr_realloc == NULL)
    {
        printf("Cấp phát bị lỗi\n");
        return 1;
    }

    ptr = ptr_realloc;

    // Khởi tạo giá trị cho các thành phần
    for (int i = 0; i < new_size; i++)
    {
        ptr[i] = 2*i;
    }

    // In ra địa chỉ và giá trị con trỏ trỏ tới
    for (int i = 0; i < new_size; i++)
    {
        printf("Add new Heap Address: %p - Value: %d\n", ptr + i, *(ptr + i));
    }

    // ***************** Thu hồi vùng nhớ đã cấp phát *****************
    //  Memory leak:
    // - Không thu hồi bộ nhớ đã phân bổ thì bộ nhớ vẫn chiếm RAM nhưng không còn biến nào trỏ tới nó dẫn đến không truy cập lại được gây lãng phí tài nguyên.
    // - Khi cấp phát tiếp thì sẽ bị cộng dồn mức sử dụng RAM lên dễ dẫn đến treo chương trình, thoát đột ngột hoặc làm chậm dần hệ thống.
    // Overflow: Nếu ghi dữ liệu vượt quá kích thước mảng hoặc vùng nhớ được cấp phát.
    free(ptr);  
    free(ptr_calloc);

    // ***************** Gán ptr = NULL sau khi không còn sử dụng *****************
    ptr = NULL;    // tránh trỏ tới những vùng nhớ khác trong RAM gây lỗi không mong muốn
    ptr_calloc = NULL; 
    ptr_realloc = NULL;

    return 0;
}
```
>➡️ Kết quả:
>
>![Image](https://github.com/user-attachments/assets/08c31886-4458-40ff-af5a-7d5f3c55a635)

### VI. Memory leak & Overflow:

|📋 So sánh|📄 Memory leak|📄 Overflow|
|:------------------------:|:------------------------|:------------------------|
|**Khái niệm**|- Xảy ra khi phân bổ bộ nhớ động nhưng quên không giải phóng nó, và bộ nhớ được phân bổ này vẫn tồn tại trong suốt thời gian của chương trình và không thể sử dụng lại bộ nhớ đó.|- Ghi quá dung lượng cho phép của stack.<br>- Ghi dữ liệu vượt quá kích thước mảng hoặc vùng nhớ được cấp phát (heap).|
|**Nguyên nhân**|Quên không free(), mất con trỏ.|- Stack overflow: gọi đệ quy vô hạn, tạo biến quá lớn.<br>- Heap overflow: Ghi dữ liệu vượt quá  kích thước mảng hoặc vùng nhớ được cấp phát.|
|**Ảnh hưởng**|Lãng phí RAM, làm chương trình chậm hoặc treo.|Crash chương trình|

### VII. malloc vs. calloc vs. realloc:

|📋 So sánh|malloc|calloc|realloc|
|:------------------------:|:------------------------|:------------------------|:------------------------|
|**Khái niệm**|- Memory allocation: phân bổ bộ nhớ động.|- Contiguous allocation: phân bổ bộ nhớ động được khởi tạo về 0.|- Reallocation: phân bổ lại bộ nhớ trước đó.|
|**Cú pháp**|`malloc(số byte phân bố);`|`calloc(số phần tử, kích thước phần tử);`|`realloc(con trỏ trước đó, kích thước mới);`|
|**Giá trị ban đầu**|Rác|`0`|Rác|
|**Phân bổ không thành công**|Trả về NULL|Trả về NULL|Trả về NULL|

[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 9: STACK - QUEUE</b></summary>
 
### 📑 I. Cấu trúc dữ liệu:

- **Cấu trúc dữ liệu** là một kho lưu trữ được sử dụng để lưu trữ và sắp xếp dữ liệu. Đây là một cách sắp xếp dữ liệu trên máy tính để có thể truy cập và cập nhật hiệu quả.
- Không chỉ được sử dụng để tổ chức dữ liệu mà còn được sử dụng để xử lý, truy xuất và lưu dữ liệu.
- Đóng vai trò quan trọng trong việc giải quyết các bài toán và tối ưu hóa thuật toán, vì nó ảnh hưởng trực tiếp đến tốc độ thực thi và tính năng phức tạp của chương trình.

![Image](https://github.com/user-attachments/assets/9ce30e6b-bb55-437a-bd5c-5e8e3966353c)

- Cấu trúc dữ liệu phân àm 2 loại chính:
  - Cấu trúc dữ liệu tuyến tính (Linear data structure):
    - Static data structure - **array**: Cấu trúc dữ liệu tĩnh có kích thước bộ nhớ cố định, việc truy cập dễ dàng hơn.
    - Dynamic data structure - **queue, stack, linked list**: Cấu trúc dữ liệu động có kích thước không cố định, kích thước có thể được cập nhật trong thời gian chạy.
  - Cấu trúc dữ liệu phi tuyến tính ( Non - linear data structure) - **trees, graph**: Cấu trúc dữ liệu mà trong đó các phần tử dữ liệu không được đặt tuần tự hoặc tuyến tính, không thể duyệt qua tất cả các phần tử chỉ trong 1 lần chạy.

### 📑 II. Stack:
- Stack là một cấu trúc dữ liệu tuyến tính tuân theo:
  - LIFO (Last In First Out), phần tử cuối được lấy ra đầu tiên,
  - hay là FILO (First In Last Out), phần tử đầu được lấy ra cuối.
- Các thao tác cơ bản trên Stack:
  - **push()**: chèn thêm 1 phần tử vào stack.
  - **pop()**: xóa 1 phần tử khỏi stack.
  - **peek() / top()**: lấy giá trị phần tử trên cùng (top element) của stack.
  - **pop()**: xóa 1 phần tử khỏi stack.
  - **isEmpty()**: điều kiện kiểm tra stack rỗng: top == -1.
  - **isFull()**: điều kiện kiểm tra stack đầy: top == size-1.
>✍️ **push()**:
> - Trước khi thêm phần tử vào đỉnh của stack, phải kiểm tra xem stack đầy hay chưa:
>   - top == size - 1: stack đã đầy -> không thể thêm phần tử vào stack. 
> - Thêm phần tử vào đỉnh của stack -> top = top + 1.
> 
> ![Image](https://github.com/user-attachments/assets/18cc7e6c-20a1-452a-85a0-0bd4cc12b669)

>✍️ **pop()**:
> - Trước khi xóa phần tử ở đỉnh của stack, phải kiểm tra xem stack có trống hay không:
>   - top == - 1: stack trống -> không thể xóa phần tử ở stack. 
> - Xóa phần tử ở đỉnh của stack -> top = top - 1.
> 
> ![Image](https://github.com/user-attachments/assets/21477252-02ab-4067-83ae-d1c0b49776c2)

>✍️ **peek() / top()**:
> - Trong stack chỉ có 1 chỉ số duy nhất là top, dùng để đọc giá trị của phần tử ở đỉnh stack:
>   - top == - 1: giá trị khởi tạo ban đầu -> stack rỗng.
>   - push -> top++.
>   - pop -> top--.
>   - top = size - 1 -> stack full.

>👉 Ví dụ: Viết code cho cấu trúc dữ liệu stack.

<details>
<summary>stack.h</summary>
 
```c
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Khai báo cấu trúc dữ liệu ngăn xếp
typedef struct 
{
    int *item;      // Mảng lưu trữ giá trị các phần tử
    int size;       // Số lượng phần tử tối đa
    int top;        // Chỉ số đọc giá trị ở đỉnh stack
}Stack;

// Khởi tạo các thông số ban đầu
void stack_init(Stack *stack, int Size);

/* Kiểm tra stack rỗng: TRUE - stack rỗng, FALSE - stack không rỗng */
bool isEmpty(Stack stack);  // sao chép dữ liệu của stack, chỉ đọc - không cần con trỏ

/* Kiểm tra stack rỗng: TRUE - stack rỗng, FALSE - stack không rỗng */ 
bool isFull(Stack stack);

/* Chèn thêm phần tử vào stack */
void push(Stack *stack, int data);  // tác động vào giá trị gốc nên phải có con trỏ

/* Xóa phần tử ở đỉnh stack */
int pop(Stack *stack);

/* Đọc giá trị ở đỉnh stack */
int top(Stack stack);

/* Giải phóng bộ nhớ stack */
void stack_free(Stack *stack);

#endif  // STACK_H
```
</details>

<details>
<summary>stack.c</summary>
 
```c
#include "stack.h"

// Khởi tạo các thông số ban đầu
void stack_init(Stack *stack, int Size)
{
    stack->item = (int*)malloc(Size*sizeof(int));   // cấp phát động cho mảng item.
    stack->size = Size;     // gán số lượng phần tử
    stack->top = -1;        // khởi tạo giá trị ban đầu cho chỉ số top
}

bool isEmpty(Stack stack)
{
    return (stack.top == -1 ? true : false);    // Kiểm tra stack rỗng: top == -1
}

bool isFull(Stack stack)
{
    return (stack.top == (stack.size - 1) ? true : false);      // Kiểm tra stack đầy: top == size - 1
}

void push(Stack *stack, int data)
{
    if (isFull(*stack))
    {
        printf("Stack is Full\n");      // kiểm tra stack đầy
    }
    else
    {
        printf("Insert the %d element: %d\n", ++stack->top, data);  
        stack->item[stack->top] = data;     // gán thêm giá trị vào stack
    }
}

int pop(Stack *stack)
{
    if (isEmpty(*stack))
    {
        printf("Stack is Empty\n");      // kiểm tra stack rỗng
        return -1;
    }
    else 
    {
        int value = stack->item[stack->top];    // đọc giá trị phần tử trong stack
        printf("Delete the %d element: %d\n", stack->top--, stack->item[stack->top]);
        stack->item[stack->top] == 0;   // gán giá trị 0 vào phần tử cần xóa
        return value;   // trả về hàm giá trị value
    }
}

int top(Stack stack)
{
    if (isEmpty(stack))
    {
        printf("Stack rỗng");   // kiểm tra stack rỗng
        return -1;
    }
    else
    {
        return stack.item[stack.top];   // đọc phần tử trong stack
    }
}

void stack_free(Stack *stack)
{
    if (stack->item != NULL)    // kiểm tra mảng có = NULL không
    {
        free(stack->item);      // giải phóng bộ nhớ động cho mảng item
        stack->item = NULL;     // gán NULL cho con trỏ khi không dùng nữa
    }
}
```
</details>

<details>
<summary>main.c</summary>
 
>`main.c`
```c
#include "stack.h"

int main()
{
    Stack stack1;
    stack_init(&stack1, 5);

    push(&stack1, 1);
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack1, 4);
    push(&stack1, 5);
    push(&stack1, 6);

    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    
    return 0;
}
```
>➡️ Kết quả:
>
>![Image](https://github.com/user-attachments/assets/33edcaff-4bb1-4351-9097-000f4154f642)
</details>


### 📑 III. Queue - Hàng đợi:
- Hàng đợi Queue là một cấu trúc dữ liệu tuân theo nguyên tắc "First In - First Out" (FIFO), nghãi là các phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra.
- Các thao tác cơ bản:
  - **enqueue**: thêm phần tử vào CUỐI hàng đợi.
  - **dequeue**: xóa phần tử ở ĐẦU hàng đợi.
  - **front**: đọc giá trị của phần tử ĐẦU hàng đợi.
  - **rear**: đọc giá trị của phần tử CUỐI hàng đợi.
  - **isEmpty**: kiểm tra hàng đợi rỗng = - 1.
  - **isFull**: kiểm tra hàng đợi đầy = size - 1.
>✍️ **enqueue**:
> - Ban đầu khởi tạo 2 chỉ số:
>   - front = -1.
>   - rear = - 1.
> - **enqueue** chèn 1 phần tử vào cuối hàng đợi:
>   - rear++.
>   - rear = size - 1 -> Queue đầy
>   
> ![Image](https://github.com/user-attachments/assets/8459bf2a-caa3-4277-a48b-95924dbb33b0)

>✍️ **dequeue**:
>  - front++.
> 
>![Image](https://github.com/user-attachments/assets/1d57330e-71f9-47c4-946c-d2ef6ee04645)
>
>  - front = size hoặc front > rear -> Queue rỗng -> reset chỉ số front, rear = - 1.
>  
>  ![image](https://github.com/user-attachments/assets/806a1ea1-2dce-44c0-b0dc-f5928906a73c)

#### 1. Linear Queue - Hàng đợi tuyến tính:
- Khi `rear` đã max (= size - 1) thì queue luôn được coi là đầy:
  - Không thể thêm phần tử mới dù có khoảng trống ở đầu hàng đợi (do đã xóa phần tử ở đầu).
  - Chỉ thêm được phần tử khi dequeue toàn bộ phần tử -> `front` và `rear` được reset (= - 1).
- Nhược điểm:
  - Không thể tận dụng được những chỗ trống sau khi đã xóa gây lãng phí bộ nhớ.

> ![Image](https://github.com/user-attachments/assets/35de6092-b6f7-475a-b067-cc1e3abfe360)

>👉 Ví dụ: Viết code cho cấu trúc dữ liệu Linear Queue.

<details>
<summary>linear.h</summary>

```c
#ifndef LINEAR_H
#define LINEAR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *item;
    int size;
    int front;
    int rear;
}L_Queue;

/* Khởi tạo thông số ban đầu của Linear Queue */
void l_queue_init(L_Queue *queue, int Size);

/* Kiểm tra Queue rỗng */
bool queue_isEmpty(L_Queue queue);

/* Kiểm tra Queue đầy */
bool queue_isFull(L_Queue queue);

/* Thêm phần tử vào cuối hàng đợi */
void enqueue(L_Queue *queue, int data);

/* Xóa phần tử ở đầu hàng đợi */
int dequeue(L_Queue *queue);

/* Đọc giá trị phần tử ở đầu hàng đợi */
int front(L_Queue queue);

/* Đọc giá trị phần tử ở cuối hàng đợi */
int rear(L_Queue queue);

/* Giải phóng bộ nhớ động */
void free_queue(L_Queue *queue);

/* Hiển thị giá trị các phần tử trong Queue */
void display(L_Queue queue);

#endif  // LINEAR_H
```

</details>

<details>
<summary>linear.c</summary>

```c
#include "linear.h"

/* Khởi tạo thông số ban đầu của Linear Queue */
void l_queue_init(L_Queue *queue, int Size)
{
    queue->item = (int*)malloc(Size * sizeof(int));     // cấp phát động cho mảng item.
    queue->size = Size;     // gán số lượng phần tử
    queue->front = queue->rear = -1;    // khởi tạo giá trị ban đầu cho chỉ số front và rear
}

/* Kiểm tra Queue rỗng */
bool queue_isEmpty(L_Queue queue)
{
    return (queue.rear == -1 || (queue.front > queue.rear)) ? true : false;     // Kiểm tra hàng đợi rỗng: rear == -1 hoặc front > rear
}

/* Kiểm tra Queue đầy */
bool queue_isFull(L_Queue queue)
{
    return queue.rear == (queue.size - 1) ? true : false;        // Kiểm tra hàng đợi đầy: rear == size - 1
}

/* Thêm phần tử vào cuối hàng đợi */
void enqueue(L_Queue *queue, int data)
{
    if(queue_isFull(*queue))
    {
        printf("Queue is Full\n");      // kiểm tra hàng đợi đầy
    }
    else
    {
        if(queue->front == -1)
        {
            queue->front = queue->rear = 0;     // nếu chỉ số front = -1 thì gán giá trị 0 cho chỉ số front và rear
        }
        else
        {
          queue->rear++;    // nếu front != -1 thì rear + 1
        }
        queue->item[queue->rear] = data;    // gán giá trị vào phần tử chỉ số rear (thêm phần tử vào cuối hàng đợi)
        printf("Enqueue: %d\n", data);
    }
}

/* Xóa phần tử ở đầu hàng đợi */
int dequeue(L_Queue *queue)
{
    if (queue_isEmpty(*queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
        return -1;
    }
    else
    {
        int dequeue_val = queue->item[queue->front];    // đọc phần tử chỉ số front (ở đầu hàng đợi)
        queue->item[queue->front] = 0;      // gán giá trị 0 cho phần tử chỉ số front (xóa phần tử đầu hàng đợi)

        if(queue->front == queue->rear && queue->rear == queue->size - 1)
        {
            queue->front = queue->rear = -1;    // nếu front == rear và rear == size - 1 thì reset front và rear = -1
        }
        else
        {
            queue->front++;     // nếu không thì front + 1
        }
        printf("Dequeue: %d\n", dequeue_val);
        return dequeue_val;     // trả về hàm giá trị dequeue_val
    }
}

/* Đọc giá trị phần tử ở đầu hàng đợi */
int front(L_Queue queue)
{
    if(queue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
        return -1;
    }
    return queue.item[queue.front];     // trả về phần tử chỉ số front
}

/* Đọc giá trị phần tử ở cuối hàng đợi */
int rear(L_Queue queue)
{
    if(queue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
        return -1;
    }
    return queue.item[queue.rear];      // trả về phần tử chỉ số rear
}

/* Giải phóng bộ nhớ dộng */
void free_queue(L_Queue *queue)
{
    if (queue->item != NULL)    // kiểm tra mảng có = NULL không
    {
        free(queue->item);      // giải phóng bộ nhớ động cho mảng item
        queue->item = NULL;     // gán NULL cho con trỏ khi không dùng nữa
    }
}

/* Hiển thị giá trị các phần tử trong Queue */
void display(L_Queue queue)
{
    if (queue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
    }
    else
    {
        printf("Queue: ");
        for(int i = queue.front; i <= queue.rear;i++)
        {
            printf("%d ", queue.item[i]);       // in ra từng phần tử trong mảng động item
        }
        printf("\n");
    }
}
```
</details>

<details>
<summary>main.c</summary>

```c
#include "linear.h"

int main()
{
    L_Queue Queue1;     // khai báo biến Queue1 kiểu L_Queue
    l_queue_init(&Queue1, 5);   // Khởi tạo hàng đợi Queue1
    
    // Chèn phần tử vào cuối hàng đợi Queue1
    enqueue(&Queue1, 1);
    enqueue(&Queue1, 2);
    enqueue(&Queue1, 3);
    enqueue(&Queue1, 4);
    enqueue(&Queue1, 5);

    // Hiển thị các phần tử trong hàng đợi Queue1
    display(Queue1);

    printf("Front: %d\n", front(Queue1));
    printf("Rear: %d\n", rear(Queue1));
    
    // Xóa các phần tử ở đầu hàng đợi Queue1
    dequeue(&Queue1);
    dequeue(&Queue1);
    dequeue(&Queue1);
    dequeue(&Queue1);

    // Chèn phần tử vào cuối hàng đợi Queue1
    enqueue(&Queue1, 6);

    // Hiển thị các phần tử trong hàng đợi Queue1
    display(Queue1);

    return 0;
}
```
>➡️ Kết quả:
>
> ![Image](https://github.com/user-attachments/assets/b77e1b3f-62b0-4449-8ba0-3edc284902fd)
</details>

#### 2. Circular Queue - Hàng đợi vòng tròn:
- Khi `rear` đã max (= size - 1) và `front` đã tăng do dequeue phần tử:
  - `rear` sẽ quay về vị trí 0 để thêm phần tử, tận dụng khoảng trống (rear = 0).
  - `front` cũng sẽ reset khi dequeue hết phần tử.
- Các thao tác:
  - Kiểm tra queue empty:
    - front == -1 hoặc,
    - rear == -1.
    - Bỏ điều kiện front > rear vì front đã tự động quay về.
  - Kiểm tra queue full:
    - front == (rear + 1) % size.
    - Bỏ điều kiện rear == size - 1 vì rear tự động quay về.

>👉 Ví dụ: Viết code cho cấu trúc dữ liệu Circular Queue.

<details>
<summary>circular.h</summary>

```c
#ifndef CIRCULAR_H
#define CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Khai báo cấu trúc dữ liệu hàng đợi vòng tròn
typedef struct 
{
    int *item;
    int size;
    int front;
    int rear;
}c_queue;

/* Hàm khởi tạo các chỉ số ban đầu */
void c_queue_init(c_queue *queue, int Capacity);

/* Kiểm tra Queue rỗng */
bool cqueue_isEmpty(c_queue queue);

/* Kiểm tra Queue đầy */
bool cqueue_isFull(c_queue queue);

/* Thêm phần tử */
void enqueue(c_queue *queue, int value);

/* Xóa phần tử */
int dequeue(c_queue *queue);

/* Đọc giá trị phần tử chỉ số front */
int front(c_queue queue);

/* Đọc giá trị phần tử chỉ số rear */
int rear(c_queue queue);

/* Giải phóng bộ nhớ hàng đợi */
void free_cqueue(c_queue *queue);

/* Hiển thị giá trị các phần tử hàng đợi */
void display(c_queue queue);

#endif // CIRCULAR_H
```

</details>

<details>
<summary>circular.c</summary>

```c
#include "circular.h"

/* Hàm khởi tạo các chỉ số ban đầu */
void c_queue_init(c_queue *queue, int Capacity)
{
    queue->item = (int*)malloc(Capacity * sizeof(int));     // cấp phát động cho mảng item
    queue->size = Capacity;     // gán size = Capacity
    queue->front = queue->rear = -1;        // khởi tạo giá trị chỉ số ban đầu
}

/* Kiểm tra Queue rỗng */
bool cqueue_isEmpty(c_queue queue)
{
    return queue.front == -1 ? true : false;        // kiểm tra điều kiện hàng đơi rỗng: front == -1
}

/* Kiểm tra Queue đầy */
bool cqueue_isFull(c_queue queue)
{
    return queue.front == ((queue.rear+1)%queue.size) ? true : false;       // kiểm tra điều kiện hàng đợi đầy: front == (rear + 1) % size
}

/* Thêm phần tử */
void enqueue(c_queue *queue, int value)
{
    if (cqueue_isFull(*queue))
    {
        printf("Queue is Full!\n");     // kiểm tra hàng đợi đầy
    }
    else
    {
        if (queue->front == -1)     // nếu front hoặc rear == -1 thì gán 0 cho chỉ số front và rear 
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear = (queue->rear + 1) % queue->size;      // phép tính để rear quay vòng
        }
        queue->item[queue->rear] = value;       // gán giá trị mới vào phần tử chỉ số rear
        printf("Enqueue: %d\n", value);
    }
}

/* Xóa phần tử */
int dequeue(c_queue *queue)
{
    if (cqueue_isEmpty(*queue))
    {
        printf("Queue is Empty!\n");        // kiểm tra hàng đợi rỗng
        return -1;
    }
    else
    {
        int dequeue_val = queue->item[queue->front];    // đọc giá trị chuần bị xóa

        queue->item[queue->front] = 0;      // xóa phần tử chỉ số front

        if (queue->front == queue->rear)        // khi xóa phần tử cuối cùng thì reset chỉ số
        {
            queue->front = queue->rear = -1;        // reset lại chỉ số front và rear
        }
        else
        {
            queue->front = (queue->front + 1) % queue->size;        // phép tính để front xoay vòng
        }
        printf("Dequeue: %d\n", dequeue_val);   // in giá trị vừa xóa
        return dequeue_val;     // trả về giá trị vừa xóa
    }
}

/* Đọc giá trị phần tử chỉ số front */
int front(c_queue queue)
{
    if (cqueue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
        return -1;
    }
    return queue.item[queue.front];     // trả về giá trị phần tử chỉ số front
}

/* Đọc giá trị phần tử chỉ số rear */
int rear(c_queue queue)
{
    if (cqueue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
        return -1;
    }
    return queue.item[queue.rear];      // trả về giá trị phần tử chỉ số rear
}

/* Giải phóng bộ nhớ hàng đợi */
void free_cqueue(c_queue *queue)
{
    if(queue->item != NULL)     // kiểm tra cấp phát động có = NULL
    {
        free(queue->item);      // giải phóng bộ nhớ cho mảng item
        queue->item = NULL;     // gán NULL cho con trỏ đã dùng xong
    }
}

/* Hiển thị giá trị các phần tử hàng đợi */
void display(c_queue queue)
{
    if (cqueue_isEmpty(queue))
    {
        printf("Queue is Empty\n");     // kiểm tra hàng đợi rỗng
    }
    printf("Queue: ");

    int i = queue.front;      // bắt đầu in từ đầu hàng đợi, không in ra những ô trống đã bị dequeue

    /* Dùng while(i != rear) */
    // while (i != queue.rear)
    // {
    //     printf("%d ", queue.item[i]);   // in bắt đầu từ phần tử chỉ số front
    //     i = (i + 1) % queue.size;       // in những phần tử tiếp theo cho tới khi i = rear thì không in nữa
    // }
    // printf("%d\n", queue.item[queue.rear]);     // in ra phần tử cuối cùng

    /* Dùng while(1) */
    while (1)
    {
        printf("%d ", queue.item[i]);      // in bắt đầu từ phần tử chỉ số front
        if (i == queue.rear)
        {
            break;      // dừng sau khi in ra phần tử cuối
        }
        i = (i + 1) % queue.size;       // in những phần tử tiếp theo
    }
}

/* Hiển thị tất cả giá trị các phần tử hàng đợi */
void display_full_queue(c_queue queue)
{
    printf("Queue: ");
    for (int i = 0; i < queue.size; i++) 
    {
        int cqueue_isFilled = 0;

        if (queue.front != -1)  // kiểm tra hàng đợi không rỗng
        {
            // Trường hợp front <= rear
            if (queue.front <= queue.rear && i >= queue.front && i <= queue.rear)       // trường hợp bình thường khi chưa xong lại: front <= rear
            {
                cqueue_isFilled = 1;    // i thỏa mãn điều kiện: i >= front && i <= rear (nằm trong khoảng từ front -> rear) nghĩa là các phần tử đã được enqueue
            }
            // Trường hợp queue đã vòng lại
            else if (queue.front > queue.rear && (i >= queue.front || i <= queue.rear))     // trường hợp front > rear (rear đã vòng lại) 
            {
                cqueue_isFilled = 1;    // i thỏa mãn điều kiện: i >= front || i <= rear (i >= front -> đã dequeue và rear đã vòng lại ; i <= rear -> rear vòng lại, ví dụ i = 0 - rear = 1)
            } 
        }

        if (cqueue_isFilled)
        {
            printf("%d ", queue.item[i]);       // in ra những phần tử có chứa giá trị
        }
        else
        {
            printf("* ");       // phần tử không có giá trị sẽ in ra '*'
        }
    }
    printf("\n");
}
```

</details>

<details>
<summary>main.c</summary>

```c
#include "circular.h"

int main()
{
    c_queue cqueue1;

    // Khởi tạo hàng đợi Circular
    c_queue_init(&cqueue1, 5);

    /* Hiển thị tất cả giá trị các phần tử hàng đợi */
    printf("Display full queue: \n");
    display_full_queue(cqueue1);
    printf("\n");

    // Chèn phần tử
    printf("Case 1: front <= rear (not returned)\n");
    printf("Insert into the end of queue: \n");
    enqueue(&cqueue1, 1);
    enqueue(&cqueue1, 2);
    enqueue(&cqueue1, 3);
    enqueue(&cqueue1, 4);
    enqueue(&cqueue1, 5);
    enqueue(&cqueue1, 6);
    printf("\n");

    // Hiển thị hàng đợi
    printf("Display queue (normal): \n");
    display(cqueue1);
    printf("\n");

    // Xóa phần tử
    printf("Delete at the start of queue: \n");
    dequeue(&cqueue1);
    dequeue(&cqueue1);

    // Hiển thị hàng đợi
    printf("Display queue (normal): \n");
    display(cqueue1);
    printf("\n");

    /* Hiển thị tất cả giá trị các phần tử hàng đợi */
    printf("Display full queue: \n");
    display_full_queue(cqueue1);
    printf("\n");

    // Chèn phần tử
    printf("Case 2: front > rear (rear returned)\n");
    enqueue(&cqueue1, 7);
    enqueue(&cqueue1, 8);

    /* Hiển thị tất cả giá trị các phần tử hàng đợi */
    printf("Display full queue: \n");
    display_full_queue(cqueue1);
    printf("\n");

    return 0;
}
```
>➡️ Kết quả:
>
> ![Image](https://github.com/user-attachments/assets/312c138a-f01c-4b91-a66b-56a8d4e17d15)

</details>

[🔼 _UP_](#top)
</details>


<details>
<summary>🔖 <b>BÀI 10: LINKED LIST</b></summary>

### I. Array:

- Mảng là một tập hợp các phần tử có kích thước cố định được lưu trữ trong các vị trí bộ nhớ liền kề.
- Thêm và xóa 1 phần tử trong array có rất nhiều bước khiến tốc độ chương trình sẽ bị chậm.

>👉 Ví dụ: Xóa 1 phần tử trong array: int arr[] = {1, 2, 3, 4, 5};.

- Cách để xóa phần tử trong mảng:
  - Xóa dữ liệu: ghi `0` hoặc `\0` vào vị trí phần tử cần xóa.
  - Dịch trái 4 byte.
  - Dùng realloc để phân bổ lại.

> ![image](https://github.com/user-attachments/assets/8b9138a9-414b-4afa-9f9e-3299f292da85)

>👉 Ví dụ: Thêm 1 phần tử trong array: int arr[] = {1, 2, 4, 5};.

- Cách để thêm phần tử trong mảng:
  - Dùng realloc để phân bổ lại.
  - Dịch phải 4 byte.
  - Ghi giá trị mới

> ![Image](https://github.com/user-attachments/assets/a2711cb2-d73f-4cb9-ae9a-5b7f13fe611a)

### II. Danh sách liên kết - Linked list:

- Linked list là một cấu trúc dữ liệu trong lập trình máy tính, dùng để tổ chức và lưu trữ dữ liệu.
- 1 linked list gồm 1 chuỗi các nút (nodes), mỗi nút chứa 1 giá trị dữ liệu và 1 con trỏ trỏ đến nút tiếp theo trong chuỗi (lưu trữ trong những vùng nhớ riêng biệt không liền kề).



[🔼 _UP_](#top)
</details>
