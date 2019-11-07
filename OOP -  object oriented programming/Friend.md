# Friend

## Hàm bạn trong C++

Nếu một hàm được định nghĩa là một hàm bạn (Friend function) trong C++, thì dữ liệu được bảo vệ (`protected`) và riêng tư (`private`) của một class có thể được truy cập bằng cách sử dụng hàm.

### Cú pháp

```cpp
class TenLop
{
    friend KieuDuLieu TenHam([Tham so]);
};
```

### Ví dụ 1

```cpp
#include <iostream>
using namespace std;
class Rectangle
{
private:
    int chieuDai;
    int chieuRong;

public:
    Rectangle(int chieuDai, int chieuRong)
    {
        this->chieuDai = chieuDai;
        this->chieuRong = chieuRong;
    }
    Rectangle() : chieuDai(0) {}
    // friend function
    friend int display(Rectangle);
};

int display(Rectangle x)
{
    x.chieuDai += 10;
    return x.chieuDai;
}

int main()
{
    Rectangle hcn = Rectangle(10, 20);
    cout << "Chieu dai cua hinh chu nhat la: " << display(hcn) << endl;
    return 0;
}
```

**Kết quả**:

```cpp
Chieu dai cua hinh chu nhat la: 20
```

### Ví dụ 2

```cpp
#include <iostream>
using namespace std;

class Lop2;

class Lop1
{
private:
    int a;

public:
    void setValue(int a)
    {
        this->a = a;
    }
    void display()
    {
        cout << "Lop 1, a = " << a << endl;
    }
    friend void findMin(Lop1, Lop2);
};

class Lop2
{
private:
    int b;

public:
    void setValue(int b)
    {
        this->b = b;
    }
    void display()
    {
        cout << "Lop 2, b = " << b << endl;
    }
    friend void findMin(Lop1, Lop2);
};

void findMin(Lop1 x, Lop2 y)
{
    cout << "Gia tri nho nhat trong 2 lop la: ";
    if (x.a <= y.b)
        cout << x.a << endl;
    else
        cout << y.b << endl;
}

int main()
{
    Lop1 l1;
    Lop2 l2;

    l1.setValue(7);
    l2.setValue(9);

    l1.display();
    l2.display();

    findMin(l1, l2);
    return 0;
}

 ```

**Kết quả**:

```cpp
Lop 1, a = 7
Lop 2, b = 9
Gia tri nho nhat trong 2 lop la: 7
```

Ở ví dụ trên hàm `TimGiaTriNhoNhat` là hàm bạn của cả hai lớp `Lop1` và `Lop2` vì vậy hàm `TimGiaTriNhoNhat` có thể truy cập dữ liệu thành viên private của cả hai lớp.

> Lưu ý: Phương thức của một class có thể là hàm bạn của một class khác.

-----

## Lớp bạn (Friend class)

Một lớp bạn (friend class) có thể truy cập cả các thành viên `private` và `protected` của class mà nó đã được khai báo là `friend`.

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;
class Lop1 {
    int a = 10;
    friend class Lop2;
};
class Lop2 {
  public:
    void HienThi(Lop1 &x) {
        cout << "Gia tri cua a la: "<< x.a;
    }
};

int main() {
    Lop1 l1;
    Lop2 l2;
    l2.HienThi(l1);
    return 0;
}
```

**Kết quả**:

```cpp
Gia tri cua a la: 10
```

Trong ví dụ trên, `Lop2` được khai báo là `friend` trong lớp `Lop1`.

Do đó `Lop2` là bạn của `Lop1` và `Lop2` có thể truy cập các thành viên private của `Lop1`.
