# C++ Data Structures Cheat Sheet

## Table of Contents

* [1 Data Structures](#1-data-structures)
* [1.1 Overview](#11-overview)
* [1.2 Vector `std::vector`](#12-vector-stdvector)
* [1.3 Deque `std::deque` - Hàng đợi hai đầu](#13-deque-stddeque)
* [1.4 List `std::list` and `std::forward_list`](#14-list-stdlist-and-stdforward_list)
* [1.5 Map `std::map` and `std::unordered_map`](#15-map-stdmap-and-stdunordered_map)
* [1.6 Set `std::set`](#16-set-stdset)
* [1.7 Stack `std::stack` - Ngăn xếp](#17-stack-stdstack)
* [1.8 Queue `std::queue` - Hàng đợi](#18-queue-stdqueue)
* [1.9 Priority Queue `std::priority_queue` - Hàng đợi ưu tiên](#19-priority-queue-stdpriority_queue)
* [1.10 Heap `std::priority_queue`](#110-heap-stdpriority_queue)

## 1 Data Structures

### 1.1 Overview

![Legend](General/Legend.png)

![DataStructures](General/Data%20Structures.png)

![ComplexityChart](General/Complexity%20Chart.png)

![DataStructureSelection](General/C++%20STL.png)

[TOP ^](#!)

-----

### 1.2 Vector `std::vector`

**Use for**:

* Lưu trữ đơn giản
* Thêm nhưng không xóa
* Chèn hay xáo ở vị trí cuối cùng O(1)
* Serialization - Tuần tự hóa
* Truy cập đến phần tử thông qua index O(1)
* Efficient traversal (contiguous CPU caching)

**Do not use for**:

* Chèn/xóa phần tử ở giữa
* Dynamically changing storage
* Index không phải số nguyên

**Time Complexity**:

| Operation    | Time Complexity |
|--------------|-----------------|
| Insert Head  |          `O(n)` |
| Insert Index |          `O(n)` |
| Insert Tail  |          `O(1)` |
| Remove Head  |          `O(n)` |
| Remove Index |          `O(n)` |
| Remove Tail  |          `O(1)` |
| Find Index   |          `O(1)` |
| Find Object  |          `O(n)` |

**Example Code**:

```c++
#include <iostream>
#include <vector>
using namespace std;

// Khởi tạo vector 1 chiều rỗng (empty)
std::vector<int> v;
// Khởi tạo vector có 5 phần tử
vector<int> v(5);
// Khởi tạo vector có 5 phần tử bằng 10
vector<int> v(10, 5);

// Khởi tạo vector 2 chiều rỗng
vector < vector<int> > v2;
// Khởi tạo vector kích thước 5×?
vector < vector<int> > v2(5);
// Khởi tạo Vector 5x10 với tất cả phần tử bằng 1
vector < vector<int> > v2(5, vector<int> (10,1));

// Insert
v.insert(v.begin(), value); // Chèn vào đầu O(n)
v.insert(v.begin() + index, value); // Chèn vào index O(n)
v.push_back(value); // Thêm phần tử vào cuối O(1)

// Access
int head = v.front();       // Lấy phần tử đầu tiên O(1)
int value = v.at(index);    // Lấy phần tử index O(1)
int tail = v.back();        // Lấy phần tử cuối cùng O(1)

// Remove
v.erase(v.begin());             // Xóa phần tử đầu tiên O(n)
v.erase(v.begin() + index);     // Xóa phần tử index O(n)
v.pop_back();                   // Xóa phần tử cuối cùng O(1)

// Kiểm tra vector có phần tử hay không
cout << std::boolalpha << v.empty();

// Size
unsigned int size = v.size();

// Iterate - Iterator là một con trỏ được sử dụng để đại diện cho một phần tử nào đó
for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << std::endl;
}

// Clear
v.clear();
```

[TOP ^](#!)

-----

### 1.3 Deque `std::deque`

**Use for**:

* Tương tự như `std::vector` có thêm `push_front` and `pop_front`
* Chèn hoặc xóa phần tử ở cuối hoặc đầu của dãy (vector chỉ chèn hoặc xóa phần tử ở cuối dãy).

**Do not use for**:

* C-style contiguous storage (not guaranteed)

**Notes**:

* Phát âm 'deck'
* Viết tắt của **D**ouble **E**nded **Que**ue

**Example Code**:

```c++
#include <iostream>
#include <deque>
using namespace std;

std::deque<int> d;

// Chèn phần tử
d.push_front(value); // Chèn phần tử vào đầu
d.insert(d.begin() + index, value); // Chèn vào index
d.push_back(value); // Thêm phần tử vào cuối

// Truy cập phần tử
int head = d.front(); // Truy cập phần tử đầu tiên
int value = d.at(index); // Truy cập vị trí index
int tail = d.back(); // Truy cập phần tử cuối cùng

// Xóa phần tử
d.pop_front(); // Xóa phần tử đầu
d.erase(d.begin() + index); //Xóa phần tử ở index
d.pop_back(); // Xóa phần tử cuối

// Kiểm tra deque có phần tử hay không
cout << std::boolalpha << d.empty();

// Size
unsigned int size = d.size();

// Iterate
for(std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
    std::cout << *it << std::endl;
}


// Clear
d.clear();
```

[TOP ^](#!)

-----

### 1.4 List `std::list` and `std::forward_list`

**Use for**:

* Chèn/xóa phần tử ở bất cứ vị trí nào O(1)
* Efficient sorting (pointer swap vs. copying)

**Do not use for**:

* Điểm yếu của list là khả năng truy cập phần tử trực tiếp thông qua index O(n)

**Time Complexity**:

| Operation    | Time Complexity |
|--------------|-----------------|
| Insert Head  |          `O(1)` |
| Insert Index |          `O(n)` |
| Insert Tail  |          `O(1)` |
| Remove Head  |          `O(1)` |
| Remove Index |          `O(n)` |
| Remove Tail  |          `O(1)` |
| Find Index   |          `O(n)` |
| Find Object  |          `O(n)` |

**Example Code**:

```c++
std::list<int> l;

//---------------------------------
// General Operations
//---------------------------------

// Chèn phần tử
l.push_front(value); // Đầu
l.insert(l.begin() + index, value);     // index
l.push_back(value); // Cuối

// Truy cập phần tử
int head = l.front(); // Phần tử dầu list
int value = std::list<int>::iterator it = l.begin() + index; // index
int tail = l.back(); // Phần tử cuối list

// Xóa phần tử
l.pop_front(); // Xóa phần tử đầu list
l.erase(l.begin() + index); // index
l.pop_back(); // Xóa phần tử cuối list

// Kiểm tra list có phần tử hay không
cout << std::boolalpha << l.empty();

// Size
unsigned int size = l.size();

// Iterate
for(std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
    std::cout << *it << std::endl;
}

// Clear
l.clear();

//---------------------------------
// Toán tử riêng của container
//---------------------------------

// Ghép list khác vào vị trí position của list hiện hành, sau khi nối ghép, list other không còn phần tử nào
// splice(iterator pos, list &x)
// splice(iterator pos, list &x, iterator i)
// splice(iterator pos, list &x, iterator first, iterator last)
l.splice(l.begin() + index, list2);

// Remove: Xóa một phần tử theo giá trị
l.remove(value);

// Unique: Xóa bỏ phần tử trùng lặp
l.unique();

// Merge: Hợp nhất hai list
l.merge(list2);

// Sort: Sắp xếp list
l.sort();

// Reverse: Đảo ngược thứ tự list
l.reverse();

```

[TOP ^](#!)

-----

### 1.5 Map `std::map` and `std::unordered_map`

**Use for**:

* Key-value pairs - Cặp <Khóa, Giá trị>
* Tra cứu bằng key
* Tìm kiếm nếu key/value tồn tại
* Loại bỏ trùng lặp
* `std::map` Ordered map
* `std::unordered_map` Hash table

**Do not use for**:

* Sắp xếp

**Notes**:

* Typically ordered maps (`std::map`) chậm hơn unordered maps (`std::unordered_map`)
* Map thường được triển khai dưới dạng cây tìm kiếm nhị phân

**Time Complexity**:

**`std::map`**

| Operation           | Time Complexity |
|---------------------|-----------------|
| Insert              |     `O(log(n))` |
| Access by Key       |     `O(log(n))` |
| Remove by Key       |     `O(log(n))` |
| Find/Remove Value   |     `O(log(n))` |

**`std::unordered_map`**

| Operation           | Time Complexity |
|---------------------|-----------------|
| Insert              |          `O(1)` |
| Access by Key       |          `O(1)` |
| Remove by Key       |          `O(1)` |
| Find/Remove Value   |              -- |

**Example Code**:

```c++
#include <iostream>
#include <map>
using namespace std;

std::map<std::string, std::string> m;

//---------------------------------
// General Operations
//---------------------------------

// Insert
m.insert(std::pair<std::string, std::string>("key", "value"));

// Access by key
std::string value = m.at("key");

// Remove by key
m.erase("key");

// Size
unsigned int size = m.size();

// Iterate
for(std::map<int>::iterator it = m.begin(); it != m.end(); it++) {
    std::cout << *it << std::endl;
}

// In map
for (auto &&i : m)
    cout << i.first << " " << i.second << "\n";

// Clear
m.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Tìm kiếm sự tồn tại của 1 phần tử bởi key
bool exists = (m.find("key") != m.end());
```

[TOP ^](#!)

-----

### 1.6 Set `std::set`

**Use for**
*Xóa bỏ trùng lặp
*Ordered dynamic storage

**Do not use for**:
*Lưu trữ đơn giản
*Truy cập trực tiếp bằng index

**Notes**
*Sets are often implemented with binary search trees

**Time Complexity**:

| Operation    | Time Complexity |
|--------------|-----------------|
| Insert       |     `O(log(n))` |
| Remove       |     `O(log(n))` |
| Find         |     `O(log(n))` |

**Example Code**:

```c++
std::set<int> s;

//---------------------------------
// General Operations
//---------------------------------

// Insert - Thêm phần tử vào set
s.insert(20);

// Size
unsigned int size = s.size();

// Iterate
for(std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
    std::cout << *it << std::endl;
}

// Remove
s.erase(20);

// Clear
s.clear();

//---------------------------------
// Container-Specific Operations
//---------------------------------

// Tìm kiếm phần tử nếu nó tồn tại
bool exists = (s.find(20) != s.end());

// Count the number of elements with a certain value
unsigned int count = s.count(20);
```

[TOP ^](#!)

-----

### 1.7 Stack `std::stack`

**Use for**:

* FILO: First-In Last-Out operations - Vào sau ra trước
* Việc bổ sung và loại bỏ phần tử được thực hiển ở cuối danh sách

**Time Complexity**:

| Operation    | Time Complexity |
|--------------|-----------------|
| Push         |          `O(1)` |
| Pop          |          `O(1)` |
| Top          |          `O(1)` |

**Example Code**:

```c++
#include <iostream>
#include <stack>
using namespace std;

// Khởi tạo stack
stack<int> s;

// Thêm phần tử vào đỉnh stack
s.push(20);

// Lấy giá trị phần tử ở đỉnh
int top = s.top();

// Xóa phần tử ở đỉnh stack
s.pop();

// Kiểm tra stack có phần tử hay không
cout << std::boolalpha << s.empty();

// Size
unsigned int size = s.size();


```

[TOP ^](#!)

-----

### 1.8 Queue `std::queue`

**Use for**:

* **FIFO**: First-In First-Out operations - Vào trước ra trước
* **Ex**: Hệ thống đặt hàng online đơn giản (đến trước phục vụ trước)

**Notes**:

> Thường được triển khai như [`std::deque`](#13-deque-stddeque)

**Example Code**:

```c++
#include <iostream>
#inlude <queue>
using namespace std;

// Khởi tạo hàng đợi
std::queue<int> q;

// Thêm vào cuối hàng đợi
q.push(value);

// Access
int head = q.front(); // Truy cập phần tử đầu
int tail = q.back(); // Truy cập phần tử cuối

// Xóa phần tử đầu hàng đợi
q.pop();

// Kiểm tra hàng đợi có phần tử hay không
cout << std::boolalpha << q.empty();

// Size
unsigned int size = q.size();

// Xóa phần tử đầu
q.pop();
```

[TOP ^](#!)

-----

### 1.9 Priority Queue `std::priority_queue`

**Use for**:

* **First-In First-Out**: Vào trước ra trước, phần tử ở đỉnh luôn luôn là phần tử có độ ưu tiên lớn nhất so với các phần tử khác (mặc định là phần tử lớn nhất)
* **Ex**: Trường hợp khẩn trong y tế (vết thương do rắn độc với gãy tay)

**Notes**:

> Thường được triển khai như [`std::vector`](#12-vector-stdvector)

**Example Code**:

```c++
#include <iostream>
#include <queue>
using namespace std;

// Khởi tạo hàng đợi ưu tiên
// Phần tử lớn nhất có độ ưu tiên cao nhất
std::priority_queue<int> p;
// Phần tử nhỏ nhất có độ ưu tiên cao nhất
std::priority_queue <int, vector<int>, greater<int> > p;

// Thêm phần tử có giá trị value vào priority_queue
p.push(value);

// Truy xuất phần tử ở đỉnh priority_queue (phần tử có độ ưu tiên lớn nhất)
int top = p.top();

// Loại bỏ phần tử ở đỉnh priority_queue
p.pop();

// Kiểm tra priority_queue có phần tử hay không
cout << std::boolalpha << p.empty();

// Lấy phần tử in xong xóa
while(!p.empty())
{
    cout << p.top() << " ";
    p.pop();
}

// Size
unsigned int size = p.size();

```

[TOP ^](#!)

-----

### 1.10 Heap `std::priority_queue`

**Notes**:

* Một đống về cơ bản là một thể hiện của [hàng đợi ưu tiên](#19-priority-queue-stdpriority_queue)
* **Min heap**: giá trị của nút gốc là nhỏ hơn hoặc bằng các giá trị của các nút con
* **Max heap**: giá trị của nút gốc là lớn hơn hoặc bằng giá trị của các nút con

* Một max heap có thể sử dụng cho công việc lớn nhất trước tiên
* Một min heap có thể sử dụng cho công việc nhỏ nhất trước tiên

**Max Heap (sử dụng cây nhị phân)**:

![MaxHeap](General/MaxHeap.png)

[TOP ^](#!)

-----
