#include <iostream>
using namespace std;

// Hàm kiểm tra xâu đối xứng
bool checkPalindrome(std::string inputString) {
    int lenS = inputString.length();
    for(int i = 0; i < lenS/2; i++) 
        if(inputString[i] != inputString[lenS-1-i]) 
            return false;
    return true;
}

int main() {
    string s;
    s = "123454321";
    if ( checkPalindrome(s) )
        cout << s << " la xau doi xung" << endl;
    else
        cout << s << " khong phai xau doi xung" << endl;
    return 0;
}