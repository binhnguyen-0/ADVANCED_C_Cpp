# ADVANCED_C_Cpp
----
## BÀI 1: COMPILER - MACRO
### I. Compiler:
- Trình biên dịch là chương trình chuyển đổi source code C thành mã máy để máy tính có thể thực thi.
- Quá trình biên dịch gồm 4 giai đoạn:
 1. Preprocess (Tiền xử lý):
  - **Lệnh tạo _file.i_ từ _file.c_ với trình gcc trong VS Code:** `gcc -E file.c -o file.i`.
  - **Xử lý các loại chỉ thị tiền xử lý:** `#include`, `#define`, `#ifdef`, etc.
  - **Xóa các comment:** `// comment`, `/* comment */`.
 2. Compile (Biên dịch):
  - **Lệnh tạo _file.i_ từ _file.c_ với trình gcc trong VS Code:** `gcc -E file.c -o file.i`.
  - **Xử lý các loại chỉ thị tiền xử lý:** `#include`, `#define`, `#ifdef`, etc.
  - **Xóa các comment:** `// comment`, `/* comment */`.
 3. Assemble (Hợp ngữ):
 4. Link (Liên kết):
### II. Preprocessor Directives (Chỉ thị tiền xử lý):
- Là các instructors cho Preprocessor để thực hiện các nhiệm vụ như thay thế văn bản, mở rộng macro, thêm header file, và các nhiệm vụ khác.
- Bắt đầu bằng `#`.
- Các loại chỉ thị tiền xử ý:
  |💡 Preprocessor Directives|📄 Description|📌 Examples|
  |:------------------------:|:------------------------|:------------------------|
  |**#define**|Dùng để define Macro|`#define PI 3.14` <br>`#define SQUARE(x) ((x) * (x))`<br>`#define MAX(x, y) ((x) > (y) ? (x) : (y))`<br>`#define SUM(a,b,c) \`<br>  `(a + b+ c)`: dùng dấu gạch chéo `\` để báo rằng macro vẫn tiếp tục ở dòng dưới|
  |**#undef**|Dùng để hủy định nghĩa Macro|`#define SENSOR_DATA 42`: định nghĩa macro<br>`#undef SENSOR_DATA `: hủy định nghĩa<br>`#define SENSOR_DATA 50`: định nghĩa lại bằng giá trị khác|
  |**#include**|Dùng để đưa các tệp bên ngoài vào chương trình hiện tại|`#include <stdio.h>`: yêu cầu Compiler tìm kiếm file trong Standard Directory của Compiler<br>`#include "file.h"`: tìm kiếm trong directory của source file|
  |**#if**|Kiểm tra điều kiện được chỉ định|`#define STM32 0`<br>`#define ATMEGA 1`<br>`#define PIC 2`<br>`#if MCU == STM32`|
  |**#elif**|Thêm 1 điều kiện nữa trong **#if & #else**|`#elif MCU == ATMEGA`: nếu điều kiện của **#if** sai thì xét điều kiện của **#elif**|
  |**#else**|Thực thi mã thay thế khi điều kiện của **#if hay #elif** sai||
  |**#endif**|Dùng để đánh dấu sự kết thúc của **#if & #ifdef & #ifndef**||
  |**#ifdef**|Kiểm tra 1 Macro đã được định nghĩa hay không, có thì thực thi mã bên dưới.|`#define DEBUG`<br>`#ifdef DEBUG`<br>`...`<br>`#endif`|
  |**#ifndef**|Kiểm tra 1 Macro chưa được định nghĩa, nếu đúng mã bên dưới sẽ được thực thi|`#ifndef PI`<br>`#define PI 3.14159`<br>`#endif`|
