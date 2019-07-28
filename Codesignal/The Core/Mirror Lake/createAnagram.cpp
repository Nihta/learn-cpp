/**
 * Bạn được cung cấp hai string s và t có cùng độ dài, bao gồm các chữ cái tiếng
 *  Anh viết hoa. Nhiệm vụ của bạn là tìm số "hoạt động thay thế" tối thiểu
 * cần thiết để có được một anagram của string t từ string s. Một thao tác thay
 * thế được thực hiện bằng cách chọn chính xác một ký tự từ string s và thay thế
 * nó bằng một ký tự khác.
 * string x là một anagram của string y nếu người ta có thể lấy y bằng cách sắp
 * xếp lại các chữ cái của x. Ví dụ: các string "MITE" và "TIME" là anagram cái,
 * "BABA" và "AABB", nhưng "ABBAC" và "CAABA" thì không.
 */
#include <iostream>
#include <vector>
using namespace std;

int createAnagram(string s, string t) {
    vector <int> v(26, 0);
    for (char c : t)
        v[c - 'A']++;
    for (char c : s)
        v[c - 'A']--;

    int count = 0;
    for (int i : v)
        if (i > 0)
            count += i;
    return count;
}

int main() {
    cout << createAnagram("AABAA", "BBAAA"); // 1
    return 0;
}