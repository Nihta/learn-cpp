# Hàm bạn (Friend function) và lớp bạn (Friend Class)

## Hàm bạn trong C++

Nếu một hàm được định nghĩa là một hàm bạn (Friend function) trong C++, thì dữ liệu được bảo vệ (protected) và riêng tư (private) của một lớp có thể được truy cập bằng cách sử dụng hàm.

### Cú pháp

```cpp
class TenLop
{
    friend KieuDuLieu TenHam([Tham so]);
};
```

### Ví dụ

```cpp
#include <iostream>
using namespace std;
class HinhChuNhat {
    private:
        int chieuDai;
        int chieuRong;
    public:
        HinhChuNhat(int chieuDai, int chieuRong) {
            this->chieuDai = chieuDai;
            this->chieuRong = chieuRong;
        }
        HinhChuNhat(): chieuDai(0) { }
        // friend function
        friend int HienThiChieuDai(HinhChuNhat);
};

int HienThiChieuDai(HinhChuNhat hcn) {
    hcn.chieuDai += 10;
    return hcn.chieuDai;
}

int main() {
    HinhChuNhat hcn = HinhChuNhat(10, 20);
    cout << "Chieu dai cua hinh chu nhat la: " << HienThiChieuDai(hcn)<<endl;
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Chieu dai cua hinh chu nhat la: 20
```

```cpp
#include <iostream>  
using namespace std;  
class Lop2;
class Lop1 {  
    int a;  
    public:  
        void ThietLapGiaTriA(int a) {  
            this->a = a;  
        }
        void HienThi() {
            cout << "Lop 1, a = " << a << endl;
        }
        friend void TimGiaTriNhoNhat(Lop1, Lop2);
};

class Lop2 {  
    int b;  
    public:  
        void ThietLapGiaTriB(int b) {  
            this->b = b;  
        }
        void HienThi() {
            cout << "Lop 2, b = " << b << endl;
        }
        friend void TimGiaTriNhoNhat(Lop1, Lop2);
        };  
        void TimGiaTriNhoNhat(Lop1 l1, Lop2 l2) {
            cout << "Gia tri nho nhat trong 2 lop la: ";
            if(l1.a <= l2.b)  
                cout << l1.a << endl;  
            else
                cout << l2.b << endl;  
}
int main() {
    Lop1 l1;  
    Lop2 l2;  
    l1.ThietLapGiaTriA(7);  
    l2.ThietLapGiaTriB(9);
    l1.HienThi();
    l2.HienThi();
    TimGiaTriNhoNhat(l1, l2);  
    return 0;
}
 ```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Lop 1, a = 7
Lop 2, b = 9
Gia tri nho nhat trong 2 lop la: 7
```

Ở ví dụ trên hàm `TimGiaTriNhoNhat` là hàm bạn của cả hai lớp `Lop1` và `Lop2` vì vậy hàm `TimGiaTriNhoNhat` có thể truy cập dữ liệu thành viên private của cả hai lớp.

## Lớp bạn (Friend class)

Một lớp bạn (friend class) có thể truy cập cả các thành viên riêng tư và được bảo vệ của lớp mà nó đã được khai báo là friend.

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
    void HienThi(Lop1 &l1) {  
        cout << "Gia tri cua a la: "<< l1.a;  
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

Trong ví dụ trên, `Lop2` được khai báo là `friend` trong lớp `Lop1`. Do đó, `Lop2` là bạn của `Lop1`. `Lop2` có thể truy cập các thành viên private của `Lop1`.
