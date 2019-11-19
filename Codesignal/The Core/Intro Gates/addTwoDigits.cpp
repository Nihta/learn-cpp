// Tính tổng các chữ số của số có 2 chữ số
#include <iostream>
using namespace std;

int addTwoDigits(int n) {
    return n/10 + n%10;
}

int main() {
    cout << addTwoDigits(19);
    return 0;
}