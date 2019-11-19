/*
Cho một ecoding, trả về encoding của nó
    "a" -> "a", "b" -> "b", .... "z" -> "z" 
    "aa" -> "2a"
    "bbb" -> "3b"
    "aaabbcaaa" -> "3a2bc3a"
 */
#include <iostream>
using namespace std;

string lineEncoding(string s)
{
    string result = "";
    // i <= s.length() mục đích để thực hiện đoạn (*) khi lặp hết string
    for(int count = 1, i = 1; i <= s.length(); ++i)
        if(s[i-1] == s[i] && i < s.length())
            ++count;
        else // (*)
        {
            count == 1? result += s[i-1] : result += to_string(count) + s[i-1];
            count = 1;
        }

    return result;
}

int main()
{
    string s = "aaabbcaaa";
    cout << lineEncoding(s);
    return 0;
}