// Liệt kê các cặp có tổng bằng A + number
#include <iostream>
#include <vector>
using namespace std;

vector<string> newNumeralSystem(char number) {
    vector<string> result;
    string s = "A + ";
    s += number;
    while (s[0] <= s[4]) {
        result.push_back(s);
        s[0]++;
        s[4]--;
    }
    return result;
}

int main() {
    for (auto i : newNumeralSystem('G'))
        cout << i << endl;
    return 0;
}