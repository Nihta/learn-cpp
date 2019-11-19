/**
 * Tính hiệu của tổng bình phương các số chẵn và tổng bình phương các số lẻ
 * trong phạm vi 1 -> k
 * Ví dụ:    k = 5 -> (2^2 + 4^2) - (1^2 + 3^2 + 5^2) = -15
 */
#include <iostream>
using namespace std;

int appleBoxes(int k) {
    int yellow = 0, red = 0;
    for(int i = 1; i <= k; i++)
        if(i%2 == 1)
            yellow += i*i;
        else
            red += i*i;
    return red - yellow;
}

int main() {
    cout << appleBoxes(5); // -15
    return 0;
}