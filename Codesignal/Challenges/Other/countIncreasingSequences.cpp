/**
 * Cho hai số nguyên n và k, tìm số chuỗi tăng dần có độ dài n bao gồm các số
 * nguyên dương không vượt quá k.
 * Ví dụ: n = 2, k = 3 => result = 3
 * {1, 2}, {1, 3}, {2, 3}
*/

#include <iostream>
using namespace std;

int countIncreasingSequences(int n, int k)
{
    int res = 1;
    if (n > k)
        return 0;
    // Tổ hợp chập n của k phần tử
    for (int i = 1; i <= k; i++)
        res *= i; // k!/(n! * (k-n)!)
    for (int i = 1; i <= n; i++)
        res /= i;
    for (int i = 1; i <= k - n; i++)
        res /= i;
    return res;
}

int main()
{
    cout << countIncreasingSequences(3, 5) << endl; // 10
    return 0;
}

// 123 124 125 134 135 145
// 234 235 245
// 345
