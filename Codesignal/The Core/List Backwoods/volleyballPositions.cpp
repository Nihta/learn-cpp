/**
 * Cho đội hình hiện tại của đội bóng chuyền và số lần k đội đội được giao bóng
 * Tìm vị trí ban đầu của mỗi thành viên trong đội biết rằng vị trí thay đổi theo
 * chiều kim đồng hồ mỗi lần giao bóng
 * Xem volleyballPositions.png
 */

#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> volleyballPositions(vector<vector<string>> formation, int k)
{
    vector<vector<string>> res = formation;
    k %= 6;
    while (k--)
    {
        string a = res[0][1], b = res[1][0], c = res[3][0],
               d = res[2][1], e = res[3][2], f = res[1][2];
        res[1][0] = a;
        res[3][0] = b;
        res[2][1] = c;
        res[3][2] = d;
        res[1][2] = e;
        res[0][1] = f;
    }
    return res;
}

int main()
{
    vector<vector<string>> res = volleyballPositions({{"0", "Nihta", "0"},
                                                      {"Haha", "0", "Hihi"},
                                                      {"0", "Wow", "0"},
                                                      {"Ohh", "0", "Huhu"}},
                                                     10);

    for (auto i : res)
    {
        for (auto j : i)
            cout << j << "\t";
        cout << endl;
    }

    return 0;
}
