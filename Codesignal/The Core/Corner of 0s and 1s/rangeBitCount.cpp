/**
 * Cho hai số nguyên a và b trong đó 0 ≤ a ≤ b.
 * Tưởng tượng bạn phải xây dựng một mảng gồm tất cả các số nguyên từ a đến b.
 * Bạn cần đếm số lượng 1 trong biểu diễn nhị phân của các số trong mảng đó.
 */
#include <iostream>
#include <bitset>
using namespace std;

int rangeBitCount(int a, int b) {
    int result = 0;
    for (int i = a; i <= b; i++)
    {
        bitset<8> tmp(i);
        result += tmp.count();
    }
    return result;
}

int main() {
    cout << rangeBitCount(1, 15); // 32
    return 0;
}