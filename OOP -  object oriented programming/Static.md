# Static member

## Static data member

**Các đặc tính chính**:

- Một bản duy nhất tồn tại trong suốt quá trình chạy của chương trình.
- Dùng chung cho tất cả các đối tượng của lớp. Bất kể có bao nhiêu đối tượng tạo ra từ class đó.
- Phải được định nghĩa bên ngoài class vì thành viên tĩnh được lưu trữ riêng biệt, không giống như các thành phần khác của đối tượng.
- Giá trị khởi tạo = 0 và có thể gián giá trị khởi tạo.

**Ví dụ**:

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

class Test
{
private:
    // Khai báo thành phần static
    static int count;

public:
    Test()
    {
        count++;
    }
    void CountValue()
    {
        cout << "Count = " << count << endl;
    }
};

// Khởi tạo biến static
int Test::count; // Không gán thì mặc định bằng 0
// int Test::count = 8;

int main()
{
    Test a, b;
    a.CountValue(); // 2
    b.CountValue(); // 2
    return 0;
}
```

## Static member functions

**Các đặc tính chính**:

- Phương thức tĩnh chỉ có thể truy cập đến thành viên tĩnh (thuộc tính hoặc phương thức tĩnh khác).
- Một phương thức tĩnh có thể được gọi qua tên class ngay khi không có đối tượng nào của lớp đó tồn tại.

**Ví dụ**:

```cpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Test
{
private:
    //khai báo thành phần static
    static int count;

public:
    Test()
    {
        count++;
    }
    static int CountValue()
    {
        return count;
    }
};

int Test::count;

int main()
{
    Test a, b, c, d, e, f;
    cout << "Dem : " << Test::CountValue(); // 6;
    return 0;
}
```
