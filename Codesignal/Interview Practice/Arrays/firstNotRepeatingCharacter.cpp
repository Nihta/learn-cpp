/**
 * Cho một string s (1 ≤ s.length ≤ 10^5) bao gồm các chữ cái tiếng Anh thường,
 * tìm và trả về trường hợp đầu tiên của một chữ cái không lặp lại trong đó.
 * Nếu không có ký tự đó, trả về '_'.
*/

#include <iostream>
using namespace std;

char firstNotRepeatingCharacter(string s)
{
    int cnt[26] = {};
    int order[26], sizeOrder = 0;

    for (char ch : s)
        if (cnt[ch - 'a']++ == 0)
            order[sizeOrder++] = ch - 'a';

    for (int i = 0; i < sizeOrder; i++)
        if (cnt[order[i]] == 1)
            return order[i] + 'a';
    return '_';
}

int main()
{
    cout << firstNotRepeatingCharacter("abacabad") << endl;       // 'c'
    cout << firstNotRepeatingCharacter("abacabaabacaba") << endl; // '_'
    cout << firstNotRepeatingCharacter("ngnmomooa") << endl;              // 'g'
    cout << firstNotRepeatingCharacter("abcdefghijklmnopqrstuvwxyziflskecznslkjfabe"); // 'd'
    return 0;
}
