/**
 * Cho tọa độ góc trái trên và dưới phải
 * Vẻ hình chữ nhật trên canvas
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> drawRectangle(vector<vector<char>> canvas, vector<int> rectangle)
{
    int aX = rectangle[0];
    int aY = rectangle[1];
    int cX = rectangle[2];
    int cY = rectangle[3];
    int bX = rectangle[2];
    int bY = rectangle[1];
    int dX = rectangle[0];
    int dY = rectangle[3];
    canvas[aY][aX] = canvas[bY][bX] = canvas[cY][cX] = canvas[dY][dX] = '*';
    // AB
    for (int i = aX + 1; i < bX; i++)
        canvas[aY][i] = '-';
    // DC
    for (int i = dX + 1; i < cX; i++)
        canvas[dY][i] = '-';
    // BC
    for (int i = bY + 1; i < cY; i++)
        canvas[i][bX] = '|';
    // AD
    for (int i = aY + 1; i < dY; i++)
        canvas[i][aX] = '|';
    return canvas;
}

int main()
{
    vector<vector<char>> vc = drawRectangle(
        {{'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
         {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
         {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}},
        {1, 1, 4, 3});

    for (auto i : vc)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}
