# Access modifier

## Phạm vi truy xuất

Access modifier trong C++  được sử dụng để triển khai một tính năng quan trọng của lập trình hướng đối tượng được gọi là Data Hiding.

Chúng ta cùng xem xét một ví dụ sau:

Giả sử công ty của chúng ta có lưu trữ thông tin của nhân viên như số điện thoai, email, năm sinh, phòng ban, chức vụ, địa điểm văn phòng làm việc,... Tất cả nhân viên của công ty có thể thấy các thông tin của nhau để tiện liên lạc thông qua trang web và có tài khoản để đăng nhập.

Người ở ngoài công ty thì không có tài khoản và không thể truy cập vào trang web để thấy thông tin của nhân viên trong công ty. Chúng ta gọi đó là hidding data.

Access modifier hay Access Specifier trong một lớp được sử dụng để đặt khả năng truy cập của các thành viên lớp. Đó là, nó đặt ra một số hạn chế đối với các thành viên lớp không được truy cập trực tiếp bởi các hàm bên ngoài.

Trong C++ có hổ trợ 3 loại access modifier đó là:

* Private
* Public
* Protected

**Lưu ý**: Nếu chúng ta không chỉ rõ bất kỳ access modifier cho thành viên của lớp, thì mặc định nó là Private.

## Private access modifier

Các thành viên lớp được khai báo là private thì chỉ có thể được truy cập bởi các hàm bên trong lớp. Chúng không được phép truy cập trực tiếp bởi bất kỳ đối tượng hoặc hàm nào bên ngoài lớp.

Chỉ các hàm thành viên hoặc các hàm bạn mới được phép truy cập các thành viên dữ liệu riêng tư của một lớp.

Private Access modifier cũng là access modifier mặc định của lớp.

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;

class HinhTron
{
private:
    double banKinh;

public:
    double TinhDienTich()
    {
        return 3.14 * banKinh * banKinh;
    }
};

int main()
{
    HinhTron ht;
    // Thử truy cập dữ liệu thành viên private bên ngoài class
    ht.banKinh = 3.5;

    cout << "Dien tich cua hinh tron la:" << ht.TinhDienTich();

    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```html
error: 'double HinhTron::banKinh' is private within this context
     ht.banKinh = 3.5;
note: declared private here
         double banKinh;
```

Chương trình trên báo lỗi biên dịch vì chúng ta đang truy cập dữ liệu thành viên bán kính ở dạng private.

Tuy nhiên, chúng ta có thể truy cập gián tiếp các thành viên dữ liệu riêng tư của một lớp bằng cách sử dụng các hàm thành viên công khai của lớp.

Ví dụ

```cpp
#include <iostream>
using namespace std;

class HinhTron
{
private:
    double banKinh;

public:
    void TinhDienTich(double bk)
    {
        banKinh = bk;
        double dienTich = 3.14 * banKinh * banKinh;
        cout << "Ban kinh la: " << banKinh << endl;
        cout << "Dien tich la: " << dienTich << endl;
    }
};

int main()
{

    HinhTron ht;
    double banKinh = 2;
    ht.TinhDienTich(banKinh);

    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên là:

```cpp
Ban kinh la: 2
Dien tich la: 12.56
```

## Public access modifier

Tất cả các thành viên lớp được khai báo dưới dạng public sẽ có sẵn cho tất cả mọi người. Các thành viên dữ liệu và các hàm thành viên được khai báo public cũng có thể được truy cập bởi các lớp khác.

Các thành viên public của một lớp có thể được truy cập từ bất cứ đâu trong chương trình bằng cách sử dụng toán tử truy cập thành viên trực tiếp (`.`) với đối tượng của lớp đó.

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;

class HinhTron
{
public:
    double banKinh;
    double TinhDienTich()
    {
        return 3.14 * banKinh * banKinh;
    }
};

int main()
{
    HinhTron ht;
    ht.banKinh = 3.5;
    cout << "Ban kinh cua hinh tron la: " << ht.banKinh << endl;
    cout << "Dien tich cua hinh tron la:" << ht.TinhDienTich();

    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```html
Ban kinh cua hinh tron la: 3.5
Dien tich cua hinh tron la:38.465
```

Trong ví dụ trên, thành viên dữ liệu bán kính là công khai nên chúng ta được phép truy cập bên ngoài lớp.

## Protected access modifier

Protected access modifier tương tự như private access modifier, sự khác biệt là thành viên lớp được khai báo là Protected không thể truy cập bên ngoài lớp nhưng chúng có thể được truy cập bởi bất kỳ lớp con (lớp dẫn xuất) nào của lớp đó.

Ví dụ

```cpp
#include <iostream>
using namespace std;

// Lớp cha
class Cha
{
protected:
    string diaChi;
};

// Lớp con
class Con : public Cha
{
public:
    void ThietLapDiaChi(string dc)
    {
        diaChi = dc;
    }

    void HienThi()
    {
        cout << "Dia chi la: " << diaChi << endl;
    }
};

int main()
{
    Con cn;
    cn.ThietLapDiaChi("Dien Chau, Nghe An");
    cn.HienThi();
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Dia chi la: Dien Chau, Nghe An
```
