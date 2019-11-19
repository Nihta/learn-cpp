/*
Một chuỗi được gọi là beautiful nếu số lượng mỗi chữ cái của nó thỏa mãn:
Chữ cái sau (theo thứ tự a->z) xuất hiện không nhiều lần hơn chữ cái trước
Tức là: b xuất hiện không nhiều lần hơn a; c xuất hiện không nhiều lần hơn b ...
Cho một chuỗi (chữ thường), kiểm tra xem nó có là beautiful?
 */
#include <iostream>
using namespace std;

bool isBeautifulString(string inputString)
{
    // Có 26 chữ cái
    int countChar[26] = {};
    // Đếm tần suất xuất hiện các chữ cái
    for (char c : inputString)
        ++countChar[c-'a'];

    // Check
    for(int i = 1; i < 26; ++i)
        if(countChar[i-1] < countChar[i])
            return false;

    return true;
}

int main()
{
    cout << boolalpha << isBeautifulString("aaabbbccd") << endl;
    cout << boolalpha << isBeautifulString("aaabbz");
    return 0;
}