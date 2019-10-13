/**
 * Cho một bảng sudoku 9 x 9
 * Kiểm tra xem nó có hợp lệ theo quy tắc của trò chơi hay không?
 * Lưu ý: hợp lệ không đồng nghĩa với có thể giải được
*/

#include <iostream>
#include <vector>
using namespace std;

bool isInvalid(int arr[])
{
    for (int i = 0; i < 10; i++)
        if (arr[i] > 1)
            return false;
    return true;
}

bool sudoku2(vector<vector<char>> grid)
{
    // Check hàng
    for (auto v : grid)
    {
        int cnt[10] = {};
        for (char ch : v)
            if (ch != '.')
                cnt[ch - '0']++;
        if (!isInvalid(cnt))
            return false;
    }

    // Check cột
    for (int j = 0; j < grid.size(); j++)
    {
        int cnt[10] = {};
        for (int i = 0; i < grid.size(); i++)
            if (grid[i][j] != '.')
                cnt[grid[i][j] - '0']++;
        if (!isInvalid(cnt))
            return false;
    }

    // Check 3x3
    for (int i = 0; i < grid.size(); i += 3)
        for (int j = 0; j < grid.size(); j += 3)
        {
            int cnt[10] = {};
            for (int x = 0; x < 3; x++)
                for (int y = 0; y < 3; y++)
                {
                    char tmp = grid[i + x][j + y];
                    if (tmp != '.')
                        cnt[tmp - '0']++;
                }
            if (!isInvalid(cnt))
                return false;
        }
    return true;
}

int main()
{
    vector<vector<char>> v2D = {
        {'.', '.', '.', '1', '4', '.', '.', '2', '.'},
        {'.', '.', '6', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '1', '.', '.', '.', '.', '.', '.'},
        {'.', '6', '7', '.', '.', '.', '.', '.', '9'},
        {'.', '.', '.', '.', '.', '.', '8', '1', '.'},
        {'.', '3', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '7', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '7', '.'}};
    cout << std::boolalpha << sudoku2(v2D) << endl; // True

    vector<vector<char>> v2D2 = {
        {'.', '3', '.', '.', '2', '.', '.', '9', '.'},
        {'.', '.', '3', '.', '6', '.', '.', '.', '.'},
        {'.', '1', '.', '.', '7', '5', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '8', '3', '.', '.', '.'},
        {'.', '.', '8', '.', '.', '7', '.', '6', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '9', '.', '2', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '.', '3', '.', '.', '.', '.'}
    };
    cout << sudoku2(v2D2); // false

    return 0;
}
