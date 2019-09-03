# Từ khóa static

## Từ khóa static trong C++

Xem ví dụ sau đây:

Giả sử chúng ta có lớp nhân viên có 3 thuộc tính đó là msnv, tên, tuổi được tổ chức thành lớp trong C++ như sau:

```cpp
#include <iostream>  
using namespace std;  
class NhanVien {
    int msnv;
    string ten;
    int tuoi;
    string tenCongTy;
    public:  
       NhanVien(int msnv, string ten, int tuoi, string tenCongTy) {
            this->msnv = msnv;
            this->ten = ten;
            this->tuoi = tuoi;
            this->tenCongTy = tenCongTy;
        }
        void HienThi() {
            cout << ten << endl;
            cout << "   Ma so nhan vien: " << msnv << endl;
            cout << "   Tuoi: " << tuoi << endl;
            cout << "   Ten cong ty: " << tenCongTy << endl;
        }
};

int main() {  
    NhanVien n1 =  NhanVien(123, "Nguyen Van A", 25, "Google");
    NhanVien n2 =  NhanVien(234, "Nguyen Van B", 40, "Google");
    NhanVien n3 =  NhanVien(345, "Nguyen Van C", 67, "Google");
    n1.HienThi();
    n2.HienThi();
    n3.HienThi();
    return 0;  
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
   Ten cong ty: Google
Nguyen Van B
   Ma so nhan vien: 234
   Tuoi: 40
   Ten cong ty: Google
Nguyen Van C
   Ma so nhan vien: 345
   Tuoi: 67
   Ten cong ty: Google
```

Như vậy dữ liệu thành viên của mỗi đối tượng là khác nhau trong bộ nhớ, mỗi đối tượng độc lập dữ liệu với nhau.

Giả sử có 1000 nhân viên làm chung một công ty, thì phải cấp phát 1000 ô nhớ lưu trữ tên của công tý, điều này gây ra lãng phí bộ nhớ.

Trong C++ có hổ trợ cho chúng ta từ khóa `static`, giúp giải quyết được vấn đề trên. Chúng ta chỉ cần khai báo `tenCongTy` là biến `static`, thì khi chạy chương trình chỉ có một biến `tenCongTy` được khỏi tạo, và các đối tượng cùng chia sẽ chung một biến `static` này.

Như vậy thành viên `static` thuộc vào lớp chứ không thuộc về thể hiện của lớp. Vì vậy, thể hiện của lớp không bắt buộc để truy cập các thành viên `static`.

Trong C++, `static` có thể là trường (field), phương thức (method), hàm xây dựng (constructor), lớp (class), thuộc tính (properties), toán tử (operator) và sự kiện (event).

## Static Field

Một field được khai báo là `static` được gọi là static field (còn được gọi là trường tĩnh). Các trường đối tượng bình thường khác sẽ được cấp phát bộ nhớ mỗi khi chúng ta tạo đối tượng, còn static field chỉ có một bản sao được tạo trong bộ nhớ. Nó được chia sẻ cho tất cả các đối tượng.

### Cú pháp

```cpp
static KieuDuLieu tenTruong;
```

### Khởi tạo giá trị

```cpp
KieuDuLieu TenLop::tenTruongStatic = Gia tri;
```

### Ví dụ

Ví dụ 1: Sử dụng từ khóa static cho tên công ty ở ví dụ ở trên như sau:

```cpp
#include <iostream>  
using namespace std;  
class NhanVien {
    int msnv;
    string ten;
    int tuoi;
    public:  
        static string tenCongTy;
        NhanVien(int msnv, string ten, int tuoi) {
            this->msnv = msnv;
            this->ten = ten;
            this->tuoi = tuoi;
        }
        void HienThi() {
            cout << ten << endl;
            cout << "   Ma so nhan vien: " << msnv << endl;
            cout << "   Tuoi: " << tuoi << endl;
            cout << "   Ten cong ty: " << tenCongTy << endl;
        }
};  

string NhanVien::tenCongTy = "Google";

int main() {  
    NhanVien n1 =  NhanVien(123, "Nguyen Van A", 25);
    NhanVien n2 =  NhanVien(234, "Nguyen Van B", 40);
    NhanVien n3 =  NhanVien(345, "Nguyen Van C", 67);
    n1.HienThi();
    n2.HienThi();
    n3.HienThi();
    return 0;  
}
```

Và kết quả sau thi thực thi chương trình trên như sau:

```cpp
Nguyen Van A
   Ma so nhan vien: 123
   Tuoi: 25
   Ten cong ty: Google
Nguyen Van B
   Ma so nhan vien: 234
   Tuoi: 40
   Ten cong ty: Google
Nguyen Van C
   Ma so nhan vien: 345
   Tuoi: 67
   Ten cong ty: Google
```

Ví dụ 2: Đếm số đối tượng được tạo

```cpp
#include <iostream>  
using namespace std;  
class NhanVien {
    int msnv;
    string ten;
    int tuoi;
    public:  
        static int dem;
        NhanVien(int msnv, string ten, int tuoi) {
            this->msnv = msnv;
            this->ten = ten;
            this->tuoi = tuoi;
            dem++;
        }
        void HienThi() {
           cout << "Co " << dem << " doi tuong duoc tao." << endl;
        }
};  

int NhanVien::dem = 0;

int main() {  
    NhanVien n1 =  NhanVien(123, "Nguyen Van A", 25);
    n1.HienThi();  
    NhanVien n2 =  NhanVien(234, "Nguyen Van B", 40);
    n2.HienThi();
    NhanVien n3 =  NhanVien(345, "Nguyen Van C", 67);
    n3.HienThi();
    return 0;  
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Co 1 doi tuong duoc tao.
Co 2 doi tuong duoc tao.
Co 3 doi tuong duoc tao.
```
