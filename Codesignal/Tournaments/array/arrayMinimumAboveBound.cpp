// Tìm phần tử mảng lớn nhất mà nhỏ hơn x

#include <iostream>
#include <vector>
using namespace std;

int arrayMinimumAboveBound(vector<int> v, int x)
{
    int min, flag = 1;
    for (auto i : v)
    {
        if (i > x && (i < min || flag))
            min = i, flag = 0;
    }
    return min;
}

int main()
{
    cout << arrayMinimumAboveBound({1, 3, 5, 4, 2, 6}, 3); // 4
    return 0;
}
