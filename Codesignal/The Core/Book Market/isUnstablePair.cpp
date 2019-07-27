// Như return
#include <iostream>
using namespace std;

bool isUnstablePair(string a, string b) {
    string c, d;
    for (char i : a)
        c += tolower(i);
    for (char i : b)
        d += tolower(i);
    return (a < b && c > d) || (a > b && c < d);
}

int main() {
    cout << boolalpha << isUnstablePair("aa", "AAB");
    return 0;
}