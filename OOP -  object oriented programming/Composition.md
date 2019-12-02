# Composition

## Composition (quan hệ hợp thành)

Sự hợp thành (composition) là quá trình xây dựng các đối tượng phức tạp dựa trên những đối tượng đơn giản.

Class trong C++ cũng được cấu thành từ các kiểu dữ liệu khác nhau bên trong (thuộc tính) nên được gọi là kiểu dữ liệu hỗn hợp.

Sự hợp thành còn có cách gọi khác như quan hệ bao hàm, quan hệ bộ phận - toàn thể hoặc quan hệ `has-a`. Laptop `has-a` keyboard, a car `has-a` steering wheel,…

## Điều kiện để trở thành composition

Một đối tượng hoặc một phần nào đó phải có mối quan hệ sau:

- Phải là một phần của đối tượng (thuộc class)
- Chỉ thuộc về đối tượng (thuộc class) tại 1 thời điểm
- Sự tồn tại của nó được quản lý bởi đối tượng (thuộc class)
- Không biết về sự tồn tại của đối tượng (thuộc class)

Ví dụ thực tế là quan hệ giữa con người và tim:

- Tim là một bộ phận của con người
- Tim được tạo ra khi cơ thể con người được tạo ra
- Khi cơ thể không hoạt động nữa -> tim cũng không hoạt động theo (death relationship)
- Cơ thể biết sự tồn tại của tim, nhưng tim không biết mình là 1 phần trong cấu trúc cơ thể

### Composition in class

Ví dụ về cách thiết kế lớp sử dụng composition:

```cpp
#include <iostream>
using namespace std;
class Point
{
private:
    int x;
    int y;

public:
    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    friend ostream &operator<<(ostream &out, const Point &p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

class straightParagraph
{
private:
    Point A;
    Point B;

public:
    straightParagraph(const Point &a, const Point &b) : A(a), B(b)
    {
    }

    friend ostream &operator<<(ostream &out, const straightParagraph &sP)
    {
        out << sP.A << "---" << sP.B;
        return out;
    }
};

int main()
{
    Point M(1, 2), N(3, 4);

    straightParagraph MN(M, N);
    cout << MN << endl;

    return 0;
}
```
