/*
Kiểm tra giải pháp sudoku 9x9
    1 ≤ grid[i][j] ≤ 9
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool sudoku(vector<vector<int>> grid)
{
    // Check hàng ngang
    for (auto v : grid)
    {
        set<int> tmp;
        for(int i : v)
            tmp.insert(i);
        if (tmp.size() != 9)
            return false;
    }

    // Check cột dọc
    for(int j = 0; j < 9; ++j)
    {
        set<int> tmp;
        for (int i = 0; i < 9; ++i)
            tmp.insert(grid[i][j]);
        if (tmp.size() != 9)
            return false;
    }

    // Check 3x3
    for (int i = 0; i < 9; i+=3)
        for(int j = 0; j < 9; j+=3)
        {
            set<int> tmp;
            for(int x = 0; x < 3; ++x)
                for(int y = 0; y < 3; ++y)
                    tmp.insert(grid[i+x][j+y]);
            if (tmp.size() != 9)
                return false;
        }

    return true;
}

int main()
{
    vector<vector<int>> grid = 
    {{1,3,2,5,4,6,9,8,7}, 
    {4,6,5,8,7,9,3,2,1}, 
    {7,9,8,2,1,3,6,5,4}, 
    {9,2,1,4,3,5,8,7,6}, 
    {3,5,4,7,6,8,2,1,9}, 
    {6,8,7,1,9,2,5,4,3}, 
    {5,7,6,9,8,1,4,3,2}, 
    {2,4,3,6,5,7,1,9,8}, 
    {8,1,9,3,2,4,7,6,5}};
    cout << boolalpha << sudoku(grid);
    return 0;
}