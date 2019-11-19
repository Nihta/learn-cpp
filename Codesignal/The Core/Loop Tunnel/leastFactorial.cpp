/**
 * Cho một số nguyên n, tìm k tối thiểu sao cho:
 *     k = m! = 1 * 2 * ... * m
 *     k >= n
 */
#include <iostream>
using namespace std;

int leastFactorial(int n) {
    int k = 1, i = 1;
    while(k < n)
        k *= i++;

    return k;
}

int main() {
    cout << leastFactorial(22); // 24 = 4!
    return 0;
}