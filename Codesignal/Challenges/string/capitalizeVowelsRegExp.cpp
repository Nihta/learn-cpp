/**
 * Cho một chuỗi, viết hoa mỗi nguyên âm chữ thường (a, e, i, o, u, y) trong đó.
*/
#include <iostream>
using namespace std;

std::string capitalizeVowelsRegExp(std::string input)
{
    string vowel = "aeiouy";
    for (auto &&ch : input)
        if (vowel.find(ch, 0) != string::npos)
            ch -= ('a' -'A');
    return input;
}

int main()
{
    cout << capitalizeVowelsRegExp("There are 12 points") << endl; // ThErE ArE 12 pOInts
    return 0;
}
