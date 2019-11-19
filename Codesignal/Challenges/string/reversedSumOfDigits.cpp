/**
 * Cho các số nguyên p và n, tìm số nguyên n chữ số không âm nhỏ nhất
 * (được biểu diễn dưới dạng chuỗi) và tổng các chữ số của số đó bằng p.
 * Nếu không có số đó, hãy trả về "-1".
 */

#include <iostream>
#include <vector>
using namespace std;

string reversedSumOfDigits(int p, int n) {
    // Đảm bảo số cần tìm tồn tại
    if (p > 9*n || (p < 1 && n > 1))
        return "-1";

    string res = "";
    while (p >= 1 && n > 1) {
        int tmp = 10;
        while (--tmp >= 0) {
            if (p - tmp >= 1) {
                p -= tmp;
                n--;
                res =  string(1, '0' + tmp) + res;
                break;
            }
        }
    }

    return string(1, p + '0') + res;
}

int main() {
    cout << reversedSumOfDigits(15, 3) << endl; // 159
    cout << reversedSumOfDigits(2, 5) << endl; // 10001
    cout << reversedSumOfDigits(0, 10) << endl; // -1
    cout << reversedSumOfDigits(0, 1); // 0
    return 0;
}
