#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

class Sudoku
{
private:
    vector<vector<int>> gridPuzzle;
    vector<vector<int>> gridSolved;
    vector<vector<int>> gridTmp;
    vector<int> valueRandom = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> indexRandom;
    // Kiểm tra xem input (puzzle) có hợp lệ hay không
    bool checkInput(const string &s)
    {
        if (s.size() != 81)
            return false;

        vector<vector<int>> grid = this->stringToGrid(s);
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
        for (int i = 0; i < 9; i++)
        {
            int cnt[10] = {};
            for (int j = 0; j < 9; j++)
                if (grid[i][j] != 0)
                    cnt[grid[i][j]]++;
            if (!H.isValid(cnt))
                return false;
        }
        // Check cột
        for (int j = 0; j < 9; j++)
        {
            int cnt[10] = {};
            for (int i = 0; i < 9; i++)
                if (grid[i][j] != 0)
                    cnt[grid[i][j]]++;
            if (!H.isValid(cnt))
                return false;
        }
        // Check 3x3
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
            {
                int cnt[10] = {};
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                    {
                        if (grid[i + x][j + y] != 0)
                            cnt[grid[i + x][j + y]]++;
                    }
                if (!H.isValid(cnt))
                    return false;
            }

        return true;
    }

    // Xuất grid định dạng svg
    bool exportSvg(const vector<vector<int>> &grid, string fileName)
    {
        // Mở files để đọc ghi
        std::ifstream fileInput("./Game/Sudoku/svgHead.txt");
        std::ofstream fileOutput("./Game/Sudoku/" + fileName + ".svg");
        if (fileInput.fail() || fileOutput.fail())
        {
            cout << "ERROR! PATH file khong chinh xac!" << endl;
            return false;
        }

        // Copy toàn bộ text từ fileInput sang fileOutput
        fileOutput << fileInput.rdbuf();
        fileInput.close();

        // Chuyển grid 9x9 sang svg
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (grid[i][j] != 0)
                {
                    int x = 50 * j + 16; // + 16 để căn lề trái
                    int y = 50 * i + 35; // + 35 để căn lề trên
                    fileOutput << "<text x=\"" << x << "\" y=\"" << y
                               << "\" style=\"font-weight:bold\" font-size=\"30px\">"
                               << grid[i][j] << "</text>\n";
                }
        fileOutput << "</svg>";

        fileOutput.close();
        return true;
    }
    // Hiện thị grid
    void display(const vector<vector<int>> &grid)
    {
        string line = " ------ + ----- + ------";
        cout << line << endl;
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
                cout << '\n'
                     << line;
            cout << endl;
        }
    }
    /**
     * Tìm vị trí (int) một cell trống bắt đầu tìm từ indexStartFind trở đi
     * Việc bắt đầu tìm từ indexStartFind có thể dẫn đến việc tìm kiếm sót cell
     * trống nhưng làm tăng tốc độ solve. Vì thế cần đảm bảo không có cell trống
     * nào từ indexStartFind trở về trước (index = 0).
    */
    int indexCellEmpty(const vector<vector<int>> &grid, int indexStartFind)
    {
        for (int i = indexStartFind; i < 81; i++)
            // row = i/9, col = i%9;
            if (grid[i / 9][i % 9] == 0)
                return i;
        return -1;
    }

    /**
     * Kiểm tra tại cell[row][col] thì điền value có khả thi hay không?
     * Lưu ý: đảm bảo cell đang kiểm tra trống (value khác 0)
    */
    bool valuePossibleInCell(vector<vector<int>> &v, int row, int col, int value)
    {
        // Check hàng và cột
        for (int i = 0; i < 9; i++)
            if (v[row][i] == value || v[i][col] == value)
                return false;
        // Check 3x3
        int sx = row - row % 3;
        int sy = col - col % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (v[i + sx][j + sy] == value)
                    return false;
        return true;
    }

    /**
     * Hàm solve đặc biệt, mục đích chính sử dụng trong createPuzzle()
     * Hàm này cố gắng giải this->gridTmp mà không sử dụng value forbiddenValue
     * tại index forbiddenIndex
    */
    bool solveWithBind(int cellIndex, int forbiddenIndex, int forbiddenValue)
    {
        // Tìm một ô trống
        int cellEmpty = this->indexCellEmpty(this->gridTmp, cellEmpty);
        // Base case
        if (cellEmpty == -1) // Nếu không tìm được cell trống
            return true;

        int rowCellEmpty = cellEmpty / 9, colCellEmpty = cellEmpty % 9;
        // Test các số khả thi
        for (int valueTest = 1; valueTest <= 9; valueTest++)
        {
            if (cellEmpty == forbiddenIndex && valueTest == forbiddenValue)
                continue;
            if (this->valuePossibleInCell(this->gridTmp, rowCellEmpty, colCellEmpty, valueTest))
            {
                this->gridTmp[rowCellEmpty][colCellEmpty] = valueTest;
                if (this->solveWithBind(cellEmpty, forbiddenIndex, forbiddenValue))
                    return true;
            }
        }

        this->gridTmp[rowCellEmpty][colCellEmpty] = 0;
        return false; // Quay lui
    }

    // Random seed
    void random()
    {
        srand(time(NULL));
        random_shuffle(this->valueRandom.begin(), this->valueRandom.end());
        indexRandom.clear();
        for (int i = 0; i < 81; i++)
            this->indexRandom.push_back(i);
        random_shuffle(this->indexRandom.begin(), this->indexRandom.end());
    }

