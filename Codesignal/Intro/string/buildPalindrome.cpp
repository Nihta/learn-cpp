/*
Cho một string, tìm string ngắn nhất có thể đạt được bằng cách thêm các ký tự vào cuối string ban đầu để biến nó thành một palindrome (string đối xứng)
 */
#include <iostream>
#include <algorithm>
using namespace std;

string buildPalindrome(string s)
{
    int i = 0;
    while (s != string(s.rbegin(), s.rend()))
        // Thử chèn lần lượt s[0], s[1][0], s[2]s[1]s[0], ...
        s.insert(s.end() - i, s[i]), ++i;
    return s;
}


int main()
{
    cout << buildPalindrome("abcdefed");
    return 0;
}