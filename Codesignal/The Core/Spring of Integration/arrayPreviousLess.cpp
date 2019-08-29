/**
 * Cho một mảng các số nguyên. Với mỗi vị trí i, tìm kiếm trong các phần tử
 * trước đó phần tử khác nó gần nhất có giá trị nhỏ hơn. Lưu giá trị này ở vị
 * trí i trong mảng trả lời.
 * Nếu không tìm thấy giá trị nào như vậy, hãy lưu -1.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> arrayPreviousLess(vector<int> v) {
    vector<int> result(1, -1);
    int min = v[0];
    for (int i = 1; i < v.size(); i++) {
        result.push_back(-1);
        for (int j = i-1; j >= 0; j--)
            if (v[i] != v[j])
                if (v[j] < v[i]) {
                    result[i] = v[j];
                    break;
                }
    }
    return result;
}

int main() {
    for (auto i : arrayPreviousLess({3, 5, 2, 4, 5})) // {-1, 3, -1, 2, 4}
        cout << i << ' ';
    cout << endl;
    return 0;
}