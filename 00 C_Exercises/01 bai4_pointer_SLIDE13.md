<a name="top"></a>

### Phân tích đoạn code sắp xếp lại theo tên, ID, điểm của sinh viên với thứ tự từ thấp đến cao.

<details>
<summary><b>main.c</b></summary>
    
```c
#include <stdio.h>
#include <string.h>

// Khai báo kiểu struct SinhVien
typedef struct
{
    char ten[50];           // chuỗi tên 50 ký tự
    float diemTrungBinh;    
    int id;
} SinhVien;

// Hàm so sánh 2 chuỗi
int stringCompare(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))       // so sánh từng ký tự trong chuỗi cho đến khi gặp ký tự null hoặc ký tự khác nhau
    {
        str1++;     // trỏ đến ký tự tiếp
        str2++;     // trỏ đến ký tự tiếp
    }
    return (*(const unsigned char*)str1 - *(const unsigned char*)str2);     // trả về hiệu của 2 ký tự: giống = 0 - khác != 0
}


// Hàm so sánh theo tên
int compareByName(const void *a, const void *b)
{
    SinhVien *sv1 = (SinhVien *)a;              // ép kiểu con trỏ void* thành kiểu con trỏ SinhVien* và gán cho sv1
    SinhVien *sv2 = (SinhVien *)b;              // ép kiểu con trỏ void* thành kiểu con trỏ SinhVien* và gán cho sv2
    return stringCompare(sv1->ten, sv2->ten);   // so sánh 2 chuỗi tên
}

// Hàm so sánh theo điểm trung bình
int compareByDiemTrungBinh(const void *a, const void *b)
{
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->diemTrungBinh > sv2->diemTrungBinh) return 1;  // nếu điểm sv1 > điểm sv2 thì trả về 1
    return 0;                                               // nếu không thì trả về 0 (điểm sv1 < điểm sv2)
}

// Hàm so sánh theo ID
int compareByID(const void *a, const void *b)
{
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return sv1->id - sv2->id;        // trả về hiệu của 2 ID: _Số âm: sv1->id < sv2->id; _Số dương: v1->id > sv2->id
}

// Hàm sắp xếp chung
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *))
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-i-1; j++)
        {
            if (compareFunc(array+j, array+j+1)>0)      // so sánh lần lượt phần tử arr + j với arr + j + 1 
            {
                SinhVien temp = array[j];               // hoán đổi 2 phần tử
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// Hàm in ra các phần tử SinhVien
void display(SinhVien *array, size_t size)
{
   for (size_t i = 0; i < size; i++)
   {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}

int main() 
{
    SinhVien danhSachSV[] =
    {
        {  
            .ten = "Hoang",
            .diemTrungBinh = 7.5,
            .id = 100
        },
        {
            .ten = "Tuan",
            .diemTrungBinh = 4.5,
            .id = 101
        },
        {
            .ten = "Vy",
            .diemTrungBinh = 6.8,
            .id = 102},
        {  
            .ten = "Ngan",
            .diemTrungBinh = 5.6,
            .id = 10
        }
    };

    size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);

    // Sắp xếp theo tên
    sort(danhSachSV, size, compareByName);
    display(danhSachSV, size);

    // Sắp xếp theo điểm trung bình
    sort(danhSachSV, size, compareByDiemTrungBinh);
    display(danhSachSV, size);

    // Sắp xếp theo ID
    sort(danhSachSV, size, compareByID);
    display(danhSachSV, size);

    return 0;
}

```

> ➡️ Kết quả:
> 
> ![image](https://github.com/user-attachments/assets/aceea4e4-6189-486d-a0b8-ae92f9d59621)


[🔼 _UP_](#top)

</details>
