// Cho các số nguyên dương n và k, tìm giá trị của n^k chia lấy dư 10e7 + 7
// Guaranteed constraints: 1 ≤ n ≤ 10^6, 0 ≤ k ≤ 10^9

#include <iostream>
#include <vector>
using namespace std;

int binaryPower(long long int n, long long int k)
{
    const int MOD = int(1e7) + 7;
    if (k == 0)
        return 1;
    if (k % 2 == 0)
        return binaryPower((n * n) % MOD, k / 2);
    return (binaryPower(n, k - 1) * n) % MOD;
}

int main()
{
    cout << binaryPower(1, 0) << endl;       // 1
    cout << binaryPower(2, 3) << endl;       // 8
    cout << binaryPower(10, 8) << endl;      // 9999937
    cout << binaryPower(2000, 1000) << endl; // 5601134
    return 0;
}
