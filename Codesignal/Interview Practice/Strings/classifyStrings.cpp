/**
 * Bạn muốn chia string thành ba loại: good, bad, or mixed.
 * Nếu một string có 3 nguyên âm liên tiếp hoặc 5 phụ âm liên tiếp hoặc cả hai
 * thì nó được phân loại thành bad, ngược lại nó được phân loại là good.
 * Nguyên âm bao gồm: a, e, i, o, u và tất cả các chữ cái khác là phụ âm.
 * String cũng có thể chứa ký tự '?', nó có thể được thay thế bằng nguyên âm
 * hoặc phụ âm. Điều này có nghĩa là string "?aa" có thể bad nếu '?' là một
 * nguyên âm hoặc good nếu nó là một phụ âm. Loại string này là loại mixed.
 * Viết một hàm xác định loại của string s (1 ≤ s.length ≤ 50).
 * Lưu ý: '?' trong "???" không đồng nghĩ là 3 kí tự giống nhau
*/

#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Thay thế 1 kí a thành b trong string s
string replaceOne(const string s, char a, char b)
{
    string tmp = s;
    for (auto &&ch : tmp)
        if (ch == a)
        {
            ch = b;
            break;
        }
    return tmp;
}

string classifyStrings(string s)
{
    // .* (0 hoặc nhiều kí tự bất kì trừ kí tự ngắt dòng)
    regex bad(".*([aeiou]{3}|[^aeiou//?]{5}).*");
    // Nếu có 3 nguyên âm liên tiếp hoặc 5 phụ âm liên tiếp thì chắc chắn là bad
    if (regex_match(s, bad))
        return "bad";

    if (s.find('?') != string::npos) // Nếu như trong string có '?'
    {
        // Xét 2 trường hợp thay thế '?' bằng nguyên âm và phụ âm
        string vow = classifyStrings(replaceOne(s, '?', 'a')); // 'a' đại diện cho nguyên âm
        string con = classifyStrings(replaceOne(s, '?', 'b')); // 'b' đại diện phụ âm
        if (vow == con)
            return vow;
        else
            return "mixed";
    }
    return "good";
}

int main()
{
    // good
    cout << classifyStrings("aa") << " "
         << classifyStrings("bbbb") << " "
         << classifyStrings("??") << endl;

    // bad
    cout << classifyStrings("aa?bbbb") << " "
         << classifyStrings("aa?bbb?a?bbb?aa") << " "
         << classifyStrings("baaabbb") << " "
         << classifyStrings("abbbbbac") << " "
         << classifyStrings("aaabbbbb") << endl;

    // mixed
    cout << classifyStrings("???") << " "
         << classifyStrings("?????") << " "
         << classifyStrings("?aa?bbb") << " "
         << classifyStrings("?aa") << endl;
    return 0;
}
