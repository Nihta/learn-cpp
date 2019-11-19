// Cho một vector. Tính tổng các phần tử của nó cho đến khi gặp phải số 0
#include <iostream>
#include <vector>
using namespace std;

int houseNumbersSum(vector<int> v) {
    int result = 0;
    for (int i : v)
        if (i == 0)
            return result;
        else
            result += i;
    return result;
}

int main() {
    cout << houseNumbersSum({5, 1, 2, 3, 0, 1, 5, 0, 2}); // 11
    return 0;
}