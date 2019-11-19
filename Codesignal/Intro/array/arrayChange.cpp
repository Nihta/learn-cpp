/*
Cho 1 mảng số nguyên.
Mỗi lần di chuyển, bạn được phép tăng chính xác một trong phần tử của nó. 
Tìm lượng tăng tối thiểu cần thiết để có được một chuỗi tăng nghiêm ngặt từ đầu vào.

Ví dụ:
    Input: {2, 1, 10, 1}  -=>  Output: 12
    do mảng tăng sẽ là {2, 3, 10, 11}, (2-2)+(3-1)+(10-10)+(11-10)= 2 + 10 = 12
 */#include <iostream>
#include <vector>
using namespace std;

int r, i;
int arrayChange(vector<int> v)
{
    for(i = 1; i < v.size(); ++i)
        if (v[i] <= v[i-1])
            r += v[i-1] - v[i] + 1,
            v[i] = v[i-1] + 1;
    return r;
}

int main() {
    cout << arrayChange({2, 1, 10, 1});
    return 0;
}