/**
 * https://kipalog.com/posts/C---lambda
 * Alphanumeric của chuỗi được định nghĩa như sau: Mỗi chuỗi được coi là một chuỗi tokens, trong đó mỗi mã là một chữ cái hoặc một số. Ví dụ: tokens của chuỗi "ab01c004" là [a, b, 01, c, 004]. Để so sánh hai chuỗi, trước tiên chúng tôi sẽ chia chúng thành các tokens và sau đó so sánh các cặp tokens tương ứng với nhau (ví dụ: so sánh tokens đầu tiên của chuỗi đầu tiên với tokens đầu tiên của chuỗi thứ hai, v.v.).
 * Dưới đây là cách so sánh tokens:
 *    Nếu một chữ cái được so sánh với một chữ cái khác, thứ tự chữ cái thông
 *    thường được áp dụng.
 *    Một số luôn được coi là nhỏ hơn một chữ cái.
 *    Khi hai số được so sánh, giá trị của chúng được so sánh. Số không hàng
 *    đầu (nếu có) được bỏ qua.
 * Nếu tại một thời điểm nào đó, một chuỗi không còn tokens trong khi chuỗi còn
 * lại vẫn còn, chuỗi có ít tokens hơn được coi là nhỏ hơn. Nếu hai chuỗi s1 và
 * s2 có vẻ bằng nhau, hãy xem xét chỉ số i nhỏ nhất sao cho tokens(s1)[i] và
 * tokens(s2)[i] (trong đó tokens[i] là tokens thứ i của chuỗi) chỉ khác nhau
 * bởi số lượng các số 0 đứng đầu. Nếu không có i như vậy tồn tại, các chuỗi
 * thực sự bằng nhau. Mặt khác, chuỗi có tokens thứ i có nhiều số 0 đứng đầu
 * được coi là nhỏ hơn.
 * Dưới đây là một số ví dụ về so sánh các chuỗi sử dụng alphanumeric:
 * "a" < "a1" < "ab"
 * "ab42" < "ab000144" < "ab00144" < "ab144" < "ab000144x"
 * "x11y012" < "x011y13"
 * Nhiệm vụ của bạn là trả về true nếu s1 hoàn toàn nhỏ hơn s2.
 */
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

bool alphanumericLess(string s1, string s2) {
    auto tokenize = [re = regex("([a-z])|([0-9]+)")](const auto& s) {
        vector<pair<char, unsigned long>> t;
        vector<int> lz;
        for_each(sregex_iterator(begin(s), end(s), re), sregex_iterator(),
                [&](const auto& m) {
                    t.emplace_back(m.str(1)[0], stoul('0' + m.str(2)));
                    lz.emplace_back(-strspn(m.str(2).c_str(), "0"));
                });
        return pair{t, lz};
    };
    return tokenize(s1) < tokenize(s2);
}

int main() {
    cout << boolalpha << alphanumericLess("ab000144", "ab00144"); // true
    return 0;
}