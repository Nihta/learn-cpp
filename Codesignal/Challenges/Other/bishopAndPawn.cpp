/**
 * Cho vị trí quân tượng trắng và quân tốt đen (cờ vua)
 * Xác định xem quân tượng có bắt được tốt không?
*/
#include <iostream>
#include <vector>
using namespace std;

bool bishopAndPawn(std::string bishop, std::string pawn) {
    int xBishop = bishop[0] - 'a';
    int YBishop = bishop[1] - '1';
    int xPawn = pawn[0] - 'a';
    int yPawn = pawn[1] - '1';
    return xBishop + YBishop == xPawn + yPawn || xBishop + yPawn == YBishop + xPawn;
}

int main() {
    cout << std::boolalpha << bishopAndPawn("a1", "c3");
    return  0;
}
