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
- Khái niệm	Là 1 kiểu dữ liệu do người dùng tự định nghĩa. Struct được sử dụng khi muốn lưu trữ một tập hợp các kiểu dữ liệu khác nhau dưới một tên duy nhất.	
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
>✍️ 1. Các thành viên của struct không được khởi tạo khi khai báo struct.<br>
>✍️ 2. Theo mặc định, các thành viên chưa được khởi tạo chứa giá trị rác, nhưng khi một biến được khởi tạo thì những thành viên còn lại chưa được khởi tạo rõ ràng sẽ được khởi tạo bằng 0.<br>
>✍️ 3. Khởi tạo khi khai báo biến kiểu struct.<br>
```c
struct struct_name str = {"abc", val1, val2, ...};  // Các giá trị sẽ được gán theo thứ tự.
```
>✍️ 4. Khởi tạo chỉ 1 số thành viên.	1. struct struct_name{ <datatype_1> <member1> = value1; }: gây ra lỗi Compiler error bởi vì khi một kiểu dữ liệu được khai báo thì không có bộ nhớ nào được phân bổ cho nó , vì vậy không có không gian để lưu trữ giá trị được gán (bộ nhớ chỉ được phân bổ khi biến được tạo).
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
  - CPU truy cập bộ nhớ bằng 1 `word` (CPU 32 bit: 1 word = 4 byte | CPU 64 bit: 1 word = 8 byte) tại 1 thời điểm, nên CPU thực hiện đọc và ghi vào bộ nhớ hiệu quả nhất là khi dữ liệu được căn chỉnh - nghĩa là memory address của data là bội số của data size.
  - Tóm lại, để đọc một data có `n` byte, data đó nên đặt ở address là bội số của `n`.
  - Boundary - Ranh giới:
    - Ranh giới `n` byte là địa chỉ bộ nhớ mà chia hết cho `n`.
    - Đối với kiểu `int` - ranh giới 4 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 4, 8, 12, ... `.
    - Đối với kiểu `char` - ranh giới 1 byte: đặt tại địa chỉ có kết thúc bằng `0, 1, 2, 3, 4, ... `.
    - Đối với kiểu `short` - ranh giới 2 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 2, 4, 6, 8, ... `.
    - Đối với kiểu `double` - ranh giới 8 byte: đặt tại địa chỉ thường có kết thúc bằng `0, 8, 16, 24, ... `.
>👉 Ví dụ:
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
    /* data */
    DataSet data;
    data.data1 = 'A';
    data.data2 = 0xFFFFEEEE;
    data.data3 = 0x22;
    data.data4 = 0xABCD;
    
    /* Pointer */
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
>👉 Kết quả:







[🔼 _UP_](#top)
</details>
