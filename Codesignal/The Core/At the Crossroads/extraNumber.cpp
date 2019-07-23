/**
 * Cho ba số nguyên, a, b và c. Đảm bảo rằng 2 trong 3 số này bằng nhau.
 * Tìm giá trị của số nguyên thứ ba?
 */
#include <iostream>
using namespace std;

int extraNumber(int a, int b, int c) {
    return a == b ? c : a == c ? b : a;
}

int main() {
    cout << extraNumber(2, 10, 2);
    return 0;
}