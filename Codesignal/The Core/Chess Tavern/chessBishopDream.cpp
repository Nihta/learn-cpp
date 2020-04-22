/**
 * Trong ChessLand có một bishop nhỏ (quân tượng - cờ vua) nhưng tự hào với giấc mơ
 * định kỳ. Trong giấc mơ, bishop thấy mình trên một bàn cờ n × m có gương dọc
 * theo mỗi cạnh, và nó không phải là một bishop mà là một tia sáng. Tia sáng này
 * chỉ di chuyển dọc theo các đường chéo (bishop không thể tưởng tượng được bất
 * kỳ loại di chuyển nào khác ngay cả trong giấc mơ của nó), nó không bao giờ
 * dừng lại, và một khi nó chạm tới một cạnh hoặc một góc của bàn cờ, nó sẽ phản
 * chiếu và tiếp tục di chuyển. Cho vị trí ban đầu và hướng của bishop, tìm
 * vị trí của nó sau k bước (1 ≤ k ≤ 10^9) trong đó một bước có nghĩa là di
 * chuyển từ ô này sang ô khác hoặc phản xạ từ một cạnh hoặc góc.
 * Minh họa: chessBishopDream.png
*/
#include <iostream>
#include <vector>
using namespace std;

// Output Operator Overloading
template <typename T>
ostream &operator<<(ostream &os, vector<T> vt)
{
    os << "(" << vt.size() << ") { ";
    for (auto it = vt.begin(); it != vt.end(); it++)
        os << *it << (it + 1 != vt.end() ? ", " : "");
    os << " }";
    return os;
}

// Sau n * m lần di chuyển thì bishop quay lại vị trí ban đầu nhưng ngược hướng
// Sau 2 * n * m lằn di chuyển thì bishop quay lại vị trí ban đầu và có cùng hướng
// với hướng di chuyển ban đầu
std::vector<int> chessBishopDream(std::vector<int> boardSize, std::vector<int> pos, std::vector<int> direction, int k)
{
    const int maxRow = boardSize[0] - 1;
    const int maxCol = boardSize[1] - 1;

    k %= boardSize[0] * boardSize[1] * 2;
    while (k--)
    {
        // Di chuyển bishop theo hướng direction
        pos[0] += direction[0];
        pos[1] += direction[1];

        // Nếu đi ra khỏi phạm vi bàn cờ thì quay lại và đổi hướng đi chuyển (phản xạ)
        if (pos[0] < 0 || pos[0] > maxRow)
        {
            pos[0] -= direction[0];
            direction[0] *= -1;
        }
        // Nếu đi ra khỏi phạm vi bàn cờ thì quay lại và đổi hướng đi chuyển (phản xạ)
        if (pos[1] < 0 || pos[1] > maxCol)
        {
            pos[1] -= direction[1];
            direction[1] *= -1;
        }
    }

    return pos;
}

int main()
{
    cout << chessBishopDream({3, 7}, {1, 2}, {-1, 1}, 13) << endl; // {0, 1}
    return 0;
}
