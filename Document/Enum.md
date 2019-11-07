# Enum

## Enum C++

Enum trong C ++ là kiểu dữ liệu chứa các hằng số cố định.

Ví dụ chúng ta có thể được sử dụng enum cho các ngày trong tuần (sunday, monday, tuesday, wednesday, thursday, friday, và saturday), hướng (north, south, east và west), giới tính (male, female) v.v ...

Enum trong C++ có thể được coi là các lớp có tập hằng cố định.

### Cú pháp

```cpp
enum TenEnum {GiaTri1, GiaTri2, GiaTri3…..GiaTriN};
```

### Tạo biến kiểu enum

Trong C++ chúng ta có thể khai báo và khởi tạo giá trị cho biến kiểu `enum` cũng giống như cách khai báo và khởi tạo giá trị cho biến kiểu thông thường khác như kiểu `int`, `float`, `double` ...

```cpp
TenEnum TenBien = GiaTri;
```

### Điểm cần lưu ý cho enum trong C++

* Enum dễ dàng sử dụng trong cấu trúc điều khiển switch case

* Enum có thể có trường (field), hàm xây dựng (constructor) và phương thức (method)

* Enum có thể thực hiện nhiều interface nhưng không thể mở rộng bất kỳ lớp nào vì bên trong nó mở rộng lớp Enum

* Enum cải thiện type safety

* Enum có thể dễ dàng duyệt qua từng phần tử

#### Ví dụ

Xét một ví dụ đơn giản về kiểu dữ liệu enum được sử dụng trong chương trình C++ như sau:

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    enum GioiTinh { nam, nu };
    GioiTinh gt = nam;

    switch (gt) {
        case nam:
            cout << "Gioi tinh la nam" << endl;
            break;
        case nu:
            cout << "Gioi tinh la nam" << endl;
            break;
        default:
            cout << "Khong xac dinh ro gioi tinh" << endl;
    }
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```cpp
Gioi tinh la nam
```

Ví dụ 2: Tạo một enum năm và duyệt qua từng phần tử của enum như sau:

```cpp
#include <iostream>
using namespace std;

// Định nghĩa enum Nam
enum Nam {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    cout << "Gia tri cua cac phan tu cua enum Nam: " << endl;
    cout << "   ";
    //Duyet qua tung phan tu cua enum
    for (int i = January; i <= December; i++) {
        cout << i << " ";
    }
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```html
Gia tri cua cac phan tu cua enum Nam:
   0 1 2 3 4 5 6 7 8 9 10 11
```

**Lưu ý**:

* Giá trị của phần tử đầu tiên trong enum có giá trị bằng 0

* Giá trị của phần tử thứ 2 bằng phần tử thứ nhất cộng 1

* Giá trị của phần tử thứ 3 bằng phần tử thứ hai cộng 1

* Giá trị của phần tử thứ n bằng phần thử thứ n - 1 cộng thêm 1

Ví dụ sau đây chúng ta sẽ khởi tạo giá trị đầu tiên của enum Nam ở ví dụ trên bằng 1.

```cpp
#include <iostream>
using namespace std;

//Dinh nghia enum Nam
enum Nam {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    cout << "Gia tri cua cac phan tu cua enum Nam: " << endl;
    //Duyet qua tung phan tu cua enum
    for (int i = January; i <= December; i++) {
        cout << "   " << "Thang: " << i << endl;
    }
    return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```html
Gia tri cua cac phan tu cua enum Nam:
   Thang: 1
   Thang: 2
   Thang: 3
   Thang: 4
   Thang: 5
   Thang: 6
   Thang: 7
   Thang: 8
   Thang: 9
   Thang: 10
   Thang: 11
   Thang: 12
```

Ví dụ 3: Ví dụ sau đây sẽ cho chúng ta thay đổi giá trị mặc định của enum trong C++.

```cpp
#include <iostream>
using namespace std;
enum Huong { Dong = 10, Tay = 20, Nam = 30, Bac = 40 };
int main()
{
   Huong h;
   h = Nam;
   cout << "-------------------" << endl;
   cout << "Huong dong: " << Dong << endl;
   cout << "Huong tay: " << Tay << endl;
   cout << "Huong nam: " << Nam << endl;
   cout << "Huong bac: " << Bac << endl;
   return 0;
}
```

Và kết quả sau khi thực thi chương trình trên như sau:

```html
-------------------
Huong dong: 10
Huong tay: 20
Huong nam: 30
Huong bac: 40
```

## Tại sao sử dụng enum

Đến đây chúng ta đã hiểu enum trong C++ là gì và cách sử dụng enum trong chương trình như thế nào, bây giờ chúng ta cùng xem lý do để sử dụng enum trong C++ như sau:

* Enum trong C++ chỉ được sử dụng khi chúng ta mong đợi biến có một trong các tập hợp giá trị có thể. Như ví dụ 3 ở trên chúng ta có biến `h` giữ 4 giá trị đó là `Dong`, `Tay`, `Nam`, `Bac`.

* Vì chúng ta chỉ định nghĩa có 4 hướng, do đó biến `h` chỉ có thể nhận bất kỳ một trong bốn giá trị trên, nếu chúng ta cố gắng gán một giá trị ngẫu nhiên khác cho biến `h`, nó sẽ gây ra lỗi biên dịch.

* Điều này làm tăng kiểm tra thời gian biên dịch và tránh các lỗi xảy ra bằng cách chuyển vào các hằng không hợp lệ.

* Một đều quan trọng khác đó là `enum` được sử dụng thường xuyên với câu lệnh điều khiển `switch case`, trong đó tất cả các giá trị mà block `case` mong đợi có thể là một trong các giá trị của `enum`.

* Sử dụng kết hợp với cấu trúc điều khiển `switch case` đảm bảo `enum` không lấy các giá trị nằm ngoài các giá trị được khai báo trong dấu ngoặc nhọn.
