/**
 * Xóa tất cả các kí tự xuất hiện nhiều lần trong string
*/
#include <iostream>
#include <map>
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

int main() {
    cout << removeDuplicateCharacters("abceeffggghhhhhhhik");
    return 0;
}