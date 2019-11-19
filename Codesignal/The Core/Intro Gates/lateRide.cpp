/**
 * Cho n là số phút kể từ 00:00    0 ≤ n < 60*24
 * Trả về tổng các chữ số của thời gian hiện tại (định dạng hh:mm)
 */
#include <iostream>
using namespace std;

int lateRide(int n) {
    int h = n/60;
    int m = n%60;
    return h/10 + h%10 + m/10 + m%10;
}

int main() {
    cout << lateRide(808); // 14
    return 0;
}