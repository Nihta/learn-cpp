/*
Cho 1 string, kiểm tra xem các ký tự của nó có thể được sắp xếp lại để tạo thành một palindrome(Xâu đối xứng)

Input:  "abab"
Output: true (vì abba là 1 xâu đối xứng)
*/
#include <iostream>
using namespace std;

/*
    Một xâu có thể sắp xếp lại để trở thành xâu đối xứng khi tần suất các kí tự xuất hiện của nó là số lẻ nhiều nhất 1 lần (còn lại phải là chẵn)
*/
bool palindromeRearranging(string s)
{
    // Tính tần suất xuất hiện của các kí tự A -> z
    int a['z'+1] = {};
    for (auto &&ch : s)
        ++a[ch];

    int check = 0;
    for (auto &&i : a)
        if(i%2 != 0)
            ++check;

    return check <= 1;
}



int main()
{
    cout << std::boolalpha << palindromeRearranging("abab");
    return 0;
}