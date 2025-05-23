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
  - Là một hàm - method, có 3 dạng:
    - Không tham số.
    - Có tham số.
    - Danh sách khởi tạo (Initialization list).
  - Đặc điểm:
    - Không có kiểu trả về.
    - Trùng tên với class.
    - Dùng để khởi tạo những giá trị cho các biến trong class.
    - Tự động gọi khi khởi tạo một object.
  
> 👉 Ví dụ:
>     - Sử dụng Constructor để khởi tạo cho các biến mà không cần qua các object.

> Constructor không có tham số:

<details>
<summary>🔖 <b>constructor.cpp</b></summary>

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

</details>

> Constructor có tham số:
> - Có 2 loại:
>   - Có giá trị mặc định: khi khởi tạo object không cần thiết truyền giá trị.
 ```cpp
      User(int _a = 1, double _b = 2, char _c = 'd')
       {
            a = _a;
            b = _b;
            c = _c;
       }
 ```
>   - Không có giá trị mặc định: khi khởi tạo object bắt buộc phải truyền giá trị.

<details>
<summary>🔖 <b>constructor.cpp</b></summary>

```cpp
#include <iostream>
using namespace std;

class User
{
    public:
        int a;
        double b;
        char c;

        // Constructor
        User(int _a, double _b, char _c)   // tham số không có giá trị mặc định
        {
            a = _a;
            b = _b;
            c = _c;
        }

        void create()   // hàm
        {
            User user1(2,4,'c');
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
    User user1(1, 2, 'a'), user2(3,4,'b');

    user1.display();

    user2.display();

    return 0;
}
```

> ➡️ Kết quả:
>
> ![image](https://github.com/user-attachments/assets/bfd48341-5b1f-4dae-bbc3-949a0198b721)

</details>

> Constructor danh sách khởi tạo:
>  - Liệt kê ra một danh sách các biến và các giá trị sẽ truyền vào cho các biến đó.
>  - Không cần phải gán giá trị cho các biến nữa.
>  - Sử dụng dấu ':' để Compiler biết mình sử dụng danh sách khởi tạo.
>  - Câu lệnh bên trong body sẽ được thực thi sau danh sách khởi tạo.
 ```cpp
      User(int _a = 1, double _b = 2, char _c = 'd')
       : a(_a), b(_b), c(_c){}
 ```

- Destructor:
  - Là một hàm - method, không có tham số.
  - Đặc điểm:
    - Không có kiểu trả về.
    - Trùng tên với class, nhưng có thêm dấu '~' phía trước.
    - Tự động gọi trước khi một object được thu hồi.
    - Dùng để xóa dữ liệu của các biến.
  
> 👉 Ví dụ:
> - Trước khi các object cục bộ trong stack được thu hổi ở hàm main thì destructor sẽ được tự động gọi ra.

<details>
<summary>🔖 <b>destructor.cpp</b></summary>

```cpp
#include <iostream>
using namespace std;

class User
{
    public:
        int a;
        double b;
        char c;

        // Constructor
        User(int _a, double _b, char _c) 
        {
            a = _a;
            b = _b;
            c = _c;
        }

        // Destructor
        ~User() 
        {
            printf("Destructor!\n");
            a = b = 0;
            c = '\n';
            display();
        }

        void display();
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
    User user1(1, 2, 'a'), user2(3,4,'b');

    user1.display();

    user2.display();

    return 0;
}
```

> ➡️ Kết quả:
>
> ![image](https://github.com/user-attachments/assets/1836ffd8-1085-4c2b-b3dc-fac7b77a8304)

</details>

- Biến static trong class:
  - Khi 1 biến static được khai báo trong class, thì tất cả các object sẽ dùng chung địa chỉ của biến đó.
  - Khai báo trong class và khởi tạo bên ngoài class.
 
<details>
<summary>🔖 <b>staticEx.cpp</b></summary>

```cpp
#include <iostream>
using namespace std;

class User
{
    public:
        static int x;

};

int User::x = 0;

int main()
{
    User user1, user2;

    user1.x = 100;
    cout << "x: " << user1.x << endl;

    user2.x = 200;
    cout << "x: " << user2.x << endl;

    return 0;
}
```

> ➡️ Kết quả:
>
> ![image](https://github.com/user-attachments/assets/9954845c-74c7-4b53-8913-5750c35cfb2c)

</details>


[🔼 _UP_](#top)

</details>
