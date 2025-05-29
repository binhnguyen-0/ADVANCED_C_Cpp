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
> - truy cập từ ngoài class.
> - truy cập bên trong class.

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

> 👉 Ví dụ: Cấp độ truy cập private:
> - không thể truy cập từ ngoài class, phải truy cập thông qua trung gian ở cấp độ public.
> - truy cập bên trong class.

<details>
<summary>🔖 <b>privateEx.cpp</b></summary>

```cpp
#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
    private:
        string name;
        int age;
        int id;

    public:
        // Tự động +1 khi khởi tạo 1 object.
        SinhVien()
        {
            static int _id = 1;
            id = _id;
            _id++;
        }

        // Hàm kiểm tra xem tên có hợp lệ không
        bool checkName(string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                char c = str[i];
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')))
                {
                    return false;
                }
            }
            return true;
        }

        // Hàm kiểm tra xem tuổi có hợp lệ không
        bool checkAge(int age)
        {
            if (age <= 0) return false;
            return true;
        }

        // Hàm truy cập vào name cấp độ private
        void setName(string newName)
        {
            if (checkName(newName))
            {
                name = newName;
            }
            else
            {
                cout << "Unvalid name !" << endl;
                name = "";
            }
        }

        // Hàm truy cập vào age cấp độ private
        void setAge(int newAge)
        {
            if (checkAge(newAge))
            {
                age = newAge;
            }
            else
            {
                cout << "Unvalid age !" << endl;
                age = 0;
            }
        }

        // Hàm hiển thị
        void display()
        {
            cout << "Tên: " << name << endl;
            cout << "Tuổi: " << age << endl;
            cout << "MSV: " << id << endl;
        }
};

int main()
{
    SinhVien user1, user2;

    // phải truy cập các property ở cấp độ private thông qua hàm setName ở cấp độ public
    user1.setName("A");      
    user1.setAge(1);    
    user1.display();        

    cout << endl;

    user2.setName("B");
    user2.setAge(2);
    user2.display();

    cout << endl;
    
    return 0;
}
```

</details>

> 👉 Ví dụ: Cấp độ truy cập protected:
> - không thể truy cập từ ngoài class, phải truy cập thông qua trung gian ở cấp độ public.
> - truy cập bên trong base class và derived class.

```cpp
#include <iostream>
#include <string>

using namespace std;

class DoiTuong
{
    protected:
        string name;
        int age;
        int id;

        bool checkName(string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                char c = str[i];
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')))
                {
                    return false;
                }
            }
            return true;
        }

        bool checkAge(int age)
        {
            if (age <= 0) return false;
            return true;
        }

    public:
    
        DoiTuong()
        {
            static int _id = 1;
            id = _id;
            _id++;
        }

        void setName(string newName)
        {
            if (checkName(newName))
            {
                name = newName;
            }
            else
            {
                cout << "Unvalid name !" << endl;
                name = "";
            }
        }

        void setAge(int newAge)
        {
            if (checkAge(newAge))
            {
                age = newAge;
            }
            else
            {
                cout << "Unvalid age !" << endl;
                age = 0;
            }
        }

        string getName()
        {
            return name;
        }

        void display()
        {
            cout << "Tên: " << getName() << endl;
            cout << "Tuổi: " << age << endl;
            cout << "MSV: " << id << endl;
        }
};

class SinhVien : public DoiTuong
{
    private:
        string chuyenNganh;
    public:
        void create()
        {
            // Kế thừa được cả method và property cấp độ protected trong DoiTuong
            SinhVien sv1;
            sv1.setAge(6);
            sv1.age;
            sv1.checkAge(6);
        }
};

int main()
{
    SinhVien user1, user2;

    // Kế thừa được những method cấp độ public trong class DoiTuong, không kế thừa được cấp độ protected trong DoiTuong
    user1.setAge(9);
    user1.setName("n");

    return 0;
}
```


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

