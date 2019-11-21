/**
 * Cho một ma trận vuông, nhiệm vụ của bạn là hoán đổi các đường chéo dài nhất
 * của nó bằng cách trao đổi các phần tử của chúng tại các vị trí tương ứng.
*/
#include <iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> swapDiagonals(std::vector<std::vector<int>> matrix)
{
    for (int row = 0; row < matrix.size(); row++)
        swap(matrix[row][row], matrix[row][matrix[0].size() - 1 - row]);
    return matrix;
}

int main()
{
    vector<vector<int>> v = swapDiagonals({{1, 2, 3},
                                           {4, 5, 6},
                                           {7, 8, 9}});

    for (auto i : v)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}
