/**
 * Xem xét một phân đoạn vuông (2k + 1) × (2k + 1) của ma trận hình chữ nhật.
 * Gọi liên kết của hai đường chéo dài nhất, cột giữa và hàng giữa là một ngôi sao.
 * Cho tọa độ tâm của ngôi sao (center) và chiều rộng (width) của nó, xoay nó
 * 45*t độ theo chiều kim đồng hồ đồng thời giữ vị trí của tất cả các phần tử của
 * ma trận không thuộc về ngôi sao đó. (CHỉ xoay các phần tử của ngôi sao)
 * Ví dụ: starRotation.png
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> starRotation(vector<vector<int>> mattrix, int width, vector<int> center, int t)
{
    t %= 8; // 8 * 45 = 360
    int oX = center[0];
    int oY = center[1];
    while (t--)
    {
        // Xử lý từng vòng một từ trong ra ngoài
        for (int i = 1; i <= width / 2; i++)
        {
            int save = mattrix[oX - i][oY - i];
            mattrix[oX - i][oY - i] = mattrix[oX][oY - i];
            mattrix[oX][oY - i] = mattrix[oX + i][oY - i];
            mattrix[oX + i][oY - i] = mattrix[oX + i][oY];
            mattrix[oX + i][oY] = mattrix[oX + i][oY + i];
            mattrix[oX + i][oY + i] = mattrix[oX][oY + i];
            mattrix[oX][oY + i] = mattrix[oX - i][oY + i];
            mattrix[oX - i][oY + i] = mattrix[oX - i][oY];
            mattrix[oX - i][oY] = save;
        }
    }
    return mattrix;
}

int main()
{
    vector<vector<int>> res = starRotation({{1, 0, 0, 2, 0, 0, 3},
                                            {0, 1, 0, 2, 0, 3, 0},
                                            {0, 0, 1, 2, 3, 0, 0},
                                            {8, 8, 8, 9, 4, 4, 4},
                                            {0, 0, 7, 6, 5, 0, 0}},
                                           3,
                                           {1, 5},
                                           81);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}
