/**
 * Cho một mảng tối đa bốn số nguyên dương, mỗi số nhỏ hơn 256
 * Nhiệm vụ của bạn là tạo một số M theo cách sau:
 *    Phần tử đầu tiên của mảng chiếm 8 bit đầu tiên của M
 *    Phần tử thứ hai chiếm 8 bit tiếp theo, v.v.
 * Ví dụ:
 * {24, 85, 0} -> {00011000, 01010101, 00000000}
 *             ->  00000000  01010101  00011000    -> 21784
 */
#include <iostream>
#include <vector>
using namespace std;

int arrayPacking(vector<int> v) {
    int m = 0;
    for(int i = 0; i < v.size(); i++)
        m += v[i] << 8*i;
    return m;
}

int main() {
    cout << arrayPacking({23, 45, 39}); // 2567447
    return 0;
}