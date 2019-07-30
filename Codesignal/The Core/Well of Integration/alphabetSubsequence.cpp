// Kiểm tra xem string s có phải bắt nguồn từ string "abcdef...xyz" hay không?
#include <iostream>
using namespace std;

bool alphabetSubsequence(string s) {
    for (int i = 1; i < s.length(); i++)
        if (s[i-1] >= s[i])
            return false;
    return true;
}

int main() {
    cout << boolalpha << alphabetSubsequence("ace"); // true
    return 0;
}