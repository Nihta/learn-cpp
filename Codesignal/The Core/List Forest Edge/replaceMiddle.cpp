/**
 * Nhiệm vụ của bạn là tìm phần tử giữa của mảng, nếu nó bao gồm hai phần tử
 * thì thay thế 2 phần tử đó bằng tổng của chúng. 
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceMiddle(vector<int> v) {
    if (v.size()%2 == 1)
        return v;
    v.at(v.size()/2 - 1) += v.at(v.size()/2);
    v.erase(v.begin() + v.size()/2);
    return v;
}

int main() {
    vector<int> v = {7, 2, 2, 5, 10, 7};
    for (auto i : replaceMiddle(v))
        cout << i << ' ';
    cout << endl;
    return 0;
}