# Constructor

## Constructor C++

Trong C++, hàm xây dựng (constructor) là một phương thức đặc biệt được gọi tự động tại thời điểm đối tượng được tạo.

Mục đích của hàm xây dựng là để khởi tạo các thành viên dữ liệu của đối tượng.

Hàm xây đựng phải cùng tên với tên lớp và không có bất cứ kiểu gì trả về kể cả kiểu `void`.

Ví dụ

```cpp
class HocSinh {
    int maSo;
    string ten;
    public:
        HocSinh();
        HocSinh(int m) {
            maSo = m;
        }
        HocSinh(string t) {
            ten = t;
        }
        HocSinh(int m, string t) {
            maSo = m;
            ten = t;
        }
};
```

Từ chương trình trên ta thấy, chúng ta có thể tạo hàm xây dựng có tham số hoặc không có tham số đều được.

Trong C++ hàm xây dựng không có tham được gọi là hàm xây dựng mặc nhiên ([Default constructor](#Hàm-xây-dựng-mặc-nhiên)), hàm xây dựng có tham số được gọi là hàm xây dựng tham số ([Parameterized constructor](#Hàm-xây-dựng-tham-số)).

## Hàm xây dựng mặc nhiên

Default constructor là hàm xây dựng không có tham số. Nó sẽ tự động được gọi tại thời điểm đối tượng được tạo.

Nếu trong class không có hàm xây dựng nào thì chương trình dịch sẽ tạo cho class đó một default constructor. Hàm này thực chất không làm gì cả.

Như vậy một đối tượng tạo ra chỉ được cấp phát bộ nhớ, còn các thuộc tính của nó chưa được xác định (nhận giá trị rác).

> Nếu trong class đã có ít nhất một hàm tạo, thì hàm tạo mặc định sẽ không được phát sinh nữa.

Ví dụ:

```cpp
#include <iostream>
using namespace std;
class NhanVien {
   public:
        NhanVien() {
            cout << "Ham xay dung mac nhien tu dong duoc goi." << endl;
        }
};

int main() {
    NhanVien e1; // Khoi tao doi tuong nhan vien 1
    NhanVien e2; // Khoi tao doi tuong nhan vien 2
    return 0;
}
```

Kết quả:

```cpp
Ham xay dung mac nhien tu dong duoc goi.
Ham xay dung mac nhien tu dong duoc goi.
```

-----

## Hàm xây dựng tham số

Một hàm xây dựng có tham số được gọi là Parameterized constructor.

Mục đích của hàm xây dựng tham số là để cung cấp các giá trị khác nhau cho các đối tượng riêng biệt.

Ví dụ:

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
    int maSo;
    string ten;
    int tuoi;

public:
    NhanVien(int m)
    {
        maSo = m;
    }
    NhanVien(int m, string tn)
    {
        maSo = m;
        ten = tn;
        tuoi = 20;
    }
    NhanVien(int m, string tn, int t)
    {
        maSo = m;
        ten = tn;
        tuoi = t;
    }
    void HienThi()
    {
        cout << ten << endl;
        cout << "   Ma so nhan vien: " << maSo << endl;
        cout << "   Tuoi: " << tuoi << endl;
    }
};

int main()
{
    NhanVien n1 = NhanVien(123, "Nguyen Van A", 25);
    NhanVien n2 = NhanVien(234, "Nguyen Van B");
    n1.HienThi();
    n2.HienThi();
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
Nguyen Van B
   Ma so nhan vien: 234
   Tuoi: 20
```

-----

## Lưu ý

* Khi chúng ta không định nghĩa hàm xây dựng thì mặc nhiên chương trình sẽ tạo cho lớp đó một hàm xây dựng mặc nhiên. Chúng ta chỉ có 1 cách để khởi tạo đối tượng duy nhất đó là className a, className b, ...

* Khi chúng ta định nghĩa hàm xây dựng kể cả mặc nhiên hay tham số thì số cách để tạo đối tương đúng bằng số hàm xây dựng mà chúng ta đã định nghĩa.

* Khi chúng ta khai báo đối tượng không khớp với bất kỳ hàm xây dựng nào mà chúng ta đã định nghĩa thì chương trình chúng ta sẽ báo lỗi.

* Tránh khai báo nhiều hàm xây dựng vô nghĩa mà chúng ta không sử dụng để khởi tạo đối tượng.

* Mục đích chính của hàm xây dựng là dùng để khởi tạo giá trị cho đối tượng, tuy nhiên chúng ta có thể sử dụng hàm xây dựng theo mục đích của riêng mình.
