/**
 * https://app.codesignal.com/arcade/code-arcade/spring-of-integration
 *
 * Guaranteed constraints: 1 ≤ levelNum, levelHeight ≤ 25.
 * For levelNum = 2 and levelHeight = 4, the output should be:
 *                     ___
 *             *          |
 *             *          | -- the crown
 *            ***      ___|
 *           *****        |
 *          *******       | -- level 1
 *         *********      |
 *        ***********  ___|
 *          *******       |
 *         *********      | -- level 2
 *        ***********     |
 *       ************* ___|
 *           *****        | -- the foot
 *           *****     ___|
 *
 * For levelNum = 4 and levelHeight = 6, the output should be:
 *
 *              *
 *              *
 *             ***
 *            *****
 *           *******
 *          *********
 *         ***********
 *        *************
 *       ***************
 *           *******
 *          *********
 *         ***********
 *        *************
 *       ***************
 *      *****************
 *          *********
 *         ***********
 *        *************
 *       ***************
 *      *****************
 *     *******************
 *         ***********
 *        *************
 *       ***************
 *      *****************
 *     *******************
 *    *********************
 *           *******
 *           *******
 *           *******
 *           *******
*/

#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<string> v)
{
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << '\n';
    return os;
}

std::vector<std::string> christmasTree(int levelNum, int levelHeight)
{
    // Khoảng cách từ đỉnh cây đến lề bên trái
    int distanceMax = levelNum + levelHeight;
    vector<string> res;
    // crown
    res.push_back(string(distanceMax, ' ') + "*");
    res.push_back(string(distanceMax, ' ') + "*");
    res.push_back(string(distanceMax - 1, ' ') + "***");
    // body
    for (int i = 0; i < levelNum; i++)
    {
        for (int j = 0; j < levelHeight; j++)
        {
            string line = string(5 + i * 2 + j * 2, '*');
            res.push_back(string(distanceMax - line.length() / 2, ' ') + line);
        }
    }
    // foot
    for (int i = 0; i < levelNum; i++)
    {
        string lineFoot = string(levelHeight % 2 == 1 ? levelHeight : levelHeight + 1, '*');
        res.push_back(string(distanceMax - lineFoot.length() / 2, ' ') + lineFoot);
    }

    return res;
}

int main()
{
    cout << christmasTree(2, 4) << endl;
    return 0;
}
