/**
 * Bạn được cung cấp một substring của một cyclic string. Độ dài của chuỗi nhỏ
 * nhất có thể được nối với chính nó nhiều lần để có được cyclic string này
 * là bao nhiêu?
 * Chúng tôi gọi cyclic string (chuỗi tuần hoàn) nếu nó có thể thu được bằng
 * cách nối chuỗi khác với chính nó nhiều lần (ví dụ: s2 = "abcabcabcabc ..."
 * là tuần hoàn vì nó có thể được lấy từ s1 = "abc" theo cách đó).
 * Lưu ý ràng buộc string cần tìm nằm trong substring.
 */
#include <iostream>
using namespace std;

// Trong cyclic string được tạo thành từ string s có độ dài i (tối thiểu) nối
//lại với nhau thì cyclicS[j] == cyclicS[j%i]
int cyclicString(string s) {
    for (int i = 1; ; i++) {
        bool check = true;
        for (int j = 0; j < s.length(); j++)
            if (s[j] != s[j % i]) {
                check = false;
                break;
            }
        if (check)
            return i;
    }
}

int main() {
    cout << cyclicString("cabca"); // 3
    return 0;
}