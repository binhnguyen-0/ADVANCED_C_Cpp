
<a name="top"></a>

### Phân tích đoạn code bật tắt các tính năng trong xe ô tô bằng bitmask.

<details>
<summary><b>main.c</b></summary>
	
```c
#include <stdio.h>
#include <stdint.h>

// Định nghĩa các màu sắc của ô tô
#define COLOR_RED    0    // 0b 0000 0000
#define COLOR_BLUE   1    // 0b 0000 0001
#define COLOR_BLACK  2    // 0b 0000 0010
#define COLOR_WHITE  3    // 0b 0000 0011

// Định nghĩa mã lực của ô tô
#define POWER_100HP  0    // 0b 0000 0000
#define POWER_150HP  1    // 0b 0000 0001
#define POWER_200HP  2    // 0b 0000 0010

// Định nghĩa động cơ của ô tô
#define ENGINE_1_5L  0    // 0b 0000 0000
#define ENGINE_2_0L  1    // 0b 0000 0001

/* Định nghĩa lại kiểu uint8_t */
typedef uint8_t CarColor;    // CarColor là uint8_t
typedef uint8_t CarPower;    // CarPower là uint8_t
typedef uint8_t CarEngine;   // CarEngine là uint8_t

/* Định nghĩa thêm các tùy chọn khác */
#define SUNROOF_MASK         1 << 0    // 0b 0000 0001
#define PREMIUM_AUDIO_MASK   1 << 1    // 0b 0000 0010
#define SPORTS_PACKAGE_MASK  1 << 2    // 0b 0000 0100

// Khai báo cấu trúc CarOptions
typedef struct 
{
    uint8_t additionalOptions : 3;      // Sử dụng 3 bit cho additionalOptions
    CarColor color : 2;                 // Sử dụng 2 bit cho color
    CarPower power : 2;                 // Sử dụng 2 bit cho power
    CarEngine engine : 1;               // Sử dụng 1 bit cho engine
} CarOptions;

// Hàm cấu hình xe ô tô
void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options)
{
    car->color = color;                     // Truy cập thành phần color trong struct CarOptions qua con trỏ car và gán giá trị của biến color.
    car->power = power;                     // Truy cập thành phần power trong struct CarOptions qua con trỏ car và gán giá trị của biến power.
    car->engine = engine;                   // Truy cập thành phần engine trong struct CarOptions qua con trỏ car và gán giá trị của biến engine.
    car->additionalOptions = options;       // Truy cập thành phần additionalOptions trong struct CarOptions qua con trỏ car và gán giá trị của biến options.
}

/* Hàm cài Options cho ô tô */
void setOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions |= optionMask;      // Bật bit tương ứng bằng OR
}

/* Hàm hủy cài Options cho ô tô */
void unsetOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions &= ~optionMask;      // Tắt bit option tương ứng bằng & ~
}

/* Hàm in ra các thông tin */
void displayCarOptions(const CarOptions car) 
{
    const char *colors[] = {"Red", "Blue", "Black", "White"};	// Khai báo mảng con trỏ trỏ đến từng thành phần chuỗi ký tự không thay đổi được.
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    
    printf("Color: %s\n", colors[car.color]);		// In ra phần tử car.color trong mảng colors
    printf("Power: %s\n", powers[car.power]);		// In ra phần tử car.power trong mảng powers
    printf("Engine: %s\n", engines[car.engine]);	// In ra phần tử car.engine trong mảng engines

    // Nếu đã bật option thì Yes, chưa thì No
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");                 
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main() {
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0); 
	
    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    
    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));

    return 0;
}
```

> ➡️ Kết quả:
> 
> ![image](https://github.com/user-attachments/assets/f806656f-ce10-4030-8347-05dc36f5caab)


[🔼 _UP_](#top)

</details>
