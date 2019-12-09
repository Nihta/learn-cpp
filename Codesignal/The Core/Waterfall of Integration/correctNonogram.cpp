/**
 * Trò chơi nonogram https://app.codesignal.com/arcade/code-arcade/waterfall-of-integration/
 * You are given a square nonogram of size size.
 * Its grid is given as a square matrix nonogramField of size (size + 1)/2 + size,
 * where the first (size + 1) / 2 cells of each row and and each column
 * define the numbers for the corresponding row/column, and the rest size × size
 * cells define the the grid itself.
 * Determine if the given nonogram has been solved correctly.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

int strToInt(string s)
{
    int res;
    stringstream ss(s);
    ss >> res;
    return res;
}

bool isAvail(vector<int> rule, vector<string> data)
{
    // Đếm số lượng các kí tự '#' liền kề
    data.push_back(".");
    vector<int> analysis;
    bool isCount = false;
    int count = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == ".")
        {
            if (count != 0)
                analysis.push_back(count);
            count = 0;
            isCount = false;
        }
        else
        {
            if (!isCount)
            {
                isCount = true;
                count = 0;
            }
            count++;
        }
    }
    return rule == analysis;
}

bool correctNonogram(int size, std::vector<std::vector<std::string>> nonogramField) {
    int squereSize = nonogramField.size();
    int marginSize = squereSize - size;

    // Check lần lượt các hàng
    for (int i = marginSize; i < squereSize; i++)
    {
        vector<int> rule;
        for (int j = 0; j < marginSize; j++)
            if (nonogramField[i][j] != "-")
                rule.push_back(strToInt(nonogramField[i][j]));

        vector<string> data;
        for (int j = marginSize; j < squereSize; j++)
            data.push_back(nonogramField[i][j]);

        if (!isAvail(rule, data))
            return false;
    }

    // Check lần lượt các cột
    for (int j = marginSize; j < squereSize; j++)
    {
        vector<int> rule;
        for (int i = 0; i < marginSize; i++)
            if (nonogramField[i][j] != "-")
                rule.push_back(strToInt(nonogramField[i][j]));

        vector<string> data;
        for (int i = marginSize; i < squereSize; i++)
            data.push_back(nonogramField[i][j]);

        if (!isAvail(rule, data))
            return false;
    }

    return true;
}

int main() {
    cout << std::boolalpha << correctNonogram(9, {
        {"-","-","-","-","-","-","-","-","-","-","-","-","-","-"},
        {"-","-","-","-","-","-","-","-","-","-","-","-","-","-"},
        {"-","-","-","-","-","-","-","-","-","-","-","-","-","-"},
        {"-","-","-","-","-","-","-","4","3","-","-","-","-","-"},
        {"-","-","-","-","-","2","2","2","1","9","3","4","2","2"},
        {"-","-","-","-","1",".",".",".",".","#",".",".",".","."},
        {"-","-","-","-","5",".",".","#","#","#","#","#",".","."},
        {"-","-","-","-","7",".","#","#","#","#","#","#","#","."},
        {"-","-","-","-","9","#","#","#","#","#","#","#","#","#"},
        {"1","1","1","1","1","#",".","#",".","#",".","#",".","#"},
        {"-","-","-","-","1",".",".",".",".","#",".",".",".","."},
        {"-","-","-","-","1",".",".",".",".","#",".",".",".","."},
        {"-","-","-","1","1",".",".","#",".","#",".",".",".","."},
        {"-","-","-","-","3",".",".","#","#","#",".",".",".","."}})
        << endl; // true
    return  0;
}
