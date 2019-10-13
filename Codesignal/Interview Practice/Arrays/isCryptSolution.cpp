/**
 * Dựa vào mảng solution chuyển các 3 string trong mảng crypt thành 3 số nguyên
 * tương ứng: a, b, c.
 * Retrun true nếu a + b == c và a, b, c là các số không chứa bất kì số 0 nào
 * ở đầu, ví dụ trường hợp không hợp lệ: 056, 007
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Ánh xạ char sang number
char decode(vector<vector<char>> solution, char ch)
{
    int i;
    for (i = 0; i <= 9; i++)
        if (ch == solution[i][0])
            break;
    return solution[i][1];
}

long long strToLl(string s)
{
    stringstream ss(s);
    long long res;
    ss >> res;
    return res;
}

bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution)
{
    for (auto &&s : crypt)
        if (decode(solution, s[0]) == '0' && s.size() != 1)
            return false;
        else
            for (auto &&ch : s)
                ch = decode(solution, ch);

    return strToLl(crypt[0]) + strToLl(crypt[1]) == strToLl(crypt[2]);
}

int main()
{
    cout << std::boolalpha << isCryptSolution({"SEND","MORE","MONEY"},{
        {'O','0'},
        {'M','1'},
        {'Y','2'},
        {'E','5'},
        {'N','6'},
        {'D','7'},
        {'S','9'},
        {'R','8'}}); // true

    return 0;
}
