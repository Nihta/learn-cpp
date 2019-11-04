// Tính tổng của tất cả phần tử có chỉ số chẵn và lẻ
#include <iostream>
#include <vector>
using namespace std;
ostream &operator<<(ostream &os, vector<int> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}

std::vector<int> alternatingSums(std::vector<int> a)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < a.size(); i += 2)
    {
        x += a[i];
        y += a[i + 1];
    }
    return {x, y};
}

int main()
{
    cout << alternatingSums({50, 60, 60, 45, 70}); // 180, 105
    return 0;
}
