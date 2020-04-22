// Kiểm tra một vuông có là Identity matrix (ma trận đơn vị) hay không?
#include <iostream>
#include <vector>
using namespace std;

bool isIdentityMatrix(std::vector<std::vector<int>> m)
{
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m.size(); j++)
            if ((i == j && m[i][j] != 1) || (i != j) && m[i][j] != 0)
                return false;
    return true;
}

int main()
{
    cout << std::boolalpha << isIdentityMatrix(
        {{1, 1, 0},
         {0, 1, 1},
         {0, 0, 1}}) << endl; // false

    cout << isIdentityMatrix(
                {{1, 0, 0},
                 {0, 1, 0},
                 {0, 0, 1}})
         << endl; // true
    return 0;
}
