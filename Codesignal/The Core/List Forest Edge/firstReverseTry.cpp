/**
 * Hoán đổi vị trí đầu tiên và cuối cùng của mảng
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> firstReverseTry(vector<int> v) {
    if(v.size() < 2)
        return v;
    swap(v.front(), v.back());
    return v;
}

int main() {
    vector<int> v = {1, 2, 2, 2, 9};
    for (int i : firstReverseTry(v))
        cout << i << " ";
    return 0;
}