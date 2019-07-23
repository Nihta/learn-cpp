// Cho một chuỗi, tìm tiền tố (prefix) dài nhất của nó chỉ bao gồm các chữ số.
#include <iostream>
using namespace std;

string longestDigitsPrefix(string inputString)
{
    string s = "";
    for(char c : inputString)
        if(isdigit(c))
            s += c;
        else
            return s;
    return s;
}

int main()
{
    string s = "123abc456789";
    cout << longestDigitsPrefix(s);
    return 0;
}