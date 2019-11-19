/*
Cho một ma trận hình chữ nhật chỉ chứa các chữ số, hãy tính số lượng hình vuông 2 × 2 khác nhau trong đó.

[1 2]  là       [2 2]
[2 2]  khác     [2 2]
 */
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

int differentSquares(vector<vector<int>> v)
{
    set<string> count;
    for (int i = 1; i < v.size(); ++i)
        for (int j = 1; j < v[0].size(); ++j)
        {
            string tmp = "";
            tmp += v[i-1][j-1],
            tmp += v[i-1][j],
            tmp += v[i][j-1],
            tmp += v[i][j];
            count.insert(tmp);
        }
    return count.size();
}

int differentSquares2(vector<vector<int>> v) {
    set<tuple<int, int, int, int>> count;
    for (int i = 1; i < v.size(); i++)
    for (int j = 1; j < v[0].size(); j++)
        count.emplace(make_tuple(v[i-1][j-1],
                                     v[i][j-1],
                                     v[i-1][j],
                                     v[i][j]));
    return count.size();
}


int main() {
    vector<vector<int>> v = {{1,2,1}, // 6
                            {2,2,2},
                            {2,2,2},
                            {1,2,3},
                            {2,2,1}};
    cout << differentSquares(v) << endl;
    cout << differentSquares2(v);
    return 0;
}
