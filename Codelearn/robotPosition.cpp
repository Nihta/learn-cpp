/**
 * TB: quay 180
 * TL: quay qua trái
 * TR: quay qua phải
 * Go x: tiến x mét
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// In vector<int>
ostream &operator<<(ostream &os, vector<int> v)
{
    for (auto &&i : v)
        os << i << ' ';
    return os;
}

// Tìm khoảng cách trong string "Go x"
int xInGoX(string s)
{
    stringstream ss;
    ss << s;
    string tmp;
    int res;
    ss >> tmp >> res;
    return res;
}

// split các lệnh từ string vào mảng
vector<string> split(string s)
{
    vector<string> res;
    s += ",";
    for (int i = 0, j = 0; i < s.size(); i++)
        if (s[i] == ',')
        {
            res.push_back(s.substr(j, i - j));
            j = i + 1;
        }
    return res;
}

// Xử lý cmd "Go x"
vector<int> cmdGoX(vector<int> xy, string way, int step)
{
    if (way == "y+")
        xy[1] += step;
    else if (way == "y-")
        xy[1] -= step;
    else if (way == "x+")
        xy[0] += step;
    else if (way == "x-")
        xy[0] -= step;
    return xy;
}

// Xử lý cmd "TL", "TR", "TB"
string cmdRotates(string way, string cmd)
{
    if (way == "y+" && cmd == "TL")
        return "x-";
    if (way == "y+" && cmd == "TR")
        return "x+";
    if (way == "y+" && cmd == "TB")
        return "y-";
    if (way == "x+" && cmd == "TB")
        return "x-";
    if (way == "x+" && cmd == "TL")
        return "y+";
    if (way == "x+" && cmd == "TR")
        return "y-";
    if (way == "x-" && cmd == "TL")
        return "y-";
    if (way == "x-" && cmd == "TR")
        return "y+";
    if (way == "x-" && cmd == "TB")
        return "x+";
    if (way == "y-" && cmd == "TL")
        return "x+";
    if (way == "y-" && cmd == "TR")
        return "x-";
    if (way == "y-" && cmd == "TB")
        return "y+";
    return "delete warning :)";
}

vector<int> robotPosition(string s)
{
    // Khởi tạo
    string way = "y+"; // y cộng là hướng lên trên
    vector<int> position = {0, 0};

    // Vector chứa các lệnh cmd
    vector<string> vCmd = split(s);

    // Thực hiện lệnh
    for (auto &&cmd : vCmd)
        if (cmd[0] == 'G') // cmd "Go x"
        {
            int step = xInGoX(cmd);
            position = cmdGoX(position, way, step);
        }
        else
            way = cmdRotates(way, cmd);
    return position;
}

int main()
{
    string cmd = "Go 2,TL,Go 2"; // [-2, 2]
    cout << robotPosition(cmd);
    return 0;
}
