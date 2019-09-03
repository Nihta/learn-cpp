// Kiểm tra năm nhuận
#include <iostream>
#include <vector>
using namespace std;

bool leapYear(int y) {
    return y % (y%5 ? 4 : 16) < 1;
}

int main() {
    cout << boolalpha << leapYear(2000) << "\n" << leapYear(100);
    return  0;
}