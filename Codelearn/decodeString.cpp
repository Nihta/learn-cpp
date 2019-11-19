/**
 * Giải mã string
 * s = "3[a]", decodeString(s) = "aaa".
 * s = "3[ab]", decodeString(s) = "ababab".
 * s = "3[b2[ca]]", decodeString(s) = "bcacabcacabcaca".
 * s = "3[a3[b]1[ab]]", decodeString(s) = "abbbababbbababbbab".
*/
#include <iostream>
#include <stack>
using namespace std;

string nhanBanString(string s, int n)
{
    string res;
    while (n--)
        res += s;
    return res;
}

string decodeString(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            st.push(i);
        if (s[i] == ']')
        {
            int start = st.top();
            st.pop();
            int heSoNhan = 0, soChuSoCuaHeSoNhan = 0;
            for (int j = start - 1, heSo = 1; j >= 0; j--, heSo *= 10)
                if (s[j] <= '9' && s[j] >= '0')
                {
                    heSoNhan += (s[j] - '0') * heSo;
                    soChuSoCuaHeSoNhan++;
                }
                else
                    break;
            string tmp = nhanBanString(s.substr(start + 1, i - start - 1), heSoNhan);
            s = s.substr(0, start - soChuSoCuaHeSoNhan) + tmp + s.substr(i + 1, s.size() - i);
            i -= 2 + soChuSoCuaHeSoNhan;
        }
    }
    return s;
}

int main()
{
    cout << decodeString("3[a3[b]1[ab]]"); // abbbababbbababbbab
    return 0;
}
