#include <iostream>
#include <regex>
using namespace std;

bool isMAC48Address(string inpS) {
    regex re("([0-9a-fA-F]{2}[-]){5}([0-9a-fA-F]{2})");
    return regex_match(inpS, re);
}

int main() {
    cout << boolalpha << isMAC48Address("E1-00-FF-84-45-E6");
    return 0;
}