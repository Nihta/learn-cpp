/**
 * Cho một mảng gồm 2^k số nguyên (đối với một số nguyên k), thực hiện các thao tác sau cho đến khi mảng chỉ chứa một phần tử:
 *     Lần lặp thứ 1, 3, 5, ... (base-1) thay thế từng cặp phần tử liên tiếp
 *     bằng tổng của chúng.
 *     Trong các lần lặp thứ 2, 4, 6, ... thay thế từng cặp phần tử liên tiếp
 *     bằng tích của chúng.
 * Sau khi thuật toán kết thúc, sẽ có một phần tử duy nhất còn lại trong mảng.
 * Trả lại phần tử đó.
 */
#include <iostream>
#include <vector>
using namespace std;

int arrayConversion(vector<int> v) {
    vector<int> tmp;
    int step = 0;
    while (v.size() != 1) {
        tmp = {};
        if (++step%2)
            for (int i = 1; i < v.size(); i+=2)
                tmp.push_back(v[i-1] + v[i]);
        else
            for (int i = 1; i < v.size(); i+=2)
                tmp.push_back(tmp[i-1] * tmp[i]);
        v = tmp;
    }
    return v[0];
}

int main() {
    cout << arrayConversion({1, 2, 3, 4, 5, 6, 7, 8});
    return 0;
}