/**
 * Bạn có một bảng trắng hình chữ nhật với một số ô màu đen (true).
 * Các ô đen tạo ra một hình đen được kết nối, tức là có thể đi từ bất kỳ ô đen
 * nào đến bất kỳ ô nào khác thông qua các ô đen liền kề (chia sẻ một mặt chung).
 * Tìm chu vi của hình đen giả sử rằng mỗi ô có cùng đơn vị độ dài.
 * Đảm bảo rằng có ít nhất một ô đen trên bàn.
 * Xem: polygonPerimeter.png
*/
#include <iostream>
#include <vector>
using namespace std;

/**
 * Ý tưởng: Chu vi hình đen cần tìm bằng với số lượng các cạnh mà thỏa mãn cạnh
 * đó không là cạnh chung với bất kì ô đen khác
*/
int polygonPerimeter(std::vector<std::vector<bool>> matrix)
{
    // Sô lượng hàng, cột của matrix
    int h = matrix.size(), w = matrix[0].size();
    int res = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == true)
            {
                // Kiểm tra 4 ô tiếp xúc với ô đen hiện tại (nếu có): trên, dưới, trái, phải
                vector<vector<int>> posNeedCheck{{i, j - 1}, {i, j + 1}, {i - 1, j}, {i + 1, j}};
                for (auto pos : posNeedCheck)
                {
                    if (0 <= pos[0] && pos[0] < h && 0 <= pos[1] && pos[1] < w)
                    {
                        // Nếu ô tiếp xúc là ô trắng
                        if (matrix[pos[0]][pos[1]] == false)
                            res += 1;
                    }
                    else // Nếu ô đang kiểm tra nằm ngoài phạm vi matrix
                        res += 1;
                }
            }
        }
    }
    return res;
}

int main()
{
    cout << polygonPerimeter({{false, true, true},
                              {true, true, false},
                              {true, false, false}}); // 12
    return 0;
}
