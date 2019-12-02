// Kiểm tra giải pháp sudoku có hợp lệ hay không
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool sudoku(std::vector<std::vector<int>> grid)
{
    // Kiểm tra hàng
    for (int row = 0; row < 9; row++)
    {
        set<int> check;
        for (int i = 0; i < 9; i++)
            check.insert(grid[row][i]);
        if (check.size() != 9)
            return false;
    }
    // Kiểm tra cột
    for (int col = 0; col < 9; col++)
    {
        set<int> check;
        for (int i = 0; i < 9; i++)
            check.insert(grid[i][col]);
        if (check.size() != 9)
            return false;
    }
    // Kiểm tra box 3x3
    for (int x = 0; x < 9; x+=3)
    {
        for (int y = 0 ; y < 9; y+=3)
        {
            set<int> check;
            for (int i = 0 ; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    check.insert(grid[x+i][y+j]);
            if (check.size() != 9)
                return false;
        }
    }
    return true;
}

int main()
{
    cout << std::boolalpha << sudoku({
        { 1, 3, 2, 5, 4, 6, 9, 8, 7 },
        { 4, 6, 5, 8, 7, 9, 3, 2, 1 },
        { 7, 9, 8, 2, 1, 3, 6, 5, 4 },
        { 9, 2, 1, 4, 3, 5, 8, 7, 6 },
        { 3, 5, 4, 7, 6, 8, 2, 1, 9 },
        { 6, 8, 7, 1, 9, 2, 5, 4, 3 },
        { 5, 7, 6, 9, 8, 1, 4, 3, 2 },
        { 2, 4, 3, 6, 5, 7, 1, 9, 8 },
        { 8, 1, 9, 3, 2, 4, 7, 6, 5 }});
    return 0;
}
