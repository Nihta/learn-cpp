// Giải sudoku
#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

long double step = 0;

// Kiểm tra giải pháp sudoku đúng hay sai
bool checkSulotionSudoku(const vector<vector<int>> &grid)
{
    // Check hàng ngang
    for (auto v : grid)
    {
        set<int> tmp;
        for (int i : v)
            tmp.insert(i);
        if (tmp.size() != 9)
            return false;
    }

    // Check cột dọc
    for (int j = 0; j < 9; ++j)
    {
        set<int> tmp;
        for (int i = 0; i < 9; ++i)
            tmp.insert(grid[i][j]);
        if (tmp.size() != 9)
            return false;
    }

    // Check 3x3
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
        {
            set<int> tmp;
            for (int x = 0; x < 3; ++x)
                for (int y = 0; y < 3; ++y)
                    tmp.insert(grid[i + x][j + y]);
            if (tmp.size() != 9)
                return false;
        }

    return true;
}

// Kiểm tra dữ liệu đầu vào có hợp lệ hay không
bool checkInputSudoku(const vector<vector<int>> &grid)
{
    struct Helper
    {
        bool isValid(int arr[])
        {
            for (int i = 0; i <= 9; i++)
                if (arr[i] > 1)
                    return false;
            return true;
        }
    };
    Helper H;

    // Check hàng
    for (auto v : grid)
    {
        int cnt[10] = {};
        for (char i : v)
            if (i != 0)
                cnt[i]++;
        if (!H.isValid(cnt))
            return false;
    }

    // Check cột
    for (int j = 0; j < grid.size(); j++)
    {
        int cnt[10] = {};
        for (int i = 0; i < grid.size(); i++)
            if (grid[i][j] != 0)
                cnt[grid[i][j]]++;
        if (!H.isValid(cnt))
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
                    if (tmp != 0)
                        cnt[tmp]++;
                }
            if (!H.isValid(cnt))
                return false;
        }
    return true;
}

// Kiểm tra xem có thể điền value vào ô tọa độ (x, y) hay không
bool isValid(const vector<vector<int>> &grid, int x, int y, int value)
{
    // Kiểm tra xem hàng và cột xem đã có số = value chưa
    for (int i = 0; i < 9; i++)
        if (grid[i][y] == value || grid[x][i] == value)
            return false;

    // Kiểm tra xem ô cần điền (tọa độ (x, y)) nằm trong ô 3x3 nào
    int sx = (x / 3) * 3;
    int sy = (y / 3) * 3;
    // Check value trong phạm vi 3x3
    for (int i = sx; i < sx + 3; i++)
        for (int j = sy; j < sy + 3; j++)
            if (grid[i][j] == value)
                return false;

    return true;
}

// Giải sudoku, return false nếu như không giải được
bool solveSudoku(vector<vector<int>> &grid, int i, int j)
{
    // Base Case - Phần neo
    if (i == 9)
        return true;

    step++;

    // Duyệt hết phần tử trong hàng thì nhảy sang hàng tiếp
    if (j == 9)
        return solveSudoku(grid, i + 1, 0);

    // Nếu như ô này đã có số thì chuyển qua ô tiếp theo
    if (1 <= grid[i][j] && grid[i][j] <= 9)
        return solveSudoku(grid, i, j + 1);

    // Nếu như ô trống (=0) thì thử điền vào đó các số từ 1 đến 9
    for (int test = 1; test <= 9; test++)
    {
        if (isValid(grid, i, j, test)) // Nếu như test phù hợp
        {
            grid[i][j] = test;

            // test xem có thể tìm được số phù hợp ở ô tiếp theo hay không
            if (solveSudoku(grid, i, j + 1))
                return true;
        }
    }

    // Nếu không thể tìm được số phù hợp để điền (cách giải sudoku sai)
    grid[i][j] = 0;
    // Quay lui
    return false;
}

// In bảng sudoku
void coutgrid(const vector<vector<int>> &grid)
{
    cout << ' ' << string(23, '-') << '\n';
    for (int i = 0; i < 9; i++)
    {
        cout << "| ";
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        if ((i + 1) % 3 == 0)
            cout << "\n " << string(23, '-');
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grid =
        {{0, 0, 2, 0, 0, 0, 3, 6, 0},
         {0, 0, 0, 6, 0, 2, 0, 5, 0},
         {9, 0, 0, 5, 0, 0, 0, 0, 0},

         {2, 0, 0, 0, 1, 0, 0, 8, 7},
         {0, 6, 0, 0, 0, 0, 0, 1, 0},
         {7, 1, 0, 0, 9, 0, 0, 0, 2},

         {0, 0, 0, 0, 0, 4, 0, 0, 8},
         {0, 2, 0, 9, 0, 3, 0, 0, 0},
         {0, 3, 8, 0, 0, 0, 2, 0, 0}};

    if (checkInputSudoku(grid)) // Kiểm tra đầu vào
    {
        if (solveSudoku(grid, 0, 0)) // Kiểm tra xem có thể giải hay không
        {
            if (checkSulotionSudoku(grid)) // Kiểm tra lời giải đúng hay sai
            {
                cout << "Giai thanh cong! Step: " << step << endl;
                coutgrid(grid);
            }
            else
                cout << "Giai ra ket qua sai @@" << step << endl;
        }
        else
            cout << "Khong the giai !!!" << endl;
    }
    else
        cout << "Input khong hop le !!!" << endl;

    return 0;
}
