/*
Cho 1 string.
Kiểm ra nó có phải là địa chỉ IPv4 hay không.
IPv4 có dạng a.b.c.d với 0 <= a, b, c, d <= 255
 */
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;


bool isIPv4Address(string s)
{
    int a[4] = {-1, -1, -1, -1,};
    char ch[3], check = ' ';
    stringstream ss;
    ss.str(s);
    ss >> a[0] >> ch[0] >> a[1] >> ch[1] >> a[2] >> ch[2] >> a[3] >> check;

    // Kiểm tra xem có kí tự thừa hay không
    if(check != ' ')
        return false;

    // Kiểm tra 3 kí tự phân tách số có phải là '.' hay không
    for (int i = 0; i < 3; ++i)
        if(ch[i] != '.')
            return false;
    
    // Kiểm tra 0 <= số <= 255
    for(int i = 0; i < 4; ++i)
        if(a[i] < 0 || a[i] > 255)
            return false;

    return true;
}

bool isIPv4Address2(string inputString) {
    regex reg("(([1]?[0-9]?[0-9])|([2][0-5][0-5])).(([1]?[0-9]?[0-9])|([2][0-5][0-5])).(([1]?[0-9]?[0-9])|([2][0-5][0-5])).(([1]?[0-9]?[0-9])|([2][0-5][0-5]))");
    return regex_match(inputString, reg);
}


int main()
{
    vector<string> input = {
        "0.0.0.0",
        "255.255.255.255",
        "2.5.25.225",
        "300.255.255.0",
        "1..2.3.4",
        "1..2.3.4.5",
        "1.2.3z.4",
        ".1.2.3.4",
        "1234",
        "1.2.3.4abc",
        "1.2.3.4.",
        "a1.2.3.4",
        "0.0.0.0.0",
        "1e2.3.4"
    };
    string s = "14.254.255.0";
    cout << boolalpha;
    for (auto &&s : input)
    {
        cout  << s << " : "<< isIPv4Address(s) << "\n\n";
    }
}