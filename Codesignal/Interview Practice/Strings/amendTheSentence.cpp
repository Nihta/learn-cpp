/**
 * Ai đó đã quên đặt khoảng trắng giữa các từ khác nhau và vì một lý do nào đó
 * họ viết hoa chữ cái đầu tiên của mỗi từ.
 * Nhiệm vụ của bạn là: đặt một khoảng trống giữa các từ và chuyển đổi chữ hoa
 * thành chữ thường.
*/

#include <iostream>
#include <string>
using namespace std;

string amendTheSentence(string s)
{
    string result = "";
    for (auto ch : s)
        if ('A' <= ch && ch <= 'Z')
        {
            if (result.length() != 0)
                result += " ";
            result += (ch + 'a' - 'A');
        }
        else
            result += ch;
    return result;
}

int main()
{
    cout << amendTheSentence("CodesignalIsAwesome"); // "codesignal is awesome"
    return 0;
}
