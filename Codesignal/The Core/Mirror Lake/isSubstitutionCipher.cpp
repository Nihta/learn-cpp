/**
 * https://app.codesignal.com/arcade/code-arcade/mirror-lake/rNrF4v5etMdFNKD3s/
 * ???
 */
#include <iostream>
#include <vector>
using namespace std;

bool isSubstitutionCipher(string a, string b) {
    vector<char> v1(26, '!');
    vector<char> v2(26, '!');

    for(int i = 0; i < a.length(); ++i)
        if(v1[a[i] - 'a'] == '!' && v2[b[i] - 'a'] == '!') {
            v1[a[i] - 'a'] = b[i];
            v2[b[i] - 'a'] = a[i];
        }
        else {
            if(v1[a[i] - 'a'] != b[i])
                return false;
            if(v2[b[i] - 'a'] != a[i])
                return false;
        }

    return true;
}

int main() {
    cout << boolalpha << isSubstitutionCipher("aabc", "aacb");
    return 0;
}