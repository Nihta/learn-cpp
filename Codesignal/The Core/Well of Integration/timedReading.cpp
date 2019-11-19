/**
 * Đếm số lượng từ có length <= maxLength
 */
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int timedReading(int maxLength, string text) {
    string word = "";
    int count = 0;
    for (char ch : text + " ") // text Cộng như vậy nó mới tính từ cuối cùng
        if(isalpha(ch))
            word += ch;
        else
        {
            if (!word.empty() && word.length() <= maxLength)
                count++;
            word.clear();
        }

    return count;
}

int timedReading2(int maxLength, string text) {
    int count = 0;
    regex word_regex("[a-zA-Z]+");
    auto words_begin = sregex_iterator(text.begin(), text.end(), word_regex), words_end = sregex_iterator();

    for (auto i = words_begin; i != words_end; i++)
        if ((*i).str().size() <= maxLength)
            count++;

    return count;
}

int main() {
    cout << timedReading(4, "The Fox asked the stork, 'How is the soup?'"); // 7
    cout << endl << timedReading(3, "a bc def vvvv ccccc llllll"); // 3
    return 0;
}