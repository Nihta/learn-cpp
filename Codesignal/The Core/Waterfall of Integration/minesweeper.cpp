/**
 * Trong trò chơi Minesweeper nổi tiếng, bạn có một mảng với một số mine và
 * những ô không chứa mine có chứa một số nguyên cho biết tổng số mine trong các
 * ô lân cận (8 ô xung quanh - Không tính chính nó )
 * Bắt đầu với một sự sắp xếp của các mine, tạo thiết lập trò chơi Minesweeper
 * Xem hình: minesweeper.png
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> minesweeper(vector<vector<bool>> matrix)
{
    // Khởi tạo vector (row x col) bao gồm các phần tử 0
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> result(row, vector<int>(col, 0));
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            // Xét 8 ô xung quanh ô tọa độ (rol, col)
            for (int n = i - 1; n < i + 2; ++n)
                for (int m = j - 1; m < j + 2; ++m)
                    // Né các ô ảo (không nằm trong phạm vi matrix)
                    if (m >= 0 && m < col && n >= 0 && n < row)
                        // Không mìn nằm ở vị trí đang (nếu có)
                        if (n == i && m == j)
                            continue;
                        else
                            result[i][j] += matrix[n][m] != false ? 1 : 0;
    return result;
}

int main()
{
    vector<vector<bool>> v = {
        {false, true, true, false},
        {true, true, false, true},
        {false, false, true, false}};

    for (auto &&i : minesweeper(v))
    {
        for (auto &&j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
