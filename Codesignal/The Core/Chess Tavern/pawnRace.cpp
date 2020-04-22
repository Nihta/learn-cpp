/**
 * https://app.codesignal.com/arcade/code-arcade/chess-tavern/
 * ...
 * Mục đích của trò chơi là đến hàng thứ 1 (cho người cầm tốt đen) hoặc
 * hàng thứ 8 (cho người cầm tốt trắng) hoặc để bắt được con tốt của đối phương.
 * Cho các vị trí ban đầu và đến lượt chơi của người, xác định ai sẽ giành
 * chiến thắng hoặc tuyên bố đó là một trận hòa (tức là không thể có bất kỳ
 * người chơi nào giành chiến thắng). Giả sử rằng các cầu thủ chơi tối ưu.
 * Xem: pawnRace.png
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

vector<string> pawnAttack(string pos, char color)
{
    string x = pos;
    string y = pos;
    if (color == 'w')
    {
        x[0] -= 1;
        x[1] += 1;
        y[0] += 1;
        y[1] += 1;
        return {x, y};
    }
    else
    {
        x[0] -= 1;
        x[1] -= 1;
        y[0] += 1;
        y[1] -= 1;
        return {x, y};
    }
}

std::string pawnRace(std::string white, std::string black, char toMove)
{

    char x = white[0], y = white[1];
    char m = black[0], n = black[1];

    if (x == m && y + 1 == n)
        return "draw";

    if (toMove == 'w')
    {
        // Nếu như tốt trắng ăn được tốt đen hoặc có thể về đích
        vector<string> attack = pawnAttack(white, 'w');
        if (y == '7' || attack[0] == black || attack[1] == black)
            return "white";

        if (white[1] == '2')
        {
            // Những vị trí mà đi vào đó sẽ bị tốt đen ăn
            vector<string> danger = pawnAttack(black, 'b');
            // Giả sử tốt đi chuyển 2 ô
            string expecPos = white;
            expecPos[1] += 2;
            // Nếu di chuyển 2 ô mà không bị tốt đen ăn hoặc không bị cản bởi tốt đen
            if (expecPos != danger[0] && expecPos != danger[1] && expecPos != black)
                white[1] += 2;
            else
                white[1] += 1;
        }
        else
        {
            white[1] += 1;
        }
    }
    else
    {
        vector<string> attack = pawnAttack(black, 'b');
        if (n == '2' || attack[0] == white || attack[1] == white)
            return "black";

        if (black[1] == '7')
        {
            vector<string> danger = pawnAttack(white, 'w');
            string expecPos = black;
            expecPos[1] -= 2;
            if (expecPos != danger[0] && expecPos != danger[1] && expecPos != white)
                black[1] -= 2;
            else
                black[1] -= 1;
        }
        else
        {
            black[1] -= 1;
        }
    }

    return pawnRace(white, black, (toMove == 'w' ? 'b' : 'w'));
}

int main()
{
    cout << pawnRace("e2", "e7", 'w') << endl; // "draw"
    cout << pawnRace("e3", "d7", 'b') << endl; // "black"
    cout << pawnRace("a7", "a2", 'w') << endl; // "white"
    cout << pawnRace("f2", "h6", 'w') << endl; // "white"
    cout << pawnRace("c5", "c7", 'b') << endl; // "draw" 40 000$ T_T
    return 0;
}
