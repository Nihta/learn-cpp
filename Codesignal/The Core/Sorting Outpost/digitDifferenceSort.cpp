/**
 * Cho một mảng các số nguyên, sắp xếp các phần tử của nó theo sự khác biệt
 * của các chữ số lớn nhất và nhỏ nhất của phần tử đó. Trong trường hợp hòa,
 * thì phần tử với chỉ số lớn hơn trong mảng sẽ đến trước.
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

std::vector<int> digitDifferenceSort(std::vector<int> a)
{
    // Tìm sự khác biệt giữa chữ số lớn nhất và nhỏ nhất
    auto diff = [](int n) {
        vector<int> digit;
        while (n != 0)
        {
            digit.push_back(n % 10);
            n /= 10;
        }
        pair<vector<int>::iterator, vector<int>::iterator> mm;
        mm = minmax_element(digit.begin(), digit.end());
        return *mm.second - *mm.first;
    };

    stable_sort(a.begin(), a.end(), [diff](const int &x, const int &y) {
        return diff(x) <= diff(y);
    });

    return a;
}

int main()
{
    cout << digitDifferenceSort({152, 23, 7, 887, 243}) << endl; // { 7, 887, 23, 243, 152}
    return 0;
}
