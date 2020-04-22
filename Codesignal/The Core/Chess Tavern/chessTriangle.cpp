/**
 * Hãy xem xét một bishop, một knight và một rook (quân xe) trên bàn cờ vua n × m.
 * Chúng được cho là tạo thành một hình tam giác nếu mỗi quân tấn công chính xác
 * một quân khác và bị tấn công bởi chính xác một quân. Tính số cách chọn vị trí
 * của các quân để tạo thành một hình tam giác.
*/
#include <iostream>
#include <vector>
using namespace std;
/**
 * [2, 3],  # 8 variants
 * [2, 4],  # 8 variants
 * [3, 2],  # 8 variants
 * [3, 3]   # 16 variants
 * [3, 4],  # 8 variants
 * [4, 3],  # 8 variants
 * [4, 2],  # 8 variants

*/
int chessTriangle(int n, int m)
{
}

int main()
{
    cout << chessTriangle(1, 30) << endl; // 0
    cout << chessTriangle(2, 2) << endl;  // 0
    cout << chessTriangle(2, 3) << endl;  // 8
    cout << chessTriangle(5, 2) << endl;  // 40
    cout << chessTriangle(3, 3) << endl;  // 48
    return 0;
}
/**
 * Once again I reaffirm that python is the best language to start programming: easy to learn, friendly to newbies, clear structure, versatile, needs manpower and high salary.
*/