public:
    Sudoku()
    {
        this->gridPuzzle = this->stringToGrid(string(81, '0'));
        this->gridSolved = this->gridPuzzle;
        this->random();
        this->solve(0);
    }

    bool setPuzzle(string s)
    {
        if (this->checkInput(s))
        {
            this->gridPuzzle = this->stringToGrid(s);
            this->gridSolved = this->gridPuzzle;
            this->random();
            this->solve(0);
            return true;
        }
        else
        {
            cout << "ERROR! Dinh dang puzzle sudoku khong dung!"
                 << "\nKiem tra puzzle va thu lai." << endl;
            return false;
        }
    }
    // Chuyển string -> vector<vector<int>>
    vector<vector<int>> stringToGrid(string s)
    {
        vector<vector<int>> res(9);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                res[i].push_back(s[9 * i + j] - '0');
        return res;
    }
    // Chuyển vector<vector<int>> -> string
    string gridToString(const vector<vector<int>> &grid)
    {
        string res;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                res += char('0' + grid[i][j]);
        return res;
    }
    // Hiện thị puzzle (dạng grid)
    void displayPuzzle()
    {
        this->display(this->gridPuzzle);
    }
    // Hiện thị solution (dạng grid)
    void displayPuzzleSolved()
    {
        this->display(this->gridSolved);
    }

    // Kiểm tra solution (Có thể có trường hợp solve được solution nhưng lại sai @@)
    bool checkSulotionSudoku()
    {
        // Check hàng ngang
        for (int i = 0; i < 9; i++)
        {
            int count[10] = {};
            for (int j = 0; j < 9; j++)
                if (this->gridSolved[i][j] == 0 || count[this->gridSolved[i][j]]++ != 0)
                    return false;
        }

        // Check cột dọc
        for (int j = 0; j < 9; j++)
        {
            int count[10] = {};
            for (int i = 0; i < 9; i++)
                if (count[this->gridSolved[i][j]]++ != 0)
                    return false;
        }

        // Check 3x3
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
            {
                int count[10] = {};
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y)
                        if (count[this->gridSolved[i + x][j + y]]++ != 0)
                            return false;
            }
        return true;
    }

    // Giải sudoku sử dụng quay lui
    bool solve(int cellIndex = 0)
    {
        // Tìm một ô trống
        cellIndex = this->indexCellEmpty(this->gridSolved, cellIndex);
        // Base case
        if (cellIndex == -1)
            return true;

        int rowCell = cellIndex / 9, colCell = cellIndex % 9;

        // Test các số khả thi
        for (int i = 0; i < 9; i++)
        {
            if (this->valuePossibleInCell(this->gridSolved, rowCell, colCell, this->valueRandom[i]))
            {
                this->gridSolved[rowCell][colCell] = this->valueRandom[i];
                if (this->solve(cellIndex))
                    return true;
            }
        }

        this->gridSolved[rowCell][colCell] = 0;
        return false; // Quay lui
    }

    // Tạo puzzle với số cell trống tối đa
    void createPuzzle()
    {
        cout << "Start create puzzle!" << endl;
        int cellEmpty = 0;
        // Bug: Hàm solve solveWithBind() nếu chạy trực tiếp trên
        // this->gridPuzzle thì sẽ làm thay đổi dữ liệu this->gridPuzzle (T_T)
        // Giải pháp là dùng this->gridTmp thay cho this->gridPuzzle
        this->gridPuzzle = this->gridSolved;
        for (int i = 0; i < 81; i++)
        {
            cout << ".";
            cellEmpty++;
            // Thử xóa cell có index là indexRandom[i]
            int row = this->indexRandom[i] / 9;
            int col = this->indexRandom[i] % 9;
            int originalValue = this->gridSolved[row][col];
            this->gridPuzzle[row][col] = 0;

            // Nếu như tại index i không sử dụng originalValue mà vẫn giải được
            // => puzzle này không phải có solution duy nhất => sai
            this->gridTmp = this->gridPuzzle;
            if (solveWithBind(0, this->indexRandom[i], originalValue))
            {
                this->gridPuzzle[row][col] = originalValue;
                cellEmpty--;
            }
        }
        cout << " Done! " << 81 - cellEmpty << " clues." << endl;
    }

    // Hiện thị puzzle, solution dạng string
    void displayData()
    {
        cout << "Puzzle:   " << this->gridToString(this->gridPuzzle) << endl;
        cout << "Solution: " << this->gridToString(this->gridSolved) << endl;
    }

    // Xuất puzzle định dạng svg
    void exportSvgPuzzle()
    {
        cout << "Xuat file svgSudoku.svg ";
        if (this->exportSvg(this->gridPuzzle, "svgSudoku"))
            cout << "thanh cong!" << endl;
        else
            cout << "that bai!" << endl;
    }
    // Xuất solution định dạng svg
    void exportSvgPuzzleSolved()
    {
        cout << "Xuat file svgSudokuPuzzleSolved ";
        if (this->exportSvg(this->gridSolved, "svgSudokuPuzzleSolved"))
            cout << "thanh cong!" << endl;
        else
            cout << "that bai!" << endl;
    }
};

