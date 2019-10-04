# Các điểm mới trong c++

## 1. Toán tử phạm vi (::)

Toán tử phạm vi `::` được dùng để truy cập các biến toàn cục trong trường hợp có biến cục bộ trùng tên.

Ví dụ:

```cpp
#include <iostream>
using namespace std;

// Khai báo biến toàn cục
int g = 20;

int main()
{
    // Khai báo biến cục bộ
    int g = 10;
    cout << g << " " << ::g << endl; // 10 20
    return 0;
}
```

## 2. Tham số mặc nhiên

Tham số mặc nhiên là tham số có sẵn giá trị, và nó được dùng khi người dùng không cung cấp đối số, lúc này giá trị mặc định sẽ được sử dụng.

Cách khai báo các bạn có thể tham khảo hàm `print()` trong ví dụ dưới đây:

```cpp
#include <iostream>
using namespace std;

void print(int a, int b = 69, int c = 96)
{
    cout << a << " " << b << " " << c << endl;
}

int main()
{
    print(1); // 1 69 96
    print(1, 2); // 1 2 96
    print(1, 2, 3); // 1 2 3
    return 0;
}
```

> Tham số mặc nhiên phải được khai báo theo thứ tự lần lượt từ phải sang trái

Những trường hợp khai báo tham số mặc nhiên không thành công:

 ```cpp
void xuat(int a = 1, int b, int c);
void xuat(int a = 1, int b = 2, int c);
void xuat(int a = 1, int b, int c = 3);
void xuat(int a = 1, int b = 2, int c);
 ```

## 3. Tái định nghĩa hàm (Function Overloading)

Quy tắc overloading: Các hàm trùng tên nhưng phải khác nhau về tham số (bao gồm số lượng, thứ tự, và kiểu dữ liệu).

Ví dụ: Muốn viết hàm tìm max cho kiểu int và double thông thường sẽ khai báo 2 hàm như sau:

```cpp
int maxInt(int a, int b);
double maxDouble(double a, double b);
```

Tuy nhiên có thể sử dụng Function Overloading trong trường hợp này như sau:

```cpp
int max(int a, int b);
double max(double a, double b);
```

Chương trình sẽ tự chọn hàm phù hợp với kiểu tham số mà bạn gọi.

## 4. Hàm Inline

Hàm inline hay còn gọi là hàm nội tuyến.

Nó yêu cầu trình biên dịch copy code vào trong chương trình thay vì thực hiện lời gọi hàm như thông thường, nó giúp giảm thời gian chạy chương trình.

> Lưu ý chỉ dùng hàm inline đối với hàm có cấu trúc đơn giản.

Ví dụ :

```cpp
inline int Max(int a, int b)
{
   return a > b ? a : b;
}
```
