# Copy Constructor

## Hàm xây dựng sao chép

Hàm xây dựng sao chép (Copy Constructor) trong C++ là một hàm xây dựng được sử dụng để khai báo và khởi tạo một đối tượng từ một đối tượng khác.

Trong C++ hổ trợ cho chúng ta hai loại hàm xây dựng sao chép đó là:

* Hàm xây dựng sao chép mặc nhiên: Nếu chúng ta không định nghĩa hàm xây dựng sao chép thì mặc nhiên trình biên dịch sẽ tự động tạo cho chúng ta một hàm xây dựng sao chép mặc nhiên.

* Hàm xây dựng sao chép do người dùng định nghĩa: Đây là hàm xây dựng do người dùng tự định nghĩa để sao chép từ một đối tượng đã có sẳn.

## Hàm xây dựng sao chép do người dùng định nghĩa

Khi gọi hàm xây dựng sao chép thì chúng ta sẽ ngầm hiểu nó là hàm xây dựng sao chép do người dụng định nghĩa.

### Cú pháp

Cú pháp của hàm xây dựng sao chép (Copy Constructor) trong C++ như sau:

```cpp
TenLop(const TenLop &doiTuongCu);
```

Ví dụ cụ thể:

```cpp
class NhanVien {  
   NhanVien(NhanVien &a) {  
   }  
};
```

Trong ví dụ trên thì hàm xây dựng sao chép có cách gọi như sau:

* NhanVien p2(p1);
* NhanVien p2 = p1;

Chúng ta cùng xem xét một ví dụ đơn giản về hàm xây dựng sao chép trong C++ như sau:

```cpp
#include <iostream>  
using namespace std;  
class NhanVien {
    int msnv;
    string ten;
    int tuoi;
    public:  
       NhanVien(int m, string tn, int t) {
            msnv = m;
            ten = tn;
            tuoi = t;
       }
       NhanVien(NhanVien &n) {
           msnv = n.msnv;
           ten = n.ten;
           tuoi = n.tuoi;
       }
       void HienThi() {
            cout << ten << endl;
            cout << "   Ma so nhan vien: " << msnv << endl;
            cout << "   Tuoi: " << tuoi << endl;
       }
};

int main() {  
    NhanVien n1(123, "Nguyen Van A", 25);
    NhanVien n2(n1);
    n1.HienThi();
    n2.HienThi();
    return 0;  
}
```

Kết quả:

```cpp
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
```

## Khi nào hàm xây dựng sao chép được gọi

Hàm xây dựng sao chép (Copy Constructor) trong C++ được gọi trong các trường hợp sau đây:

* Khi chúng ta khỏi tạo một đối tượng từ một đối tượng khác tồn tại có cùng class type. Ví dụ NhanVien p2 = p1, NhanVien là tên lớp.

* Khi đối tượng cùng class type được truyền bằng giá trị dưới dạng đối số.

* Khi hàm trả về đối tượng cùng class type theo giá trị.

## Loại copy được tạo bởi hàm xây dựng

Trong C++ có hai loại copy được tạo bởi hàm xây dựng đó là:

* Shallow cop
* Deep copy

### Shallow Copy

Hàm xây dựng sao chép mặc định chỉ có thể tạo shallow copy.

Shallow copy được định nghĩa là quá trình tạo bản sao của một đối tượng bằng cách sao chép dữ liệu của tất cả các biến thành viên

Để hiểu rõ hơn về shallow copy chúng ta cùng xem xét một ví dụ đơn giản sau đây:

```cpp
#include <iostream>  
using namespace std;

class TestShallowCopy {  
    int a;  
    int b;  
    int *p;  
    public:  
        TestShallowCopy() {  
            p = new int;  
        }  
        void TaoDuLieu(int x, int y, int z) {  
            a = x;  
            b = y;  
            *p = z;  
        }  
        void HienThi()  {  
            cout << "   Gia tri cua a la: " << a << std::endl;  
            cout << "   Gia tri cua b la: " << b << std::endl;  
            cout << "   Gia tri cua *p la: " << *p << std::endl;  
        }  
};

int main() {  
    TestShallowCopy t1;  
    t1.TaoDuLieu(2, 6, 8);

    TestShallowCopy t2 = t1;

    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.HienThi();

    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.HienThi();  
    return 0;  
}
```

Kết quả:

```cpp
Du lieu cua doi tuong t1:
   Gia tri cua a la: 2
   Gia tri cua b la: 6
   Gia tri cua *p la: 8
Du lieu cua doi tuong t2:
   Gia tri cua a la: 2
   Gia tri cua b la: 6
   Gia tri cua *p la: 8
```

Trong ví dụ trên, chúng ta không định nghĩa bất kỳ hàm xây dựng nào, do đó câu lệnh `TestShallowCopy t2 = t1` gọi hàm xây dựng mặc nhiên được tạo bởi trình biên dịch.

Hàm xây dựng mặc nhiên tạo shallow coppy của đối tượng tồn tại. Do đó, con trỏ `p` của cả hai đối tượng trỏ đến cùng một vị trí bộ nhớ. Vì vậy, khi bộ nhớ của một trường được giải phóng, bộ nhớ của một trường khác cũng được tự động giải phóng khi cả hai trường đều trỏ đến cùng một vị trí bộ nhớ.

Để giải quyết vấn đề trên chúng ta deep copy

## Deep copy

Deep copy tự động cấp phát bộ nhớ cho bản sao và sau đó sao chép giá trị thực cho bản sao, cả nguồn và bản sao có vị trí bộ nhớ khác nhau.

Theo cách này, cả nguồn và bản sao là khác nhau và sẽ không chia sẻ cùng một vị trí bộ nhớ. Deep copy yêu cầu chúng ta viết hàm xây dựng do người dùng định nghĩa.

Chúng ta tiếp xét tiếp ví dụ ở trên, tuy nhiên chúng ta sẽ tự định nghĩa hàm xây dựng sao chép như sau:

```cpp
#include <iostream>  
using namespace std;

class TestShallowCopy {  
    int a;  
    int b;  
    int *p;  
    public:
        TestShallowCopy() {  
            p = new int;
        }
        TestShallowCopy(TestShallowCopy &t) {
            a = t.a;
            b = t.b;
            p = new int;
            *p = *(t.p);
        }
        void TaoDuLieu(int x, int y, int z) {  
            a = x;
            b = y;
            *p = z;
        }
        void HienThi() {
            cout << "   Gia tri cua a la: " << a << endl;  
            cout << "   Gia tri cua b la: " << b << endl;  
            cout << "   Gia tri cua *p la: " << *p << endl;
        }
};

int main() {
    TestShallowCopy t1;
    t1.TaoDuLieu(2, 6, 8);
    TestShallowCopy t2 = t1;
    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.HienThi();
    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.HienThi();
    return 0;
}
```

Kết quả:

```cpp
Du lieu cua doi tuong t1:
   Gia tri cua a la: 2
   Gia tri cua b la: 6
   Gia tri cua *p la: 8
Du lieu cua doi tuong t2:
   Gia tri cua a la: 2
   Gia tri cua b la: 6
   Gia tri cua *p la: 8
```

Ở ví dụ trên, chúng ta tự định nghĩa hàm xây dựng sao chép, câu lệnh `TestShallowCopy t2 = t1` sẽ gọi hàm xây dựng sao chép do chúng ta định nghĩa.

> Một điểm lưu ý cho các bạn là khi chương trình chúng ta có dữ liệu thành viên là con trỏ, thì nên tự định nghĩa một hàm xây dựng sao chép để tránh những bất lợi của shallow copy đã đề cập ở trên nhé.
