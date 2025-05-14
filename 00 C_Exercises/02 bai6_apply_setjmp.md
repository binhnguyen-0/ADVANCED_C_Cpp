
<a name="top"></a>

### Phân tích đoạn code bật tắt các tính năng trong xe ô tô bằng bitmask.

<details>
<summary><b>main.c</b></summary>
	
```c
#include <stdio.h>
#include <setjmp.h>
#include <string.h>

char error_code[50];

#define TRY if ((exception = setjmp(buf)) == 0)
#define CATCH(x) else if (exception == x)
#define THROW(x, message)               \
{                                       \
    int size = strlen(message);         \
    for (int i = 0; i < size; i++)      \
    {                                   \
        error_code[i] = message[i];     \
    }                                   \
    error_code[size] = '\0';            \
    longjmp(buf, x);                    \
}

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
   THROW(NO_EXIST, "Lỗi không tồn tại");  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 1
  }
  else if (b == 0)
  {
    THROW(DIVIDE_BY_0, "Lỗi chia cho 0");  // Nếu a và b đều bằng 0 thì nhảy về setjmp và trả về 2
  }
  return (double)a/b;
}

int main()
{
  exception = NO_ERROR;
  TRY
  {
    printf("Kết quả: %.2f\n", divide(5,0));  // Lần gọi trực tiếp setjmp đầu tiên luôn có kq là 0 trả về
  }
  CATCH(NO_EXIST)
  {
    printf("%s\n", error_code);  // Nếu kq trả về là 1 thì hiện câu lệnh.
  }
  CATCH(DIVIDE_BY_0)
  {
    printf("%s\n", error_code);  // Nếu kq trả về là 2 thì hiện câu lệnh.
  }
  return 0;
}
```

> ➡️ Kết quả:
> 
> ![image](https://github.com/user-attachments/assets/f806656f-ce10-4030-8347-05dc36f5caab)


[🔼 _UP_](#top)

</details>
