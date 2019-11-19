/**
 * Cho tọa độ x, y của bốn đỉnh hình vuông
 * Tìm chiều dài của cạnh hình vuông bình phương
*/
#include <iostream>
#include <vector>
using namespace std;

int findSquareSide(vector<int> x, vector<int> y)
{
    // Tìm độ cách từ một điểm đến 2 điểm, có 2 khả năng xảy ra:
    // Đó là độ dài cạnh hình vuông hoặc độ dài đường chéo
    int a = (x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]);
    int b = (x[0] - x[2])*(x[0] - x[2]) + (y[0] - y[2])*(y[0] - y[2]);
    return a < b ? a : b;
}

int main()
{
    cout << findSquareSide({0, -1, -4, -3}, {-1, -4, -3, 0}); // 10
    return 0;
}
