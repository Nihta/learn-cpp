/**
 * Cho một số nguyên 3 ≤ n ≤ 400 tìm một số nguyên k>= 2 sao cho biểu diễn
 * của n trong hệ cơ số k có số lượng số 0 tối đa có thể.
 * Nếu có một vài số k thỏa mãn, trả về k nhỏ nhất.
*/
#include <iostream>
#include <vector>
using namespace std;

int maxZeros(int n)
{
    int res = 0;
    int maxZeros = 0;
    for (int k = 2; k <= n; k++)
    {
        int count = 0;
        int nTmp = n;
        // Chuyển nTmp từ cơ số 10 sang cơ số k
        while (nTmp != 0)
        {
            // Đếm số lượng số 0 có trong nTmp cơ số k
            if (nTmp % k == 0)
                count++;
            nTmp /= k;
        }
        if (count > maxZeros)
        {
            maxZeros = count;
            res = k;
        }
    }
    return res;
}

int main()
{
    cout << maxZeros(9) << endl;   // 2
    cout << maxZeros(127) << endl; // 5
    return 0;
}
