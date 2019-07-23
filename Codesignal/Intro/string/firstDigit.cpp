// Tìm số đầu tiên xuất hiện trong string
#include <iostream>
using namespace std;

char firstDigit(string s)
{
    for(char c : s)
        if(isdigit(c))
            return c;
}


int main()
{
    string s = "abc123xyz";
    cout << firstDigit(s);
    return 0;
}