# Destructor

## Hàm hủy trong C++

Hàm hủy (Destructor) trong C++ ngược lại với hàm xây dựng, trong khi hàm xây dựng dùng để khởi tạo giá trị cho đối tượng thì hàm hủy dùng để hủy đối tượng.

Chỉ có duy nhất một hàm hủy trong một lớp. Hàm hủy tự động được gọi. Nếu như chúng ta không định nghĩa hàm hủy thì mặc định trình biên dịch sẽ tự tạo ra một hàm hủy mặc nhiên.

Cũng giống như hàm xây dựng, hàm hủy được định nghĩa có cùng tên với tên lớp, khôn có bất cứ kiểu gì trả về kể cả kiểu `void`, tuy nhiên phải có dấu `~` trước tên của hàm hủy.

Lưu ý: Hàm hủy (Destructor) không có bất cứ tham số nào

### Cú pháp

Cú pháp của hàm hủy (Destructor) trong C++ như sau:

```cpp
~TenLop() { };
```

Ví dụ cụ thể là lớp nhân viên, thì chúng ta sẽ tạo hàm hủy cho lớp nhân viên như sau:

```cpp
class NhanVien {  
   public:  
        ~NhanVien() { };
};
```

Chúng ta cùng xem xét một ví dụ đơn giản nhất về hàm hủy trong C++ như sau:

```cpp
#include <iostream>  
using namespace std;  
class NhanVien  {  
   public:  
        NhanVien() {
            cout << "Ham xay dung duoc goi" << endl;
        }
        ~NhanVien() {
            cout << "Ham huy duoc goi" << endl;
        }  
};  
int main() {  
    NhanVien n1;

    NhanVien n2;

    return 0;  
}
```

Kết quả:

```cpp
Ham xay dung duoc goi
Ham xay dung duoc goi
Ham huy duoc goi
Ham huy duoc goi
```

## Khi nào hàm hủy được gọi

Hàm hủy (Destructor) trong C++ được gọi tự động khi đối tượng đi ra khỏi phạm vi:

* Kết thúc một block
* Kết thúc hàm
* Kết thúc chương trình
* Toán tử delete được gọi

Có hai hạn chế khi sử dụng hàm hủy đó là:

* Chúng ta không thể lấy địa chỉ của nó
* Lớp con không có thừa kế hàm hủy từ lớp cha của nó

## So sánh hàm hủy với hàm xây dựng

**Giống nhau**:

* Cùng tên với tên lớp
* Không có bất kỳ kiểu gì trả về kể cả kiểu void
* Được gọi tự động
* Khi không khai báo thì trình biên dịch sẽ tự tạo cho hàm xây dựng và hàm hủy mặc nhiên

**Khác nhau**:
|Hàm xây dựng|Hàm hủy|
|-|-|
Mục đích của hàm xây dựng là khởi tạo giá trị cho đối tượng|Mục đích của hàm hủy hủy bỏ đối tượng
Có thể có tham số hoặc không có tham số: nếu hàm xây dựng có tham số thì gọi hàm xây dựng tham số, nếu hàm xây dựng không có tham số thì gọi là hàm xây dựng mặc nhiên|Hàm hủy không có tham số
Hàm xây dựng được gọi khi tạo đối tượng|Hàm hủy được gọi khi đối tượng ra khỏi phạm vi của nó hoặc dùng toán tử `delete`
Hàm xây dựng cùng tên với tên lớp|Hàm hủy cũng cùng tên với tên lớp tuy nhiên phải có dấu `~` trước tên
Có thể có nhiều hàm xây dựng trong một lớp|Chỉ có duy nhất một hàm hủy trong một lớp
Lớp con có thể thừa kế hàm xây dựng của lớp cha|Lớp con không thể thừa kế hàm xây dựng của lớp cha
