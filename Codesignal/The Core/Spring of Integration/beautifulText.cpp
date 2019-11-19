/**
 * Hãy xem xét một chuỗi chỉ chứa các chữ cái và khoảng trắng. Nó được phép
 * thay thế một số khoảng trắng (có thể hoặc không) bằng các ký hiệu dòng mới
 * để có được một văn bản nhiều dòng. Gọi một văn bản nhiều dòng là đẹp khi và
 * chỉ khi mỗi dòng của nó (nghĩa là các chuỗi con được phân định bởi một ký tự
 * dòng mới) có chứa số lượng ký tự bằng nhau (chỉ tính đến các chữ cái và
 * khoảng trắng khi đếm tổng số ký tự). Gọi chiều dài của dòng là text width.
 * Cho một chuỗi và 2 số nguyên l và r (l ≤ r), kiểm tra xem có thể có được một
 * văn bản đẹp từ chuỗi có text width nằm trong phạm vi [l, r] không?
 */
#include <iostream>
#include <vector>
using namespace std;

//     s.size() = Số dòng * textWidth + (số dòng - 1)
// <=> Số dòng = (s.size() + 1)/(textWidth + 1)
bool beautifulText(string s, int l, int r) {
    for (int textWidth = l; textWidth <= r; textWidth++) {
        if ((s.size() + 1)%(textWidth + 1) == 0) {
            bool check = true;
            for (int j = textWidth; j < s.size(); j+= textWidth+1)
                if (s[j] != ' ') {
                    check = false;
                    break;
                }
            if (check)
                return true;
        }
    }
    return false;
}
/** es6
 * function beautifulText(inputString, l, r) {
    for (let i = l; i <= r; i++) {
        let j = i
        for (; inputString[j] === " "; j += i + 1) { }
        if (j === inputString.length) return true
    }
    return false
}

 */
int main() {
    string inputString = "Look at this example of a correct text";
    cout << boolalpha << beautifulText(inputString, 5, 15);
    return 0;
}
