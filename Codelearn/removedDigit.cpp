/**
 * Con gái Việt đang tập viết. Cháu viết liên tiếp các số từ 1 tới N thành 1 dãy
 * số như 1234567891011...
 * Tuy nhiên cháu lại rất ghét 1 số chữ số nào đó, ví dụ S = {1, 2, 3}.
 * Do đó, sau khi viết xong dãy số cháu gạch đi tất cả các chữ số mà cháu ghét.
 * Việt tự nhiên tò mò muốn biết chữ số thứ K (đếm từ 1) mà cháu gạch là chữ số nào.
 * Trường hợp ko đủ dãy số hãy trả ra số -1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Chuyển số sang string
string numToString (int n) {
    string res;
    while (n != 0) {
        res = string(1, n%10 + '0') + res;
        n/= 10;
    }
    return res;
}

int removedDigit(int n, vector<int> s, int k)
{
    if (n == 0 || s.size() == 0 || k == 0)
        return -1;

    string write;

    // Tạo một string bao gồm các số từ 1 đến n liên tục
    for (int i = 1; i <= n; i++) {
        write += numToString(i);
    }

    cout << write << endl;

    // Tìm số thứ k bị xóa
    for (auto &&c : write)
        if (find(s.begin(), s.end(), c-'0') != s.end())
            if (--k == 0)
                return c-'0';

    return -1;
}

int main() {
    cout << removedDigit(10, {3, 4, 5}, 3); // 5
    return  0;
}
