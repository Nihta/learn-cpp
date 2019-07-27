// Danh từ riêng luôn bắt đầu bằng chữ in hoa, theo sau là chữ nhỏ.
#include <iostream>
using namespace std;

string properNounCorrection(string noun) {
    noun[0] = toupper(noun[0]);
    for (int i = 1; i < noun.size(); i++)
        noun[i] = tolower(noun[i]);
    return noun;
}

int main() {
    cout << properNounCorrection("niHtA");
    return 0;
}