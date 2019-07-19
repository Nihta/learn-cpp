/*
Xem một từ (word) như một chuỗi các chữ cái tiếng Anh liên tiếp.
Tìm từ dài nhất trong string đã cho
 */
#include <iostream>
#include <set>
#include <regex>
using namespace std;

string longestWord(string text)
{
    // Tách các word thêm vào set(loại bỏ phần tử lặp)
    set<string> seT;
    string word = "";
    for (char c : text)
    {
        if(isalpha(c))
            word += c;
        else
        {
            if(word != "")
                seT.insert(word);
            word = "";
        }
    }
    seT.insert(word);

    // Tìm word có độ dài lớn nhất
    int maxLen = 0;
    string longestS = "";
    for (string s : seT)
        if(s.length() > maxLen)
            maxLen = s.length(),
            longestS = s;

    return longestS;
}

string longestWord2(string text)
{
    regex re("[A-Za-z]+");

    auto begin = sregex_iterator(text.begin(), text.end(), re);
    auto end = sregex_iterator();

    int maxLen = 0;
    string maxStr = "";
    for (sregex_iterator i = begin; i != end; ++i)
    {
        smatch match = *i;
        string match_str = match.str();
        if(match_str.length() > maxLen)
            maxLen = match_str.length(),
            maxStr = match_str;
    }
    return maxStr;
}

int main()
{
    string s ="Ready[[[, steady, go!";
    cout << longestWord(s); // steady
    return 0;
}