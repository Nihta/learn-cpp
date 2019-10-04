# Nạp chồng

## Overview

**Các toán tử có thể được nạp chồng**:

| | | | | | |
|-|-|-|-|-|-|
`+`|`-`|`*`|`/`|`%`|`^`
`&`|`|`|`~`|`!`|`,`|`=`
`<`|`>`|`<=`|`>=`|`++`|`--`
`<<`|`>>`|`==`|`!=`|`&&`|`||`
`+=`|`-=`|`/=`|`%=`|`^=`|`&=`
|`=`|`*=`|`<<=`|`>>=`|`[]`|`()`
`->`|`->*`|`new`|`new []`|`delete`|`delete []`

**Các toán tử không thể được nạp chồng**:

| | | | |
|-|-|-|-|
`::`|`.*`|`.`|`? :`

**Cách nạp chồng**:

|Dạng toán tử|Phương thức của lớp|Hàm toàn cục|
|--|--|--|
aa@bb|aa.operator@(bb)|operator@(aa,bb)
@aa|aa.operator@()|operator@(aa)
aa@|aa.operator@(int)|operator@(aa,int)

## Details

- [Toán tử một ngôi](#Nạp-chồng-toán-tử-đơn)
- [Toán tử đôi](#Nạp-chồng-toán-tử-đôi)
- [Toán tử quan hệ](#Nạp-chồng-toán-tử-quan-hệ)
- [Toán tử input/output](#Nạp-chồng-toán-tử-input/output)
- [Toán tử ++ và --](#Nạp-chồng-toán-tử-++-và---)
- [Toán tự gán](#Nạp-chồng-toán-tự-gán)
- [Toán tử gọi hàm ()](#Nạp-chồng-toán-tử-gọi-hàm-())
- [Toán tử []](#Nạp-chồng-toán-tử-[])
- [Toán tử truy cập thành viên lớp ->](#Nạp-chồng-toán-tử-truy-cập-thành-viên-lớp-`->`)

-----

## Nạp chồng toán tử đơn

Toán tử một ngôi (unary) trong c++ hoạt động trên một toán hạng đơn:

- Nạp chồng toán tử tăng `++` và toán tử giảm `--`
- Toán tử một ngôi `-`
- Toán tử logic phủ định `!`

Toán tử một ngôi hoạt động trên đối tượng mà chúng được gọi, và thường thì toán tử này xuất hiện bên trái đối tượng, dạng như: `!obj`, `-obj`, và `++obj`, nhưng đôi khi chúng có thể sử dụng như là hậu tố giống như `obj++` hoặc `obj--`.

Ví dụ:

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }
    // Hiện thị phân số
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }
    // Cộng hai phân số
    Fraction operator+(Fraction b)
    {
        Fraction res;
        res.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
        res.denominator = this->denominator * b.denominator;
        return res;
    }

    // Phương thức của lớp
    Fraction operator-()
    {
        if (this->denominator < 0)
            this->denominator *= -1;
        else
            this->numerator *= -1;
        return *this;
    }

    // friend Fraction operator-(Fraction &X);
};

/* Hàm toàn cục
Fraction operator-(Fraction &X)
{
    if (X.denominator < 0)
        X.denominator *= -1;
    else
        X.numerator *= -1;
    return X;
}
*/

int main()
{
    Fraction a(1, 1), b(1, 2);
    -b;
    b.display(); // -1/2

    Fraction res = a + -b; // 1 + 1/2
    res.display();
    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử đôi

- Toán tử cộng `+`, trừ `-`, nhân `*` toán tử chia `/`.

Ví dụ sau giải thích cách toán tử cộng `+` có thể được nạp chồng trong C++:

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }

    // Phương thức của lớp
    Fraction operator+(Fraction b)
    {
        Fraction res;
        res.numerator = this->numerator * b.denominator + b.numerator * this->denominator;
        res.denominator = this->denominator * b.denominator;
        return res;
    }

    // friend Fraction operator+(Fraction a, Fraction b);
    void display();
};

void Fraction::display()
{
    cout << this->numerator << "/" << this->denominator << endl;
}

/* Hàm toàn cục
Fraction operator+(Fraction a, Fraction b)
{
    Fraction res;
    res.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    res.denominator = a.denominator * b.denominator;
    return res;
}
*/

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    Fraction sum = a + b;
    sum.display();

    return 0;
}

```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử quan hệ

Có nhiều toán tử quan hệ như `<`, `>`, `<=`, `>=`, `==`, ...

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }
    // Hiện thị phân số
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    // Phương thức lớp
    bool operator>(Fraction b)
    {
        return this->numerator * b.denominator > b.numerator * this->denominator;
    }

    // friend bool operator>(Fraction a, Fraction b);
};

/* Hàm toàn cục
bool operator>(Fraction a, Fraction b)
{
    return a.numerator*b.denominator > b.numerator * a.denominator;
}
*/

int main()
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    if (a > b)
        cout << "Phan so a lon hon phan so b";
    else
        cout << "Phan so b lon hon phan so a";

    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử input/output

C++ có thể input và output các kiểu dữ liệu có sẵn bởi sử dụng toán tử trích luồng `>>` và toán tử chèn luồng `<<`. Các toán tử trích luồng và chèn luồng cũng có thể được nạp chồng để thực hiện input và output cho các kiểu tự định nghĩa (user-defined).

Chúng ta sử dụng hàm `friend` mà không phải hàm của phương thức là vì bên trái toán tử là `cin` rồi đến toán tử `>>` rồi đến class cần xử lí. Loại này có dạng `aa@bb` Tuy nhiên `aa` trong bảng [trên](#Overview) là đối tượng của class hiện tại, mà `cin` hay `cout` là không thuộc class hiện tại, nên không thể khai báo hàm của phương thức. Nên buộc tại đây chúng ta sử dụng `friend`.

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }

    friend ostream &operator<<(ostream &output, const Fraction &X);

    friend istream &operator>>(istream &input, Fraction &X);
};

ostream &operator<<(ostream &output, const Fraction &X)
{
    output << X.numerator << "/" << X.denominator;
    return output;
}

istream &operator>>(istream &input, Fraction &X)
{
    char tmp;
    input >> X.numerator >> tmp >> X.denominator;
    return input;
}

int main()
{
    Fraction a;
    cout << "Nhap phan so (dang a/b): ";
    cin >> a;
    cout << "Phan so vua nhap la: " << a;

    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử ++ và --

**Nạp chồng phương thức lớp**:

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }
    // Hiện thị phân số
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    // ++ Tiền tố
    Fraction operator++()
    {
        this->numerator += 1;
        this->denominator += 1;
        return *this;
    }

    // ++ Hậu tố
    // int ở đâu là cú pháp để phân biệt tiền tố và hậu tố, không liên quan gì đến kiểu dữ liệu
    Fraction operator++(int)
    {
        Fraction dataOld = *this;
       this->numerator += 1;
       this->denominator += 1;
        return dataOld;
    }
};

int main()
{
    Fraction a(1, 1), b(1, 1);

    // Test tiền tố
    (++a).display(); //    2/2
    a.display();     //    2/2

    // Test hậu tố
    (b++).display(); //    1/1
    b.display();     //    2/2
    return 0;
}
```

**Nạp chồng hàm toàn cục**:

```cpp
// ++ Tiền tố
Fraction operator++(Fraction &X)
{
    X.numerator += 1;
    X.denominator += 1;
    return X;
}

// ++ Hậu tố
Fraction operator++(Fraction &X, int)
{
    Fraction dataOld = X;
    X.numerator += 1;
    X.denominator += 1;
    return dataOld;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tự gán

Bạn có thể nạp chồng toán tử gán `=` như khi bạn có thể với các toán tử khác trong C++ và nó có thể được sử dụng để tạo một đối tượng giống như copy constructor.

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }
    // Hiện thị phân số
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    friend void operator=(const Fraction &b)
    {
        this->numerator = X.numerator;
        this->denominator = X.denominator;
    }
};

int main()
{
    Fraction a(3, 4), b = a;
    b.display();
    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử gọi hàm ()

Toán tử gọi hàm `()` trong C++ có thể được nạp chồng cho các đối tượng của kiểu lớp.

Khi nạp chồng `()`, ta không tạo một cách mới để gọi một hàm mà là tạo một hàm toán tử mà có thể được truyền số tham số tùy ý.

```cpp
#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    // Copy constructor
    Fraction(const Fraction &x)
    {
        this->numerator = x.numerator;
        this->denominator = x.denominator;
    }
    // Hiện thị phân số
    void display()
    {
        cout << this->numerator << "/" << this->denominator << endl;
    }

    // Phương thức lớp
    Fraction operator()(int x, int y, int z)
    {
        Fraction res;
        res.numerator = x * z + y;
        res.denominator = z;
        return res;
    }
};

int main()
{
    Fraction a(1, 2), b;
    a.display();
    b = a(1,2,3);
    a.display();
    b.display();
    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử []

Toán tử subscript `[]` trong C++ thường được sử dụng để truy cập các phần tử mảng. Toán tử này có thể được nạp chồng để nâng cao tính năng đang tồn tại về mảng trong C++ (do vậy, có thể gọi là toán tử chỉ số mảng).

```cpp
#include <iostream>
using namespace std;
const int MAX = 15;

class ViDuMang {
    private:
        int mang[MAX];
    public:
        ViDuMang() {
            register int i;
            for(i = 0; i < MAX; i++)
                mang[i] = i;
        }

        int &operator[](int i) {
            if(i > MAX) {
                cout << "Chi muc vuot gioi han!" <<endl;
                // Tra ve phan tu dau tien.
                return mang[0];
            }
            return mang[i];
        }
};

int main() {
    ViDuMang V;

    cout << "Gia tri cua V[3] la: " << V[3] <<endl;
    cout << "Gia tri cua V[6] la: " << V[6]<<endl;
    cout << "Gia tri cua V[16] la: " << V[16]<<endl;

    return 0;
}
```

[^ Back to top ^](#Details)

-----

## Nạp chồng toán tử truy cập thành viên lớp `->`

Toán tử truy cập thành viên lớp `->` có thể được nạp chồng, nhưng nó khá là phức tạp. Nó được định nghĩa để cung cấp một kiểu lớp một hành vi "pointer-like". Toán tử `->` phải là một hàm thành viên. Nếu được sử dụng, kiểu trả về của nó phải là một con trỏ hoặc một đối tượng của một lớp để bạn có thể áp dụng.

Toán tử `->` thường được sử dụng kết hợp với toán tử `*` để triển khai "smart pointer". Những con trỏ này là các đối tượng mà vận hành như các con trỏ thông thường, ngoại trừ việc chúng thực hiện các tác vụ khi bạn truy cập một đối tượng thông qua chúng, ví dụ: xóa đối tượng tự động hoặc khi con trỏ bị hủy hoặc khi con trỏ được sử dụng để trỏ tới đối tượng khác.

Toán tử -> có thể được định nghĩa như là một toán tử hậu tố một ngôi.

```cpp
class Ptr {
   //...
   X * operator->();
};
```

Các đối tượng của lớp `Ptr` có thể được sử dụng để truy cập các thành viên của lớp `X` ở trên theo phương thức giống như cách các con trỏ được sử dụng. Ví dụ:

```cpp
void f(Ptr p ) {
   p->m = 10 ; // la tuong tu (p.operator->())->m = 10
}
```

Lệnh `p->m` được thông dịch thành `(p.operator->())->m`. Sử dụng cùng khái niệm trên, ví dụ sau sẽ giải thích cách một toán tử truy cập lớp `->` trong C++ có thể được nạp chồng.

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Nihta {
    static int i, j;
    public:
        // Các smart pointer để hiện thị
        void f() const { cout << i++ << endl; }
        void g() const { cout << j++ << endl; }
        void h() const { cout << "--------" << endl; }
        };

        // Phần định nghĩa các thành viên Static:
        int Nihta::i = 4;
        int Nihta::j = 15;

        // Triển khai một container cho lớp trên
        class NiContainer {
            vector<Nihta*> a;
            public:
                void add(Nihta* vj) {
                    a.push_back(vj);
                }
            friend class SmartPointer;
        };

        // Triển khai smart pointer để truy cập thành viên của lớp Nihta.
        class SmartPointer {
            NiContainer vc;
            int index;
            public:
                SmartPointer(NiContainer& nic) {
                    vc = nic;
                    index = 0;
                }
                // Trả về giá trị để chỉ phần cuối của danh sách:
                bool operator++() {
                    if(index >= vc.a.size()) return false;
                    if(vc.a[++index] == 0) return false;
                    return true;
                }

                bool operator++(int) {
                    return operator++();
                }

                // Nạp chồng operator->
                Nihta* operator->() const {
                    if (!vc.a[index]) {
                        cout << "Gia tri 0!!";
                        return (Nihta*)0;
                    }
                    return vc.a[index];
                }
};

int main() {
    const int sz = 5;
    Nihta o[sz];
    NiContainer vc;

    for (int i = 0; i < sz; i++)
        vc.add(&o[i]);

    SmartPointer sp(vc); // Tạo một iterator
    do {
        sp->f(); // Gọi smart pointer
        sp->g();
        sp->h();
    } while(sp++);

    return 0;
}
```

[^ Back to top ^](#Details)

-----
