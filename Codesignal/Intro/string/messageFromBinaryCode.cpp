// 8 bit liền nhau tương ứng với 1 kí tự trong ASCII
#include <iostream>
#include <bitset>
using namespace std;

string messageFromBinaryCode(string code)
{
    string result = "", tmp = "";
    while (code.length() != 0)
    {
        // Chuyển code (cơ số 2) sang c (cơ số 10)
        tmp = code.substr(0, 8);
        int c = 0;
        for (int i = 7, mu = 1; i >= 0; i--, mu*=2)
            c += (tmp[i] - '0') * mu;

        result += char(c);
        code.erase(0, 8);
    }

    return result;
}

string messageFromBinaryCode2(string code)
{
    string result;
    for(int i = 0; i < code.size(); i += 8)
    {
        bitset<8> c (code.substr(i, 8));
        result += c.to_ulong();
    }
    return result;
}

int main()
{
    string s = "010010000110010101101100011011000110111100100001"; // Hello!
    cout << messageFromBinaryCode(s) << endl;
    cout << messageFromBinaryCode2(s) << endl;
    return 0;
}