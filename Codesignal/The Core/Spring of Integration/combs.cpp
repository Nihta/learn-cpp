/**
 * Cô X chỉ có hai chiếc lược, cả hai đều đã cũ và gãy một hoặc hai chiếc răng.
 * (comb.lenghth() <= 8). Cô ấy có nhiều ví và chúng có chiều dài khác nhau,
 * cô ấy mang theo những chiếc lược trong đó. ...
 * Tìm chiều dài tối thiểu của chiếc ví mà cô ấy cần để có thể mang đồng thời 2
 * cái lược theo bên mình. ...
 * Ví dụ:    *.* + *..* -=> ***.* (=5)
 * https://app.codesignal.com/arcade/code-arcade/spring-of-integration/6ceKutpnCs4LzBKgf
 */
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

// Trường hợp lược a buộc phải nằm trước lược b
int test(string a, string b) {
    int r = 999;
    // Đổi về dạng bit: '*' = 1, '.' = 0;
    bitset<16> c1(a, 0, -1, '.', '*'), c2(b, 0, -1, '.', '*');
    // Đếm số lượng '*'
    int cnt = c1.count() + c2.count();
    for (int i = a.size(); i >= 0; i--) {
        bitset<16> c2Tmp = c2, tmp = c1 | (c2Tmp << i);
        if (tmp.count() == cnt)
            r = min(r, i);
    }
    return max(a.size(), b.size() + r);
}

int combs(string comb1, string comb2) {
    return min(test(comb1, comb2), test(comb2, comb1));
}

int main() {
    cout << combs("*..*.*", "*.***"); // 9 *..*xx***
    return 0;
}