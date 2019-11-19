// Cho một string, đặt nó trong cặp dấu ngoặc tròn
#include <iostream>
using namespace std;

string encloseInBrackets(string s) {
    return "(" + s + ")";
}

int main() {
    cout << encloseInBrackets("Nihta");
    return 0;
}