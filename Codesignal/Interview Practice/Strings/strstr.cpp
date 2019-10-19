/**
 * Cho hai string s và x: 1 ≤ s.length, x.length ≤ 10e6
 * Tìm sự xuất hiện đầu tiên của chuỗi x trong s (index)
 * Nếu không return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

// c++17 std::boyer_moore_searcher
int strstr(string s, string x)
{
    for (int i = 0; i <= s.length() - x.length(); i++)
        if (x.front() == s[i] && x.back() == s[i + x.length() - 1])
        {
            string tmp(s.begin() + i, s.begin() + i + x.length());
            if (x == tmp)
                return i;
        }
    return -1;
}

int main()
{
    cout << strstr("CodefightsIsAwesome", "IA") << endl;  // -1
    cout << strstr("CodefightsIsAwesome", "IsA") << endl; // 10
    cout << strstr("a", "a") << endl;                     // 0
    return 0;
}
