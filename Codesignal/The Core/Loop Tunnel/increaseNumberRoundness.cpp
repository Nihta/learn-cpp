/**
 * Định nghĩa roundness của số nguyên là số lượng các số 0 liên tục trong nó (nằm cuối số đó):
 * roundness:          3               4
 *              12000003000      12000030000
 * Cho một số nguyên n, kiểm tra xem có thể tăng roundness của n không bằng cách hoán đổi một số cặp chữ số của nó.
 */
#include <iostream>
using namespace std;

// roundness:          3               4
//             12000003000      12000030000
bool increaseNumberRoundness(int n)
{
    while (n/10 != 0) // Ngưng lặp khi n còn 1 chữ số
        if (n%10 != 0 && n/10%10 == 0) // true nếu số có dạng ...[0][1-9]...
            return true;
        else
            n/=10;
    return false;
}

int main() {
    cout << boolalpha << increaseNumberRoundness(1230450); // true
    return 0;
}