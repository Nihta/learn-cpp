/*
Cho một string, nhiệm vụ của bạn là thay thế từng ký tự của nó
bằng một ký tự tiếp theo trong bảng chữ cái tiếng Anh;
tức là thay a bằng b, thay b bằng c, ... (z sẽ được thay thế bằng a)
 */

#include <iostream>
using namespace std;

string alphabeticShift(string s) {
    for(int i = 0; i < s.length(); ++i)
        s[i] = (s[i] == 'z') ? 'a' : s[i] + 1;
    return s;
}

int main()
{
    string s ="abcxyz";
    cout << alphabeticShift(s);
    return 0;
}