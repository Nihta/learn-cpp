/**
 * Cho một string, kiểm tra xem nó có thể trở thành palindrome thông qua thay đổi kiểu (hoa, thường) một vài chữ cái (có thể hoặc không).
 */
#include <iostream>
using namespace std;

bool isCaseInsensitivePalindrome(string s) {
    for (int i = 0; i<s.size()/2; i++)
        if (tolower(s[i]) != tolower(s.at(s.size() - 1 - i)))
            return false;
    return true;
}


int main() {
    cout << boolalpha << isCaseInsensitivePalindrome("AacBCaa"); // true
    return 0;
}