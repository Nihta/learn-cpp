# This

## Con trỏ this trong C++

This là một con trỏ đặc biệt dùng để trỏ đến địa chỉ của đối tượng hiện tại. Như vậy để truy cập đến các thuộc tính, phương thức của đối tượng hiện tại thì ta sẽ sử dụng con trỏ `this`.

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
    int maSo;
    string ten;
    int tuoi;

public:
    void setData(int maSo, string ten, int tuoi)
    {
        this->maSo = maSo;
        this->ten = ten;
        this->tuoi = tuoi;
    }
    void showData()
    {
        cout << "Ten nhan vien: " << this->ten << endl;
        cout << "Ma so nhan vien: " << this->maSo << endl;
        cout << "Tuoi: " << this->tuoi << endl;
    }
};
```

Class `NhanVien` có ba thuộc tính để lưu trữ thông tin của một nhân viên đó là: `manv`, `ten`, `tuoi`. Ngoài ra còn có phương thức `setData()` dùng để gán dữ liệu, và `showData()` dùng để hiển thị dữ liệu.

Trong phương thức `setData()` mình đã sử dụng từ khóa `this->ten_thuoc_tinh` để thực hiện phép gán dữ liệu cho các thuộc tính, còn ở phương thức `showData()` mình cũng sử dụng cú pháp tương tự để hiển thị dữ liệu của các thuộc tính. Như vậy công dụng của từ khóa `this` chính là một con trỏ và trỏ đến địa chỉ của đối tượng hiện tại.

Câu hỏi đặt ra là đối tượng hiện tại tại là gì? Để hiểu rõ hơn thì hãy xem đoạn code sử dụng class trên như sau:

```cpp
int main()
{
    // Nhan vien 1
    NhanVien n1 =  NhanVien();
    n1.setData(123, "Nguyen Van A", 24);
    n1.showData();

    // Nhan vien 2
    NhanVien n2 =  NhanVien();
    n2.setData(234, "Nguyen Van B", 25);
    n2.showData();

    return 0;
}
```

Trong ví dụ này mình đã tạo ra hai đối tượng sinh viên đó là `n1` và `n2`, và con trỏ `this` của `n1` sẽ trỏ đến chính đối tượng `n1`, con trỏ `this` của `n2` sẽ trỏ đến chính đối tượng `n2`, đây ta gọi là đối tượng hiện tại.

Trong các phương thức bình thường (không phải hàm khởi tạo) nếu bạn sử dụng tên của biến thì sẽ có hai trường hợp xảy ra:

* Nếu biến đó không tồn tại trong phương thức mà nó lại trùng với tên thuộc tính thì mặc nhiên nó sẽ hiểu đó là thuộc tính.

* Nếu biến đó có khai báo trong phương thức thì ta sẽ hiểu đó là biến bình thường, không phải là thuộc tính.

## Một ví dụ khác về con trỏ `this`

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
    int maSo;
    string ten;
    int tuoi;

public:
    NhanVien(int maSo, string ten, int tuoi)
    {
        cout << "Trong ham xay dung: " << endl;
        cout << "   maSo: " << maSo << endl;
        cout << "   ten: " << ten << endl;
        cout << "   Tuoi: " << tuoi << endl;
        maSo = maSo;
        ten = ten;
        tuoi = tuoi;
    }
    void HienThi()
    {
        cout << "Ham in thong tin cua doi tuong nhan vien: " << endl;
        cout << ten << endl;
        cout << "   Ma so nhan vien: " << maSo << endl;
        cout << "   Tuoi: " << tuoi << endl;
    }
};

int main()
{
    NhanVien n1 = NhanVien(123, "Nguyen Van A", 25);
    n1.HienThi();

    return 0;
}
```

**Kết quả**:

```cpp
Trong ham xay dung:
   maSo: 123
   ten: Nguyen Van A
   Tuoi: 25
Ham in thong tin cua doi tuong nhan vien:

   Ma so nhan vien: 4199120
   Tuoi: 1986841792
```

Đây là một kết quả mà chúng ta không hề mong đợi đúng không?

* Khi chúng ta khai báo tên của tham số hàm trùng tên với dữ liệu thành viên của lớp, thì bên trong hàm xây dựng chương trình hiểu là biến tham số chứ không phải dữ liệu thành viên của lớp

* Như vậy ở ví dụ trên, bên trong thân hàm xây dựng ta gán `maSo = maSo`, `ten = ten`, `tuoi = tuoi`, thì chương trình hiểu `mssv`, `ten`, `tuoi` chính là biến truyền vào từ hàm xây dựng, chính vì vậy nó không cập nhật vào các thuộc tính của đối tượng.

