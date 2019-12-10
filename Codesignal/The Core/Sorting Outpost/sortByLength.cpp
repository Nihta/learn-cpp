/**
 * Cho một mảng các string, sắp xếp chúng theo thứ tự độ dài tăng dần.
 * Nếu hai chuỗi có cùng độ dài, thứ tự tương đối của chúng phải
 * giống như trong mảng ban đầu.
*/
#include <iostream>
#include <algorithm>
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

std::vector<std::string> sortByLength(std::vector<std::string> v)
{
    stable_sort(v.begin(), v.end(), [](string s1, string s2) { // Lambda expression
        return s1.length() < s2.length();
    });
    return v;
}

int main()
{
    cout << sortByLength({"abc",
                          "",
                          "aaa",
                          "a",
                          "zz"})
         << endl; // {"", "a", "zz", "abc", "aaa"}
    return 0;
}
