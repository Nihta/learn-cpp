# Struct

## Struct trong C++

Trong C++, các class và struct là các bản thiết kế được sử dụng để tạo ra thể hiện của một lớp. Struct được sử dụng cho các đối tượng nhẹ như hình chữ nhật, màu sắc, điểm, v.v.

Không giống như class, các struct trong C++ là kiểu giá trị hơn là kiểu tham chiếu. Nó rất hữu ích khi chúng ta có dữ liệu mà chúng ta không có ý định sửa đổi sau khi tạo struct.

Struct trong C++ là một tập hợp các loại dữ liệu khác nhau. Nó tương tự như lớp chứa các loại dữ liệu khác nhau.

## Cú pháp

```cpp
struct TenCauTruc  
{
   // Khai bao cac thanh vien
}
```

Như cú pháp khai báo `struct` ở trên thì ta có từ khóa `struct` và theo sau là tên của `struct`. Bên trong dấu ngoặc nhọn, chúng ta có thể khai báo các biến thành viên của các kiểu dữ liệu khác nhau như là `float`, `int`, `string`, `char`, ...

Ví dụ cụ thể chúng ta sẽ khai báo một `struct HocSinh` có 3 biến thành viên đó là `ten`, `mshs`, và `tuoi` như sau:

```cpp
struct HocSinh
{  
    char ten[50];  
    int mshs;  
    int tuoi;  
}
```

**Lưu ý**:

* Khi struct được khai báo, không được cấp phát bộ nhớ.

* Khi biến của struct được tạo, thì mới được cấp phát bộ nhớ.

## Cách tạo một thể hiện của struct

Trong C++ một thể hiện của struct có thể được tạo như sau:

```cpp
TenCauTruc tenBien;
```

Và ví dụ cụ thể là tạo một thể hiện của struct HocSinh ở trên là:

```cpp
HocSinh h;
```

Trong đó:

* `h` là thể hiện của struct HocSinh, hay còn được gọi là biến cấu trúc.

* Khi biến cấu trúc được tạo thì được cấp phát bộ nhớ

* Struct HocSinh chứa 1 biến kiểu `char` và 2 biến kiểu `int`. Do đó, bộ nhớ cho một biến `char` là 1 byte và hai `int` sẽ là 2 * 4 = 8. Tổng bộ nhớ bị chiếm bởi biến h là 9 byte.

## Cách truy cập biến cấu trúc

Biến của Struct có thể được truy cập bằng cách sử dụng thể hiện của struct theo sau bởi toán tử dot `.` và theo sau đó là trường của struct. Ví dụ như sau:

```cpp
h.mshs = 111243;
```

Trong câu lệnh trên, chúng ta đang truy cập vào trường `mshs` của struct HocSinh bằng cách sử dụng toán tử dot `.` và gán giá trị `111243` cho trường `mshc`.

Ví dụ

Chúng ta cùng xem xét một ví dụ đơn giản sau đây có sử dụng struct trong C++ để thiết lập một struct HinhChuNhat có hai dữ liệu thành viên đó là chieuDai và chieuRong.

Ví dụ

```cpp
#include <iostream>
using namespace std;
struct HinhChuNhat
{
   int chieuDai;
   int chieuRong;
};

int main() {
    struct HinhChuNhat hcn;
    hcn.chieuDai = 2;
    hcn.chieuRong = 4;
    cout << "Dien tich hinh chu nhat la: " << (hcn.chieuDai * hcn.chieuRong) << endl;
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Dien tich hinh chu nhat la: 8
```

Cũng tiếp tục ví dụ về tính diện tích của hình chử nhật trên nhưng chúng ta sẽ sử dụng hàm xây dựng để khởi tạo giá trị cho chiều dài, chiều rộng và dùng phương thức để tính toán diện tích hình chử nhật như sau:

```cpp
#include <iostream>
using namespace std;
struct HinhChuNhat
{
    int chieuDai;
    int chieuRong;
    HinhChuNhat(int ch, int cr) {
       chieuDai = ch;
       chieuRong = cr;
    }
    void TinhDienTich() {
       cout << "Dien tich hinh chu nhat la: " << (chieuDai * chieuRong) << endl;  
    }
};

int main(void) {
    struct HinhChuNhat hcn = HinhChuNhat(3,5);
    hcn.TinhDienTich();
    return 0;
}

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Dien tich hinh chu nhat la: 15
```

## So sánh struct với lớp

Chúng ta cùng xem xét điểm giống và khác nhau giữa struct và class trong C++ như sau:

**Giống nhau**:

* Bản thiết kế để tạo ra thể hiện.

* Chứa các dữ liệu khác nhau.

**Khác nhau**:

|Struct|Class|
|-----|-----|
Nếu chỉ định truy cập không được khai báo rõ ràng, thì theo mặc định truy cập sẽ được public.|Nếu chỉ định truy cập không được khai báo rõ ràng, thì theo mặc định truy cập sẽ được private.
|Cú pháp của struct:`cpp struct TenCauTruc{ }`| Cú pháp của class: `class TenLop { }`|
|Thể hiện của struct được gọi là "Biến cấu trúc".|Thể hiện của lớp được gọi là "Đối tượng của lớp".|
