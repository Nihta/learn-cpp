# Inheritance

## Kế thừa

Một trong những đặc tính quan trọng nhất của OOP là kế thừa. Ưu điểm của đặc tính kế thừa: sử dụng lại các đoạn code đã có trong chương trình một cách hiệu quả.

Khi tạo một class, thay vì việc viết một class mới hoàn toàn, người lập trình viên có thể kế thừa một số thuộc tính và phương thức từ một class đã có trong project.

Class đã có trước đấy gọi là lớp cơ sở (Base Class), class kế thừa từ Base Class (hay superclass) gọi là lớp dẫn xuất (Derived Class).

Ví dụ:

```cpp
class Base {
    // Thành phần của lớp cơ sở
};

class Derived : [private/protected/public] Base {
    // Thành phần riêng của lớp dẫn xuất
};
```

## Phạm vi truy xuất

### Truy xuất theo chiều dọc

Nói về quyền truy xuất vào các thuộc tính và phương thức (với các kiểu private, protected và public) của lớp từ những vị trí khác nhau (như bên trong lớp, ở lớp con, hàm bạn, lớp bạn và bên ngoài lớp).

[Xem chi tiết](./Access-modifier.md)

### Truy xuất theo chiều ngang

Nói về sự truy xuất các thành phần của lớp cha thông qua lớp con từ thế giới bên ngoài, đây chính là những phạm vi đươc lớp con sử dụng khi kế thừa lớp cha.

```cpp
class Base
{
private:
    int Pri;

protected:
    int Pro;

public:
    int Pub;
};

class B : private Base
{
    // Private: Pri, Pro, Pub
};

class C : protected Base
{
    // Private: Pri
    // Protected: Pro, Pub
};

class D : public Base
{
    // Private: Pri
    // Protected: Pro
    // Public: Pub
};
```

> Sau khi đã chuyển đổi phạm vi tương ứng, các thuộc tính từ lớp cha (Base) bây giờ đã trở thành thuộc tính của lớp con (với các kiểu truy xuất mới) và ở bên ngoài sẽ truy xuất dựa trên sự thay đổi này.

## Đơn kế thừa

Đơn kế thừa là loại kế thừa dựa trên mối quan hệ 1 - 1. Một con chỉ có một cha.

Lưu ý:

- `constructor` sẽ được gọi từ lớp cha trước rồi đến lớp con.
- `destructor` sẽ được gọi từ lớp con rồi mới đến lớp cha.
