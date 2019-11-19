/**
 * Xóa tất cả các kí tự xuất hiện nhiều lần trong string
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string removeDuplicateCharacters(string s) {
	map<char, int> charCount;
	string res = "";

	for (auto c : s)
		if (charCount.count(c) != 0)
			++charCount[c];
		else
			charCount[c] = 1;

	for (int i = 0; i < s.size(); i++) {
		if (charCount[s[i]] == 1) {
			res += s[i];
		}
	}
	return res;
}

string removeDuplicateCharacters2(string s) {
	string res;
	for(int c: s)
		if(count(s.begin(), s.end(), c) < 2)
			res += c;
	return res;
}

int main() {
    cout << removeDuplicateCharacters("abceeffggghhhhhhhik") << endl;
	cout << removeDuplicateCharacters2("abceeffggghhhhhhhik");
    return 0;
}
