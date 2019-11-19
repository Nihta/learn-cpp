/**
 * Cho các số nguyên n, l và r.
 * Tìm số cách biểu diễn n = A + B sao cho l ≤ A ≤ B ≤ r.
 */
#include <iostream>
using namespace std;

int countSumOfTwoRepresentations2(int n, int l, int r) {
    int c = n/2 - max(n - r, l) + 1;
    return c > 0 ? c : 0;
}

int main() {
    // 2:  6 = 2 + 4 = 3 + 3
    cout << countSumOfTwoRepresentations2(6, 2, 4);
    return 0;
}