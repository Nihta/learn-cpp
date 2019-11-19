// Cho vị trí của quân mã (knight), tính xem các vị trí mà nó có thể di chuyển
#include <iostream>
using namespace std;

// Kiểm tra tọa độ (h, w) có tồn tại trên bàn cờ hay không
bool validCell(int w, int h)
{
    return '1' <= h && h <= '8' && 'a' <= w && w <= 'h';
}

int chessKnight(string cell)
{
    int w = cell.front(), h = cell.back();

    // Check 8 vị trí mà knight có thể di chuyển
    return  validCell(w+2, h+1)+
            validCell(w+2, h-1)+
            validCell(w-2, h+1)+
            validCell(w-2, h-1)+
            validCell(w+1, h+2)+
            validCell(w+1, h-2)+
            validCell(w-1, h+2)+
            validCell(w-1, h-2);
}

int main()
{
    string s = "d5";
    cout << chessKnight(s);
    return 0;
}