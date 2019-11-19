/**
 * Tìm số cách biểu thị n là tổng của ít nhất hai số nguyên dương liên tiếp.
 */
#include <iostream>
using namespace std;

/**
 * Check 1 + 2 + 3 + ... bằng n hay không
 * Check 2 + 3 + 4 + ... bằng n hay không
 * ...
 * Check  n/2 - 1 + n/2 bằng n hay không
 * check n/2 + n/2 + 1 bằng n hay không
 */
int isSumOfConsecutive2(int n) {
    int count = 0;
    for (int i = 1; i <= n/2; i++) {
        int sum = 0, tmp = i;
        while (sum < n) {
            sum += tmp;
            tmp++;
        }
        if (sum == n)
            count++;
    }
    return count;
}


int main() {
    cout << isSumOfConsecutive2(9);
    return 0;
}