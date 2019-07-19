/*
Cho một mảng các số nguyên được sắp xếp v, nhiệm vụ của bạn
là xác định phần tử nào của a gần nhất với tất cả các giá trị khác của a
Nói cách khác, tìm phần tử x trong a, để tối thiểu hóa tổng sau:
abs(v[0] - x) + abs(v[1] - x) + ... + abs(v[v.size() - 1] - x)
*/

#include <iostream>
#include <vector>
using namespace std;

// Phần tử cần tìm là phần tử nằm chính giữa mảng (phần tử nhỏ nếu size v chẵn)
int absoluteValuesSumMinimization(vector<int> v)
{
    return v.size()%2 == 0 ? v[v.size()/2 - 1] : v[v.size()/2];
}

int main()
{
    vector<int> v ={1, 2, 3, 4, 5};
    cout << absoluteValuesSumMinimization(v);
    return 0;
}