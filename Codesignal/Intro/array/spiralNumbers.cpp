/*
Xây dựng ma trận xoắn ốc kích thước n*n
            [1 2 3]
n = 3 -=>   [8 9 4]
            [7 6 5]
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiralNumbers(int n)
{
    /*  Vẽ lần lượt vỏ bao kích thước nxn -=> (n-1)x(n-1) -> (n-2)x(n-2) ...
        1  2  3  4
        12       5
        11       6
        10 9  8  7

        1  2  3  4
        12 13 14 5
        11 16 15 6
        10 9  8  7   */
    vector<vector<int>> r(n, vector<int>(n));

    int i, j, number = 0, min = 0, max = n;
    while(number != n*n)
    {
        // i, j là tọa độ bắt đầu của vỏ bao hiện tại đang vẽ
        i = j = min;
        // Cạnh trên
        for(       ; j < max;  ++j) r[i][j] = ++number; --j;
        // Cạnh phải
        for(i = i+1; i < max;  ++i) r[i][j] = ++number; --i;
        // Cạnh dưới
        for(j = j-1; j >= min; --j) r[i][j] = ++number; ++j;
        // Cạnh bên
        for(i = i-1; i > min;  --i) r[i][j] = ++number;
        // Vẽ cái bao quanh phía trong tiếp theo
        ++min, --max;
    }

    return r;
}

int main()
{
    for (int test = 2; test <= 9; test++)
    {
        for (auto &&i : spiralNumbers(test))
        {
            for (auto &&j : i)
                j < 10 ? cout << "  " << j : cout << " " << j;
            cout << endl;
        }
        cout << "---------------------------" << endl;
    }
    
    
    return 0;
}
