/**
 * Giải mã hóa tin nhắn s.
 * Cách mã hóa:
 *    letter 0: t -> 19 -> t;
 *    letter 1: th -> (19 + 7) % 26 -> 0 -> a;
 *    letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;
 *    etc.
 */
#include <iostream>
using namespace std;

string cipher26(string s) {
    int sum = 0;
    for (auto  &&ch : s) {
        int x = 0;
        while ((x + sum)%26 != ch - 'a')
            x++;
        ch = (x + 'a');
        sum += x;
    }
    return s;
}

string cipher262(string s) {
    int sum = 0;
    for(auto &c : s) {
        c = (((c - 'a') + 26 - sum) % 26) + 'a';
        sum = (sum + (c-'a')) % 26;
    }
    return s;
}

int main() {
    cout << cipher26("taiaiaertkixquxjnfxxdh"); // thisisencryptedmessage
    cout << endl << cipher262("taiaiaertkixquxjnfxxdh");
    return 0;
}