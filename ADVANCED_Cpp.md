<a name="top"></a>
# 📖 ADVANCED_CPP
----
<details>
<summary>🔖 <b>Bài 15: CLASS</b></summary>

### 📑 I. Khái niệm:

- Từ khóa `class` được dùng để định nghĩa một lớp, là một cấu trúc dữ liệu do người dùng tự định nghĩa có thể chứa dữ liệu và các hàm thành viên.
- Class là nền tảng của lập trình hướng đối tượng OOP trong C++.
- Định nghĩa Class (class definition hoặc template):
  
```cpp
class class_Name
{
    access_specifier:    // phạm vi truy cập là private, public, protected
    data member;         // những biến thành viên - thuộc tính attribute
    member funtions(){}  // hàm được khai báo bên trong class - phương thức method.
};
```

#### a) Access Specifier:
  - Kiểm soát quyền truy cập vào các thành viên của class.
  - Các cấp độ truy cập:
    - public: các thành viên class có thể truy cập được từ bên ngoài.
    - private: chỉ có thể truy cập trong chính class.
    - protected: truy cập trong class và bởi class con kế thừa.
    - Cấp độ mặc định là private.

> 👉 Ví dụ: Cấp độ truy cập public:
> - truy cập từ ngoài class
> - truy cập bên trong class

<details>
<summary>🔖 <b>publicEx.cpp</b></summary>

```cpp
#include <iostream>
using namespace std;

class User
{
    public:

    int a;
    double b;
    char c;

    void create()        // truy cập từ bên trong Class
    {
        User user1;      // user1 là đối tượng (object)

        user1.a = 30;
        user1.b = 20;
        user1.display();
    }

    void display();        // định nghĩa hàm bên trong class
    //{
    //    cout << a << endl;
    //    cout << b << endl;
    //}
};

void User::display()     // định nghĩa hàm bên ngoài class sử dụng toán tử `::`
{
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    User user1, user2;    // user1, user2 là đối tượng (object)

    user1.a = 10;        // truy cập bên ngoài class
    user1.b = 20.6;

    user1.display();
    user1.create();
    return 0;
}
```

</details>

#### b) Special Member Functions - Methods:

- Constructor:
  - Là một hàm - method.
  - Đặc điểm:
    - Không có kiểu trả về.
    - Trùng tên với class.
    - Dùng để khởi tạo những giá trị cho các biến trong class.
    - Tự động gọi khi khởi tạo một object.
> 👉 Ví dụ:
>     - Sử dụng Constructor để khởi tạo cho các biến mà không cần qua các object.

```c
#include <iostream>
using namespace std;

class User
{
    public:
        int a;
        double b;
        char c;

        // Constructor
        User() 
        {
            a = 1;
            b = 2.5;
            c = 'A';
        }

        void create()   // hàm
        {
            User user1;

            user1.a = 30;
            user1.b = 20;
            user1.display();
        }

        void display();  // hàm
        // {
        //     cout << a << endl;
        //     cout << b << endl;
        // }
};

void User::display()
{
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

int main()
{
    User user1, user2;

    // user1.a = 10;
    // user1.b = 20.6;

    user1.display();

    return 0;
}
```

> ➡️ Kết quả:
>
> ![image](https://github.com/user-attachments/assets/08f00124-8019-4d29-8359-0ab84d586715)

 
[🔼 _UP_](#top)

</details>
