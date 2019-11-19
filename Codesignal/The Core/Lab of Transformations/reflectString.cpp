/**
 * a -> z, b -> y, c -> x, ..., n -> m, m -> n, ..., z -> a
 */
#include <iostream>
using namespace std;

string reflectString(string s) {
    string rule = "";
    for (int i = 'z'; i >= 'a'; i--)
        rule += i;
    for (auto &&ch : s)
        ch = rule[ch - 'a'];
    return s;
}

std::string reflectString2(std::string s) 
{
    for(auto &&ch : s)
        ch = 'z' - (ch - 'a');
    return s;
}


int main() {
    cout << reflectString("nihta"); // mrsgz
    cout << endl << reflectString2("nihta");
    return 0;
}