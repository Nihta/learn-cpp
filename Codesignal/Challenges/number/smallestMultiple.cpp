/**
 * Tìm số nhỏ nhất chia hết cho tất cả các số nằm trong khoảng [left, right]
 * Guaranteed constraints: 1 ≤ left ≤ right ≤ 15
*/
#include <iostream>
#include <algorithm>
using namespace std;

// Tìm bội chung nhỏ nhất
int lcm(int a, int b)
{
    return a * b / std::__gcd(a, b);
}

int smallestMultiple(int left, int right)
{
    int res = 1;
    for (int i = left; i <= right; i++)
        res = lcm(res, i); // std::lcm() là hàm có sẵn c++17
    return res;
}

int main()
{
    cout << smallestMultiple(2, 4) << endl; //12
    return 0;
}
