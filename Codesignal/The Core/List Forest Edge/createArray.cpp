/**
 * Trả về 1 mảng gồm n số 1
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> createArray(int size) {
    return vector<int>(size, 1);
}

int main() {
    for(int i : createArray(5))
        cout << i << " ";
    return 0;
}