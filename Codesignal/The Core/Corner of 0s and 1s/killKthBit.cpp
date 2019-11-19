/**
 * Cho n: 0 ≤ n ≤ 2^31 - 1
 * Thay đổi bit thứ k (tính từ phải sang) thành 0
 * Ví dụ:    k = 3    100101 ~> 100001
 */
#include <iostream>
using namespace std;

int killKthBit(int n, int k) {
  return n & ~(1 << (k - 1));
}

int main() {
    cout << killKthBit(37, 3); // 33
    return 0;
}