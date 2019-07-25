/**
 * Xóa các phần tử nằm trong khoảng l và r
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> removeArrayPart(vector<int> v, int l, int r) {
    v.erase(v.begin() + l, v.begin() + r + 1);
    return v;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : removeArrayPart(v, 0, 5))
        cout << i << ' ';
    cout << endl;
    return 0;
}
