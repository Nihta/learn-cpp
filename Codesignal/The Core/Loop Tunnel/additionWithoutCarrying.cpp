/**
 * Một cậu bé đang bắt đầu học cách cộng hai số nguyên.
 * Nhưng anh luôn quên đi phần quan trọng - phần nhớ (9 + 9 = 8 nhớ 1).
 * Cho hai số nguyên, tìm ra kết quả mà cậu bé sẽ tính ra (kết quả sai).
 *    456
 * + 1734
 *   ____
 *   1180
 */
#include <iostream>
using namespace std;

int additionWithoutCarrying(int a, int b) {
    int result = 0;
    for (int i = 1; a != 0 || b != 0; i *= 10, a/=10, b/=10)
        result += (a%10 + b%10)%10 * i;
    return result;
}

int main() {
    cout << additionWithoutCarrying(456, 1734); // 1180
    return 0;
}