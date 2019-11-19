/**
 * Cho các số nguyên a và b, xác định xem mã giả sau có dẫn đến một infinite loop không?
 *    while a is not equal to b do
 *        increase a by 1
 *        decrease b by 1
 */
#include <iostream>
using namespace std;

bool isInfiniteProcess(int a, int b) {
    if (a > b)
        return true;
    return (a + b)%2;
}

int main() {
    cout << boolalpha << isInfiniteProcess(2, 4) << endl;
    cout << isInfiniteProcess(2, 3) << endl;
    return 0;
}