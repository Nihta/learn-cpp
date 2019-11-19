/**
 * Xác định có thể thu được string đã cho bằng cách ghép một string với
 * chính nó hay không?
 */
#include <iostream>
using namespace std;

bool isTandemRepeat(string s) {
    if (s.length()%2 != 0)
        return false;
    int l = s.length()/2;
    return s.substr(0, l) == s.substr(l, l);
}

int main() {
    cout << boolalpha << isTandemRepeat("NihtaNihta");
    return 0;
}