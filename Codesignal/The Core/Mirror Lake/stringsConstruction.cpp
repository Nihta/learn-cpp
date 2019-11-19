/**
 * Có bao nhiêu string bằng a có thể được xây dựng bằng các chữ cái trong
 * string b? Mỗi chữ cái chỉ có thể được sử dụng một lần và trong một string.
 * a và b đều là chữ thường
 */
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int stringsConstruction(string a, string b) {
    int countA[26] = {}, countB[26] = {}, result = 0;
    for (char c : a)
        countA[c-'a']++;
    for (char c : b)
        countB[c-'a']++;
    while (1)
    {
        for(char c : a)
            if(countB[c-'a'] < 1)
                return result;
            else
                countB[c-'a']--;
        result++;
    }
}

int stringsConstruction2(string a, string b) {
    set<char> ch;
    for(char i : a)
        ch.insert(i);

    vector<char> cCh;
    for(char i : ch)
        cCh.push_back(count(b.begin(),b.end(),i)/count(a.begin(), a.end(),i));

    return *min_element(cCh.begin(), cCh.end());
}


int main() {
    cout << stringsConstruction("abc", "abcbcaabceezzvc") << endl;
    cout << stringsConstruction2("abc", "abcbcaabceezzvc");
    return 0;
}