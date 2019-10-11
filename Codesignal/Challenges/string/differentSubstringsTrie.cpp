// Cho một string. Tìm tất cả các substing khác nhau (không rỗng) của nó

#include <iostream>
#include <set>
using namespace std;

int differentSubstringsTrie(string s)
{
    set<string> sub;
    for (int i = 1; i <= s.size(); i++)
        for(int j = 0; j <= s.size()-i; j++)
            sub.insert(s.substr(j, i));
    return sub.size();
}

int main() {
    cout << differentSubstringsTrie("abac") << endl; // 9
    cout << differentSubstringsTrie("abacaba") << endl; // 21
    return  0;
}
