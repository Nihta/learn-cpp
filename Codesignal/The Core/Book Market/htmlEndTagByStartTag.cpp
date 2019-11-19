// Tìm thẻ kết thúc cho đoạn html
#include <iostream>
using namespace std;

string htmlEndTagByStartTag(string s) {
    return "</" + s.substr(1, s.find_first_of("> ") - 1) + ">";
}

int main() {
    cout << htmlEndTagByStartTag("<button type='button' disabled>");
    return 0;
}