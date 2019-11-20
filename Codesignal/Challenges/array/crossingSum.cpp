/**
 * Cho một ma trận hình chữ nhật.
 * Tính tổng các phần tử nằm trên hàng a và cột b.
*/
#include <iostream>
#include <vector>
using namespace std;

int crossingSum(std::vector<std::vector<int>> m, int a, int b) {
    int res = 0;
    for (int i = 0; i < m[0].size(); i++)
        res += m[a][i];
    for (int i = 0; i < m.size(); i++)
        res += m[i][b];
    res -= m[a][b]; // Lặp 2 lần
    return res;
}

int main() {
    cout << crossingSum({
        {1,1,1,1},
        {2,2,2,2},
        {3,3,3,3}
    }, 1, 3); // 12
    return  0;
}
