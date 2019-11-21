// Đảo ngược các phần tử trên hai đường chéo chính
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reverseOnDiagonals(vector<vector<int>> v)
{
    int size = v.size();
    for (int i = 0; i < size / 2; i++)
        swap(v[i][i], v[size - 1 - i][size - 1 - i]);
    for (int i = 0; i < size / 2; i++)
        swap(v[i][size - 1 - i], v[size - 1 - i][i]);
    return v;
}

int main()
{
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    for (auto i : reverseOnDiagonals(v))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
