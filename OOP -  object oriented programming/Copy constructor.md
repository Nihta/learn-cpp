# Copy constructor

## Copy constructor C++

Hàm tạo sao chép (copy constructor) khởi tạo một đối tượng bằng cách sử dụng một đối tượng khác cùng class đã được tạo trước đó.

Mục đích:

- Khởi tạo một đối tượng từ một đối tượng khác cùng loại.
- Sao chép một đối tượng để truyền nó làm đối số cho function.
- Sao chép một đối tượng để trả về nó từ một function.

## Hàm sao chép mặc nhiên

Nếu chúng ta không định nghĩa copy constructor thì mặc nhiên trình biên dịch sẽ tự động tạo cho chúng ta một copy constructor mặc nhiên.

Hàm này sẽ sao chép nội dung từng bit của đối tượng nguồn vào các bit tương ứng của đối tượng đích. Như vậy các vùng nhớ của đối tượng nguồn và đối tượng đích sẽ có nội dung như nhau.

Trong đa số các trường hợp, nếu lớp không có các thuộc tính kiểu con trỏ hay tham chiếu, thì việc dùng các copy constructor mặc nhiên (để tạo ra một đối tượng mới có nội dung như một đối tượng cho trước) là đủ và không
cần xây dựng một hàm tạo sao chép mới.

## Hàm xây dựng sao chép do người dùng định nghĩa

**Cú pháp**:

```cpp
className(const className &obj)
{
    //
};
```

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;
class NhanVien
{
    int maSo;
    string ten;
    int tuoi;

public:
    NhanVien(int m, string tn, int t)
    {
        maSo = m;
        ten = tn;
        tuoi = t;
    }

    NhanVien(NhanVien &n)
    {
        maSo = n.maSo;
        ten = n.ten;
        tuoi = n.tuoi;
    }

    void display()
    {
        cout << ten << endl;
        cout << "\tMa so nhan vien: " << maSo << endl;
        cout << "\tTuoi: " << tuoi << endl;
    }
};

int main()
{
    NhanVien n1(123, "Nguyen Van A", 25);
    NhanVien n2(n1);
    NhanVien n3 = n1;

    n1.display();
    n2.display();
    n3.display();

    return 0;
}
```

**Kết quả**:

```cpp
Nguyen Van A
        Ma so nhan vien: 123
        Tuoi: 25
Nguyen Van A
        Ma so nhan vien: 123
        Tuoi: 25
Nguyen Van A
        Ma so nhan vien: 123
        Tuoi: 25
```

**Loại copy được tạo bởi copy constructor**:

- [Shallow copy](#Shallow-copy)
- [Deep copy](#Deep-copy)

### Shallow copy

Shallow copy được định nghĩa là quá trình tạo bản sao của một đối tượng bằng cách sao chép dữ liệu của tất cả các biến thành viên

> Hàm tạo sao chép mặc nhiên chỉ có thể tạo shallow copy.

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;

class TestShallowCopy
{
    int a;
    int b;
    int *p;

public:
    TestShallowCopy()
    {
        p = new int;
    }

    void setData(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }

    void display()
    {
        cout << "    Gia tri cua a la: " << a << endl;
        cout << "    Gia tri cua b la: " << b << endl;
        cout << "    Gia tri cua *p la: " << *p << endl;
    }
};

int main()
{
    TestShallowCopy t1;
    t1.setData(2, 6, 8);

    TestShallowCopy t2 = t1;

    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.display();

    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.display();
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

Trong ví dụ trên câu lệnh `TestShallowCopy t2 = t1` gọi hàm tạo mặc nhiên được tạo bởi trình biên dịch.

Hàm tạo mặc nhiên tạo shallow copy của đối tượng tồn tại. Do đó, con trỏ `p` của cả hai đối tượng trỏ đến cùng một vị trí bộ nhớ.

Vì vậy, khi bộ nhớ của một trường được giải phóng, bộ nhớ của một trường khác cũng được tự động giải phóng khi cả hai trường đều trỏ đến cùng một vị trí bộ nhớ.

Để giải quyết vấn đề trên chúng ta deep copy

### Deep copy

Deep copy tự động cấp phát bộ nhớ cho bản sao và sau đó sao chép giá trị thực cho bản sao, cả nguồn và bản sao có vị trí bộ nhớ khác nhau.

Theo cách này, cả nguồn và bản sao là khác nhau và sẽ không chia sẻ cùng một vị trí bộ nhớ.

Deep copy yêu cầu chúng ta viết hàm xây dựng do người dùng định nghĩa.

**Ví dụ**:

```cpp
#include <iostream>
using namespace std;

class TestShallowCopy
{
    int a;
    int b;
    int *p;

public:
    TestShallowCopy()
    {
        p = new int;
    }

    TestShallowCopy(TestShallowCopy &t)
    {
        a = t.a;
        b = t.b;
        p = new int;
        *p = *(t.p);
    }

    void setData(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z;
    }

    void display()
    {
        cout << "   Gia tri cua a la: " << a << endl;
        cout << "   Gia tri cua b la: " << b << endl;
        cout << "   Gia tri cua *p la: " << *p << endl;
    }
};

int main()
{
    TestShallowCopy t1;
    t1.setData(2, 6, 8);
    TestShallowCopy t2 = t1;
    cout << "Du lieu cua doi tuong t1: " << endl;
    t1.display();
    cout << "Du lieu cua doi tuong t2: " << endl;
    t2.display();
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

Ở ví dụ trên, chúng ta tự định nghĩa hàm tạo sao chép, câu lệnh `TestShallowCopy t2 = t1` sẽ gọi hàm xây dựng sao chép do chúng ta định nghĩa.

> Khi chương trình có dữ liệu thành viên là con trỏ hoặc tham chiếu thì nên định nghĩa một hàm tạo sao chép để tránh những bất lợi của shallow copy.
