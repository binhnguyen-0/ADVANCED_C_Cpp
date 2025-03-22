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
  |**`va_arg(list, type)`**|Truy xuất tham số - |`#define sum(...) \`<br>`int arr[__VA_ARGS__]; \`<br>`int result = 0; \`<br>`for (int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++) \`<br>`{ result += arr[i]; } \`<br>`printf("Sum = %d\n", result);`<br>--> `sum(1,2,3,4);`: tính tổng 1+2+3+4|
<br>
</details>
