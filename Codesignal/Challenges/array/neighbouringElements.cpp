/**
 * Tìm các cặp phần tử lân cận (theo hàng hoặc cột) bằng nhau
*/

#include <iostream>
#include <vector>
using namespace std;

int neighbouringElements(vector<vector<int>> v)
{
    int res = 0;
    // Check theo hàng
    for (vector<int> i : v)
        for (int j = 1; j < i.size(); j++)
            if (i[j] == i[j-1])
                res++;
    // Check theo cột
    for (int j = 0; j < v[0].size(); j++)
        for (int i = 1; i < v.size(); i++)
            if (v[i][j] == v[i-1][j])
                res++;
    return res;
}

int main()
{
    cout << neighbouringElements({{0, 1, 2, 3},
                                  {1, 2, 3, 0},
                                  {2, 3, 1, 0}}); // 1
    return 0;
}
