/*
 Cho một divisor và một bound, tìm số nguyên N lớn nhất sao cho:
    N chia hết cho divisor.
    N nhỏ hơn hoặc bằng bound.
    N lớn hơn 0.
Đảm bảo rằng một số N như vậy tồn tại.
 */
#include <iostream>
using namespace std;

int maxMultiple(int divisor, int bound) {
    return bound/divisor * divisor;
}

int main() {
    cout << maxMultiple(3, 10); // 9
    return 0;
}