#### c) Từ khóa static trong class:

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
        static int *d;

};

int User::x = 0;

int* User::d = nullptr;

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

- Hàm static trong class:
  - Độc lập với các object, không cần thông qua object gọi ra, có thể gọi trực tiếp từ class.
  - Có thể được gọi khi không có object nào tồn tại.
  - Chỉ được sử dụng các biến static.

<details>
<summary>🔖 <b>staticMethod.cpp</b></summary>

```cpp
#include <iostream>
using namespace std;

class User
{
    public:
        int a;
        static int x;

        static void test()
        {
            cout << "static method\n";
            cout << x;                      // chỉ sử dụng được biến static
        }
};

int User::x = 0;


int main()
{
    User user1, user2;

    user1.test;     // gọi qua object

    User::test();   // gọi trực tiếp từ class

    return 0;
}
```

</details>

[🔼 _UP_](#top)

</details>


<details>
<summary>🔖 <b>Bài 16: OOP</b></summary>

### 📑 I. Khái niệm:

#### 1. Tính đóng gói: 

- Tính đóng gói (Encapsulation) là ẩn đi các property khỏi người dùng. Nghĩa là khai báo các property ở quyền truy cập private hoặc protected, không thể truy cập chúng từ các object bên ngoài.

```cpp
class SinhVien
{
    private:
        string name;    // tính đóng gói
        int age;        // tính đóng gói
        int id;         // tính đóng gói
}
```

#### 2. Tính trừu tượng: 

- Tính trừu tượng là ẩn đi các hàm khỏi người dùng. Nghĩa là khai báo các hàm ở quyền truy cập private hoặc protected, không thể truy cập chúng từ các object bên ngoài.

```cpp
class SinhVien
{
    private:
       /* Tính trừu tượng: khai báo, định nghĩa hàm ở cấp private*/
        // Hàm kiểm tra xem tên có hợp lệ không
        bool checkName(string str)
        {
            for (int i = 0; i < str.length(); i++)
            {
                char c = str[i];
                if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == ' ')))
                {
                    return false;
                }
            }
            return true;
        }

        // Hàm kiểm tra xem tuổi có hợp lệ không
        bool checkAge(int age)
        {
            if (age <= 0) return false;
            return true;
        }
}
```

- Hàm setter dùng để cài dữ liệu, còn hàm getter dùng để lấy dữ liệu.

```cpp
class SinhVien
{
    private:
        string name;
        int age;
        int id;

    public:
        // Constructor
        SinhVien()
        {
            static int _id = 1;
            id = _id;
            _id++;
        }

        // setter
        void setName(string newName)
        {
            if (checkName(newName))
            {
                name = newName;
            }
            else
            {
                cout << "Unvalid name !" << endl;
                name = "";
            }
        }

        // setter: đặt dữ liệu
        void setAge(int newAge)
        {
            if (checkAge(newAge))
            {
                age = newAge;
            }
            else
            {
                cout << "Unvalid age !" << endl;
                age = 0;
            }
        }

        // getter: lấy dữ liệu
        string getName()
        {
            return name;
        }

        // Hàm hiển thị
        void display()
        {
            cout << "Tên: " << getName << endl;
            cout << "Tuổi: " << age << endl;
            cout << "MSV: " << id << endl;
        }
};
```

#### 3. Tính kế thừa: 

- Một class có thể sử dụng lại những property hay method được khai báo trong những class khác.
- Chỉ có thể kế thừa được những property và method ở cấp độ public, protected trong base class còn private thì không thể kế thừa.
- Cú pháp:
  - `class derivedclass : public baseclass`
- Có 3 kiểu kế thừa:
  - public, private và protected.
 
> 👉 Tính kế thừa kiểu public:
> - không thể truy cập từ ngoài class, phải truy cập thông qua trung gian ở cấp độ public.
> - truy cập bên trong base class và derived class.


[🔼 _UP_](#top)

</details>