* Khi các dữ liệu thành viên như `maSo`, `ten`, `tuoi` không được khỏi tạo giá trị nó sẽ có giá trị tự động cho chương trình tạo ra mà chúng ta không hề biết trước.

Con trỏ `this` trong C++ giúp chúng ta giải quyết được vấn về trên. Chúng ta sẽ dùng con trỏ `this` trong ví dụ trên như sau:

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
    int maSo;
    string ten;
    int tuoi;

public:
    NhanVien(int maSo, string ten, int tuoi)
    {
        cout << "Trong ham xay dung: " << endl;
        cout << "   maSo: " << maSo << endl;
        cout << "   ten: " << ten << endl;
        cout << "   Tuoi: " << tuoi << endl;
        this->maSo = maSo;
        this->ten = ten;
        this->tuoi = tuoi;
    }
    void HienThi()
    {
        cout << "Ham in thong tin cua doi tuong nhan vien: " << endl;
        cout << ten << endl;
        cout << "   Ma so nhan vien: " << maSo << endl;
        cout << "   Tuoi: " << tuoi << endl;
    }
};

int main()
{
    NhanVien n1 = NhanVien(123, "Nguyen Van A", 25);
    n1.HienThi();
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Trong ham xay dung:
   maSo: 123
   ten: Nguyen Van A
   Tuoi: 25
Ham in thong tin cua doi tuong nhan vien:
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
```

Kết quả trên đúng như kết quả của chúng ta mong đợi rồi nhé.

Như vậy con trỏ `this` trong C++ dùng để tham chiếu đến thể hiện hiện tại của lớp. Con trỏ `this` có thể sử dụng trong 3 cách như sau:

* Nó có thể được sử dụng để truyền đối tượng hiện tại làm tham số cho phương thức khác.

* Nó có thể được sử dụng để tham chiếu đến thể hiện hiện tại của lớp (như ở ví dụ trên).

* Nó có thể được sử dụng để khai báo các chỉ mục.

## Thêm một vài ví dụ với `this`

Ví dụ 1: Sử dụng con trỏ `this` trong trường hợp tên của tham số trùng tên với dữ liệu thành viên như sau:

```cpp
#include <iostream>
using namespace std;

class TestPointer
{
private:
    int a;
    int b;

public:
    void ThietLapGiaTri(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void HienThi()
    {
        cout << "Gia tri cua a: " << a << endl;
        cout << "Gia tri cua b: " << b << endl;
    }
};

int main()
{
    TestPointer p;
    int a = 10;
    int b = 20;

    p.ThietLapGiaTri(a, b);
    p.HienThi();

    return 0;
}

```

**Kết quả**:

```cpp
Gia tri cua a: 10
Gia tri cua b: 20
```

Ví dụ 2: Sử dụng con trỏ để trả về tham chiếu cho đối tượng gọi

```cpp
#include <iostream>
using namespace std;

class TestPointer
{
private:
    int a;
    int b;

public:
    TestPointer(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    TestPointer &ThietLapGiaTriA(int x)
    {
        a = x;
        return *this;
    }
    TestPointer &ThietLapGiaTriB(int y)
    {
        b = y;
        return *this;
    }
    void HienThi()
    {
        cout << "   Gia tri a = " << a << endl;
        cout << "   Gia tri b = " << b << endl;
    }
};

int main()
{
    cout << "----------Thong tin doi tuong p-----------" << endl;
    TestPointer p(4, 8);
    p.HienThi();

    cout << "Thong tin doi tuong p sau khi thiet lap gia tri" << endl;
    p.ThietLapGiaTriA(10);
    p.ThietLapGiaTriB(20);
    //Hoac chung ta cung co the viet p.ThietLapGiaTriA(10).ThietLapGiaTriB(20);
    p.HienThi();

    cout << endl
         << "----------Thong tin doi tuong p2-----------" << endl;
    TestPointer p2(4, 5);
    p2.HienThi();
    p2.ThietLapGiaTriA(55).ThietLapGiaTriB(67);

    cout << "Thong tin doi tuong p2 sau khi thiet lap gia tri" << endl;
    p2.HienThi();

    return 0;
}
```

**Kết quả**:

```cpp
----------Thong tin doi tuong p-----------
   Gia tri a = 4
   Gia tri b = 8
Thong tin doi tuong p sau khi thiet lap gia tri
   Gia tri a = 10
   Gia tri b = 20

----------Thong tin doi tuong p2-----------
   Gia tri a = 4
   Gia tri b = 5
Thong tin doi tuong p2 sau khi thiet lap gia tri
   Gia tri a = 55
   Gia tri b = 67
```
