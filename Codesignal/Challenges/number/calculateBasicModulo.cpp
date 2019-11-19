// Tìm a^b % m
// Với a, b, m rất lớn: |a|, |b| ≤ 10^18, 1 ≤ m ≤ 10^9

#include <iostream>
#include <vector>
using namespace std;

/**
 * (m * n) % p = ((m % p) * (n % p)) % p
 *
 * Nếu b chẵn:
 * (a ^ b) % c = ((a ^ b/2) * (a ^ b/2)) % c
 *
 * Nếu b là số lẻ:
 * (a ^ b) % c = (a * (a ^ (b-1)) % c
*/
int calculateBasicModulo(long long a, long long b, long long m)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;

    long long y;

    if (b % 2 == 0)
    {
        long long x = calculateBasicModulo(a, b / 2, m); // Tính a^(b/2) % m
        y = (x * x) % m;
    }
    else
        // (a * (a ^ (b-1)) % m = (a % m * (a^(b-1) % m) % m) % m
        y = ((a % m) * calculateBasicModulo(a, b - 1, m) % m) % m;

    // return kiểu này để tính mod của số âm y có giá trị tuyệt đối nhỏ hơn m
    return (y + m) % m;
    // return y % m
}

int main()
{
    cout << calculateBasicModulo(1, 0, 1e7 + 7) << endl;       // 1
    cout << calculateBasicModulo(2, 3, 1e7 + 7) << endl;       // 8
    cout << calculateBasicModulo(-3, 5, 89) << endl;           // 24
    cout << calculateBasicModulo(10, 8, 1e7 + 7) << endl;      // 9999937
    cout << calculateBasicModulo(2000, 1000, 1e7 + 7) << endl; // 5601134
    return 0;
}
