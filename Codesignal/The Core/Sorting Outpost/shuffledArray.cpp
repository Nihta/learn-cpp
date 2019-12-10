/**
 * Cho mảng được xáo trộn bao gồm các phần tử :
 * a1, a2, ..., an, a1 + a2 + ... + an theo thứ tự ngẫu nhiên
 * Trả về mảng đã sắp xếp của các phần tử gốc a1, a2, ..., an.
*/
#include <iostream>
#include <vector>
#include <algorithm>
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

// Ý tưởng: tổng các phần tử gốc thì tổng của tất cả các phần tử trong mảng chia 2
std::vector<int> shuffledArray(std::vector<int> shuffled)
{
    vector<int> res;
    int sumArr = 0;
    for (int i : shuffled)
        sumArr += i;
    int sumOrigin = sumArr / 2;

    bool isDel = true;
    for (int elm : shuffled)
    {
        if (isDel && elm == sumOrigin)
        {
            isDel = false;
            continue;
        }
        res.push_back(elm);
    }

    sort(res.begin(), res.end());

    return res;
}

int main()
{
    cout << shuffledArray({1, 12, 3, 6, 2}) << endl;  // { 1, 2, 3, 6}
    cout << shuffledArray({1, -3, -5, 7, 2}) << endl; // { -5, -3, 2, 7}
    return 0;
}
