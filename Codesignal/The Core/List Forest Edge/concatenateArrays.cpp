/**
 * Cho 2 mảng a và b. Ghép mảng b vào mảng a
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> concatenateArrays(vector<int> a, vector<int> b) {
    for (int i : b)
        a.push_back(i);
    return a;
}

vector<int> concatenateArrays2(vector<int> a, vector<int> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5},
                b = {6, 7, 8, 9};
    for (auto i : concatenateArrays(a, b))
        cout << i << ' ';
    cout << endl;

    for (auto i : concatenateArrays(a, b))
        cout << i << ' ';
    cout << endl;
    return 0;
}