// Cho vị trí con tượng (cờ vua) và một con tốt
// Xác đinh xem con tượng có bắt được con tốt hay không
#include <iostream>
using namespace std;

// 'a' = 97, 'h' = 104
bool bishopAndPawn(string bishop, string pawn) {
    return abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]);
}

int main()
{
    cout << boolalpha << bishopAndPawn("a1", "c3"); // true
    return 0;
}