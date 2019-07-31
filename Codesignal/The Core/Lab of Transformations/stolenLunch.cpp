/**
 * Giải note đã mã hóa.
 * Cách mã hóa: tất cả các chữ số trong đó được thay thế bằng các chữ cái và
 * ngược lại, chữ số 0 được thay thế bằng 'a', 1 được thay thế bằng 'b', v.v., với chữ số 9 được thay thế bằng 'j'.
 */
#include <iostream>
#include <vector>
using namespace std;

string stolenLunch(string note) {
    // Quy tắc mã hóa
    vector<char> rule;
    for (char i = 'a'; i < 'a'+9; i++)
        rule.push_back(i);
    rule.push_back('j');

    for (auto &&c : note)
    {
        // Nếu là chữ số chuyển thành chữ (theo rule)
        if (isdigit(c)) {
            c = rule[c - '0'];
            continue;
        }
        // Nếu là chữ (trong rule) chuyển thành chữ số
        for (int i = 0; i <= 9; i++)
            if (c == rule[i])
                c = '0' + i;
    }

    return note;
}

int main() {
    //                   you'll never guess it: 2390
    cout << stolenLunch("you'll n4v4r 6u4ss 8t: cdja");
    return 0;
}