/*
Cho tọa độ hai ô trên bàn cờ
Xác định xem chúng có cùng màu hay không?
 */
#include <iostream>
#include <algorithm>
using namespace std;

// A C E G là các số lẻ
// Các ô màu đen là ô có tọa độ x+y là số chẵn
bool chessBoardCellColor(string cell1, string cell2)
{
    return (cell1[0] + cell1[1])%2 == (cell2[0] + cell2[1])%2;
}

int main()
{
    string cell1 = "A1", cell2 = "A2";
    cout << boolalpha << chessBoardCellColor(cell1, cell2);
    return 0;
}