/**
 * Nhân 2 phân số, trả về kết quả là phân số tối giảm
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

std::vector<int> fractionMultiplication(std::vector<int> a, std::vector<int> b) {
    vector<int> res = {a[0]*b[0], a[1]*b[1]};
    int gcd = std::__gcd(res[0], res[1]);
    res[0] /= gcd;
    res[1] /= gcd;
    return res;
}

int main() {
    cout << fractionMultiplication({3,2}, {2,5}); // {3, 5}
    return  0;
}
