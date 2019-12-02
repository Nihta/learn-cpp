/**
 * Triangular Numbers là số nguyên dương có thể được biểu diễn dưới dạng tổng của
 * tất cả các số nguyên từ 1 đến một số n.
 * Xác định xem số đã cho có phải là Triangular.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isSum(int value) {
    int i = 1;
    while (value > 0)
        value -= i++;
    return value == 0;
}

int main() {
    cout << std::boolalpha << isSum(6) << endl; // 6 = 1 + 2 + 3
    return  0;
}