void demoClassSudoku()
{
    Sudoku S;
    cout << "Nhap lua chon"
         << "\n\t1. Giai sudoku"
         << "\n\t2. Tao mot puzzle (max clues)" << endl;

    int choose;
    cin >> choose;
    cin.ignore();
    if (choose == 1)
    {
        string puzzle;
        do
        {
            cout << "Enter puzzle sudoku(type string): ";
            getline(cin, puzzle);
        } while (!S.setPuzzle(puzzle));

        if (!S.solve() || !S.checkSulotionSudoku())
        {
            cout << "FAIL! Giai sudoku that bai!";
            return;
        }

        cout << "\nPuzzle: " << endl;
        S.displayPuzzle();
        cout << "\nSolution: " << endl;
        S.displayPuzzleSolved();

        cout << endl;
        S.displayData();

        cout << endl;
        S.exportSvgPuzzle();
        S.exportSvgPuzzleSolved();
    }
    else if (choose == 2)
    {
        S.createPuzzle();

        cout << "\nPuzzle: " << endl;
        S.displayPuzzle();
        cout << endl;

        S.displayData();
        cout << endl;

        S.exportSvgPuzzle();
        S.exportSvgPuzzleSolved();
    }
}
// 000000000000000000000000000000000000000000000000000000000000000000000000000000000
int main()
{
    demoClassSudoku();

    return 0;
}
