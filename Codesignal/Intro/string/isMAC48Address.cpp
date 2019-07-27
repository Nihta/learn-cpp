// Kiểm tra địa chỉ MAC-48 (IEEE 802)
#include <iostream>
#include <regex>
using namespace std;

bool isMAC48Address(string inputString) {
    regex re("^([0-9a-fA-F]{2}[-]){5}([0-9a-fA-F]{2})$");
    return regex_match(inputString, re);
}

int main()
{
    string s = "00-12-34-99-AB-AE";
    cout << boolalpha << isMAC48Address(s);
    return 0;
}