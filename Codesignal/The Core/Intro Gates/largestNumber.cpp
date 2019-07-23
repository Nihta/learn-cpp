// Trả về số lớn nhất chứa n chữ số
#include <iostream>
#include <math.h>
using namespace std;

int largestNumber(int n) {
    return pow(10, n) - 1;
}

int main() {
    cout << largestNumber(3);
    return 0;
}