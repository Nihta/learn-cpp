/**
 * Cho vị trí của quân cờ mã trên bàn cờ vua,
 * tìm số vị trí mà nó có thể di chuyển trong nước đi tiếp theo
*/
#include <iostream>
using namespace std;

int chessKnightMoves(string cell)
{
    struct Helper
    {
        bool isValid(int pos)
        {
            if (0 <= pos && pos < 8)
                return true;
            return false;
        }

        int getX(string pos)
        {
            return pos[0] - 'a';
        }

        int getY(string pos)
        {
            return pos[0] - '1';
        }
    };
    Helper h;

    int current_x = h.getX(cell.substr(0, 1));
    int current_y = h.getY(cell.substr(1, 2));
    int result = 0;

    for (int dx = -2; dx <= 2; dx++)
        for (int dy = -2; dy <= 2; dy++)
            // Vị trí mà quân mã có thể đi (trường hợp bàn cờ không có biên giới)
            if (abs(dx * dy) == 2)
                // Kiểm tra xem vị trí thỏa mãn có nằm trên bàn cờ không
                if (h.isValid(current_x + dx) && h.isValid(current_y + dy))
                    result++;
    return result;
}

int main()
{
    cout << chessKnightMoves("a1"); // 2
    return 0;
}
