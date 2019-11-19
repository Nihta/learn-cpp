# Destructor

## Destructor C++

Hàm hủy (Destructor) trong C++ ngược lại với constructor, trong khi constructor dùng để khởi tạo giá trị cho đối tượng thì destructor dùng để hủy đối tượng.

Chỉ có duy nhất một destructor trong một lớp. Nếu trong class không định nghĩa destructor, thì một destructor mặc nhiên không làm gì cả được phát sinh.

Cũng giống như constructor, destructor được định nghĩa có cùng tên với tên lớp, không có bất cứ kiểu gì trả về kể cả kiểu `void` và cũng không có bất kì tham số nào, tuy nhiên phải có dấu `~` trước tên của destructor.

**Cú pháp**:

```cpp
~className() {
    //
};
```

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
public:
    NhanVien()
    {
        cout << "Ham xay dung duoc goi" << endl;
    }
    ~NhanVien()
    {
        cout << "Ham huy duoc goi" << endl;
    }
};
int main()
{
    NhanVien n1;
    NhanVien n2;

    return 0;
}
```

**Kết quả**:

```cpp
Ham xay dung duoc goi
Ham xay dung duoc goi
Ham huy duoc goi
Ham huy duoc goi
```

**Destructor được gọi khi**:

- Toán tử delete được gọi
- Kết thúc một block
- Kết thúc hàm
- Kết thúc chương trình

**Hạn chế khi sử dụng destructor**:

- Chúng ta không thể lấy địa chỉ của nó
- Lớp con không có thừa kế destructor từ lớp cha của nó

## So sánh destructor với constructor

**Giống nhau**:

- Cùng tên với tên lớp
- Không có bất kỳ kiểu gì trả về kể cả kiểu `void`
- Được gọi tự động
- Khi không khai báo thì trình biên dịch sẽ tự tạo cho constructor và destructor mặc nhiên

**Khác nhau**:

|Constructor|Destructor|
|-----------|----------|
Mục đích của constructor là khởi tạo giá trị cho đối tượng|Mục đích của destructor hủy bỏ đối tượng
Có thể có tham số hoặc không có tham số: nếu constructor có tham số thì gọi constructor tham số, nếu constructor không có tham số thì gọi là constructor mặc nhiên|Destructor không có tham số
Constructor được gọi khi tạo đối tượng|Destructor được gọi khi đối tượng ra khỏi phạm vi của nó hoặc dùng toán tử `delete`
Constructor cùng tên với tên lớp|Destructor cũng cùng tên với tên lớp tuy nhiên phải có dấu `~` trước tên
Có thể có nhiều constructor trong một lớp|Chỉ có duy nhất một destructor trong một lớp
Lớp con có thể thừa kế constructor của lớp cha|Lớp con không thể thừa kế destructor của lớp cha
