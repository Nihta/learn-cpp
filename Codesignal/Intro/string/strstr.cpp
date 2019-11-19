/*
    Không sử dụng hàm chức năng tích hợp
    Tìm vị trí xuất hiện đầu tiên của string x trong string s
*/
#include <iostream>
using namespace std;

// c++17 std::boyer_moore_searcher
int strstr(string s, string x) {
    for(int i = 0; i <= s.length() - x.length(); ++i)
    {
        if(s[i] == x[0] && s[i+x.length()-1] == x[x.length()-1])
        {
            string tmp(s.begin()+i, s.begin()+i+x.length());
            if(tmp == x)
                return i;
        }
    }
    return -1;
}


int main()
{
    string s, x;
    s = "ATErUUeUkVFVNfxfUKtntOErKmZLUpWpHRASdxjUhzzxygmnNnKabPPgPqyvCLSCZObaNNGCXQssfEEDDJIPBwtkMmTniKapBlrd";
    x = "vCLSCZObaNNGCXQssfEEDDJIPBwtkMmTniKa";
    cout << strstr(s, x); // 59
    return 0;
}