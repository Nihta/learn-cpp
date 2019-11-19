// Đếm số lượng kí tự khác nhau trong string
#include <iostream>
#include <set>
using namespace std;

int differentSymbolsNaive(string s)
{
    set<int> se;
    for(char c : s)
        se.insert(c);
    return se.size();
}


int main()
{
    string s = "qwertyuioplkjhgfdsazxcvbnmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
    cout << differentSymbolsNaive(s);
    return 0;
}