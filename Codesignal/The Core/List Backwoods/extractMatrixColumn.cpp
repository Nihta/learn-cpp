/**
 * Cho một ma trận
 * Trả về các phần tử của cột column
*/
#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}

std::vector<int> extractMatrixColumn(std::vector<std::vector<int>> matrix, int column)
{
    vector<int> res;
    for (int i = 0; i < matrix.size(); i++)
        res.push_back(matrix[i][column]);
    return res;
}

int main()
{
    cout << extractMatrixColumn({{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}}, 1);
    return 0;
}
