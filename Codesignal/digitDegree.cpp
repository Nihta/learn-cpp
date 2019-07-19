/*
Định nghĩa digitDegree của một số nguyên dương là số lần chúng ta cần thay thế
số này bằng tổng các chữ số của nó cho đến khi chúng ta có được một số có một chữ số
Cho một số nguyên, tìm digitDegree của nó
 */
#include <iostream>
using namespace std;

int digitDegree(int n)
{
    int result = 0;

    while (n/10 != 0)
    {
        ++result;
        int tmp = n, sum = 0;
        while(tmp != 0)
            sum += tmp%10, tmp/=10;
        n = sum;
    }

    return result;
}

int main()
{
    cout << digitDegree(73); // 2
    return 0;
}