# Các toán thử thao tác trên bit (bitwise)

## 1 Các toán thử thao tác trên bit

|Các phép thao tác trên bit|Kí hiệu|
|--------------------------|-------|
|[Phép AND](#11-Phép-AND)   | &     |
|[Phép OR](#12-Phép-OR)     | \|    |
|[Phép phủ định NOT](#13-Phép-phủ-định-NOT)| ~ |
|[Phép XOR](#14-Phép-XOR)   | ^     |
|[Phép dịch trái](#15-Phép-dịch-trái)  | << |
|[Phép dịch phải](#16-Phép-dịch-phải)  | >> |

## 2 [std::bitset](#2-std::bitset)

## 3 [Ví dụ bitwise](#3-Ví-dụ)

-----

### 1.1 Phép AND

**Kí hiệu**: `&`

**Bảng chân trị**:

|A|B|A & B|
|-|-|-----|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

> Phép AND chỉ có giá trị 1 nếu cả hai toán hạng đều có giá trị 1.
-----

### 1.2 Phép OR

**Kí hiệu**: `|`

**Bảng chân trị**:

|A|B|A \| B|
|-|-|------|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

> Phép OR chỉ có giá trị 0 nếu cả hai toán hạng đều có giá trị 0.
-----

### 1.3 Phép phủ định NOT

**Kí hiệu**: `~`

**Bảng chân trị**:

|A|~A|
|-|--|
|0|1|
|1|0|

> Phép NOT đảo bit 1 thành 0 và ngược lại.
-----

### 1.4 Phép XOR

**Kí hiệu**: `^`

**Bảng chân trị**:

|A|B|A ^ B|
|-|-|-----|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

> Phép XOR có giá trị 0 nếu cả hai toán hạng có cùng giá trị.
-----

### 1.5 Phép dịch trái

**Kí hiệu**: `<<`

> Phép dịch trái n bit tương đương với phép nhân cho 2 mũ n.
-----

### 1.6 Phép dịch phải

**Kí hiệu**: `>>`

> Phép dịch phải n bit tương đương với phép chia cho 2 mũ n.

[TOP^](#!)

-----

## 2 **std:bitset**

Một `bitset` là một mảng các phần tử bool nhưng mỗi giá trị bool không được lưu trữ riêng thay vào đó `bitset` tối ưu hóa không gian sao cho mỗi bool chỉ chiếm 1 bit. Do đó không gian được lấy bởi `bitset<N> bs` nhỏ hơn `bool bs[N]` và `vector<bool> bs(N)`. Tuy nhiên, một hạn chế của `bitset` là N phải được biết tại thời điểm biên dịch tức N là một hằng số (giới hạn này không có đối với vectơ và mảng động)

```c++
#include <iostream>
#include <bitset>
using namespace std;

#define M 32

int main()
{
    // Khởi tạo với tất cả các bit 0
    bitset<M> bset1;
    // Khởi tạo với bit của 20
    bitset<M> bset2(20);
    // Khởi tạo với bit trong string
    bitset<M> bset3(string("1100"));

    bitset<8> set8;    // 00000000
    set8[4] = set8[1]; // 00010010

    // Số lượng set
    int numberof1 = set8.count();
    // Số lượng unset
    int numberof0 = set8.size() - numberof1;

    // return 1 nếu bit là set
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";

    // true nếu có ít nhất 1 set
    cout << '\n' << boolalpha << set8.any() << endl;

    // returns true nếu không có bit nào là set
    cout << set8.none() << endl;

    // Đặt tất cả các bit là set
    set8.set();
    // bset.set(pos, x) bset[pos] = x
    set8.set(4, 0);  

    // Đặt tất cả các bit là unset
    set8.reset();

    // ~ bit 2    (1 -> 0, 0 -> 1)
    set8.flip(2);
    // ~ toàn bộ bit
    set8.flip();

    // BIN -> string
    cout << set8.to_string() << endl;
    // BIN to unsigned long long
    cout << set8.to_ullong() << endl;

    return 0;
}

```

```c++
#include <iostream>
#include <bitset>
using namespace std;


int main()
{
    bitset<4> bset1(9); // 1001
    bitset<4> bset2(3); // 0011
  
    // Toán tử so sánh
    cout << (bset1 == bset2) << endl; // false 0
    cout << (bset1 != bset2) << endl; // true 1
  
    // bitwise operation and assignment
    cout << (bset1 ^= bset2) << endl; // 1010
    cout << (bset1 &= bset2) << endl; // 0010
    cout << (bset1 |= bset2) << endl; // 0011
  
    // Phép dịch trái và dịch phải
    cout << (bset1 <<= 2) << endl; // 1100
    cout << (bset1 >>= 1) << endl; // 0110
  
    // Phép phủ định
    cout << (~bset2) << endl; // 1100
  
    // bitwise operator
    cout << (bset1 & bset2) << endl; // 0010
    cout << (bset1 | bset2) << endl; // 0111
    cout << (bset1 ^ bset2) << endl; // 0101

    return 0;
}
```

[TOP^](#!)

-----

## 3 Ví dụ

> Return kết quả dạng 2 mũ pos

### 1 Tìm bit ngoài cùng bên phải bằng 1

```c++
// 11010 -> 00010
return n & (~n+1);
```

### 2 Tìm bit ngoài cùng bên phải bằng 0

```c++
// 110101 -> 000010
return ~n & (n+1);
```

### 3 Tìm bit thứ 2 ngoài cùng bên phải bằng 0

```c++
// 1010010 -> 0000100
return ~n & ((n+1 | n) + 1)
```

### 4 Tìm vị trí cặp bit ngoài cùng bên phải giống nhau

```c++
// 110101, 101000 -> 000010
return ~(n ^ m) & ((n ^ m) + 1);
```

### 5 Tìm vị trí cặp bit ngoài cùng bên phải khác nhau

```c++
// 1010, 1100 -> 0010
return (n ^ m) & (~(n ^ m) + 1);
```

### 6 Thay đổi bit thứ k (tính từ phải) thành 0

```c++
// k = 3, 100101 -> 100001
return n & ~(1 << (k - 1));
```

### 7 Đảo vị trí của cặp bit liên kề (số 32 bit)

```c++
// 101110 -> 011101
return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
```

[TOP^](#!)

-----
