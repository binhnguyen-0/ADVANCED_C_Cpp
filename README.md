<a name="top"></a>
# 📖 ADVANCED_C_Cpp
----
<details>
<summary>🔖 <b>BÀI 1: COMPILER - MACRO</b></summary>
 
### 📑 I. Compiler:
- Trình biên dịch là chương trình chuyển đổi source code C thành mã máy để máy tính có thể thực thi.
- Quá trình biên dịch gồm 4 giai đoạn:
![Image](https://github.com/user-attachments/assets/3a955cb2-1589-4680-a75e-5d2ec4b280ac)
<br>&nbsp;1. Preprocess (Tiền xử lý):<br>
&nbsp;&nbsp;- &nbsp;**Lệnh tạo _file.i_ từ _file.c_ với trình gcc trong VS Code:** `gcc -E file.c -o file.i`.<br>
&nbsp;&nbsp;- &nbsp;**Xử lý các loại chỉ thị tiền xử lý:** `#include`, `#define`, `#ifdef`, etc.<br>
&nbsp;&nbsp;- &nbsp;**Xóa các comment:** `// comment`, `/* comment */`.<br>
&nbsp;2. Compiler (Quá trình biên dịch):<br>
&nbsp;&nbsp;- &nbsp;**Lệnh tạo _file.s_ từ _file.i_:** `gcc -S file.i -o file.s`.<br>
&nbsp;&nbsp;- &nbsp;**File.s là file assembly code (mã hợp ngữ):** là ngôn ngữ bậc thấp, giúp điều khiển phần cứng dễ dàng.<br>
&nbsp;3. Assembler (Quá trình dịch hợp ngữ):<br>
&nbsp;&nbsp;- &nbsp;**Lệnh tạo _file.o_ từ _file.s_:** `gcc -c file.s -o file.o`.<br>
&nbsp;&nbsp;- &nbsp;**File.o là file Object:** dịch Assembly code thành mã máy mà máy tính có thể hiểu được.<br>
&nbsp;4. Linker (Quá trình liên kết):<br>
&nbsp;&nbsp;- &nbsp;**Lệnh tạo _file.exe_ từ các _file.o_:** `gcc file1.o file2.o -o filemain`.<br>
&nbsp;&nbsp;- &nbsp;**Lệnh chạy _file.exe_:** `./filemain`.<br>
&nbsp;&nbsp;- &nbsp;**Liên kết các file.o:** Tất cả các file.o sẽ được liên kết lại và tạo thành 1 file.exe để có thể chạy được chương trình.<br>
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
  - Khi mỗi lần gọi hàm `count` thì kết quả biến `a` luôn = 0 bởi vì dòng khởi tạo biến luôn được thực thi nên mỗi lần gọi kết quả đều giống nhau.

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



[🔼 _UP_](#top)
</details>
