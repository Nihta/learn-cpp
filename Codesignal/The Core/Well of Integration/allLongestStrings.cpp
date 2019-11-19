// In ra những string có chiều dài lớn nhất
#include <iostream>
#include <vector>
using namespace std;

vector<string> allLongestStrings(vector<string> v) {
    int maxLen = 0;
    for (string s : v)
        if (s.length() > maxLen)
            maxLen = s.length();
    vector<string> result;
    for (string s : v)
        if (s.length() == maxLen)
            result.push_back(s);
    return result;
}

int main() {
    vector<string> v = {"abc", 
                        "aa", 
                        "a", 
                        "vcl", 
                        "xyz"};
    for (string s : allLongestStrings(v))
    cout << s << endl;
    return 0;
}