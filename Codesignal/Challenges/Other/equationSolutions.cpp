/**
 * Có bao nhiêu cặp số A, B với l <= A, B <= l sao cho A^3 = B^2
 * Lưu ý: A có thể bằng B
*/
#include <iostream>
#include <map>
using namespace std;

int equationSolutions(int l, int r) {
    map<int, int> a, b;
    for (int i = l; i <= r; i++)
    {
        a[i*i*i]++;
        b[i*i]++;
    }
    int res = 0;
    for (auto ita = a.begin(); ita != a.end(); ita++)
        for (auto itb = b.begin(); itb != b.end(); itb++)
            if (ita->first == itb->first)
                res += ita->second * itb->second;
    return res;
}

int main() {
    cout << equationSolutions(1, 4) << endl; // 1
    cout << equationSolutions(0, 10) << endl; // 3
    cout << equationSolutions(-10, 10) << endl; // 5

    return  0;
}
