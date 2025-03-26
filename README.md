<a name="top"></a>
# 📖 ADVANCED_C_Cpp
----
<details>
<summary>🔖 <b>BÀI 1: COMPILER - MACRO</b></summary>
 
### 📑 I. Compiler:
- Trình biên dịch là chương trình chuyển đổi source code C thành mã máy để máy tính có thể thực thi.
- Quá trình biên dịch gồm 4 giai đoạn:
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
  listSelectedFeatures(options);    truyền vào giá trị sao chép của options sau khi đã bật cá tính năng để in ra các tính năng đó.
  return 0;
```
[🔼 _UP_](#top)
</details>

<details>
<summary>🔖 <b>BÀI 4: POINTER</b></summary>
 
- Con trỏ là một biến chứa giá trị là địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm).
  - Cách khai báo: `type ptrname` - `int *ptr;`.
  - Lấy địa chỉ của 1 biến x kiểu int: `int *ptr = &x;`.
  - Truy cập giá trị của biến bằng cách giải tham chiếu: `int y = *ptr;`: y = giá trị của biến x mà con trỏ ptr trỏ tới.
- Cách 1 biến được lưu trữ trong bộ nhớ:
  - Ví dụ 1 biến int 32 bit (4 byte) được lưu trữ thành 1 nhóm địa chỉ, mỗi địa chỉ lưu trữ 8 bit (1 byte) giá trị bắt đầu từ LSB đến MSB.
 ![Cách lưu trữ địa chỉ và giá trị của biến int](https://github.com/user-attachments/assets/3f4514ad-3758-4354-9fec-4e81327a2e0c)
- Kích thước của con trỏ:
  - Phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc là kiến trúc của vi xử lý.
  - Ví dụ với máy tính có 64 bit operating system thì thường là pointer sẽ có kích thước là 8 bytes (64 bit).
- Cách 1 con trỏ được lưu trữ trong bộ nhớ:
  - Ví dụ 1 con trỏ trỏ tới 1 biến int, mối địa chỉ của con trỏ sẽ lưu trữ 1 giá trị là địa chỉ của biến int đó, và những địa chỉ còn lại sẽ được mặc định là chứa 0x00.
![image](https://github.com/user-attachments/assets/ead4d1e7-bd97-4098-bb93-aa32a198e32a)

[🔼 _UP_](#top)
</details>
