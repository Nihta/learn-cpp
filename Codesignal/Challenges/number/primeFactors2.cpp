// Tìm tất cả các thừa số nguyên tố riêng biệt của một số nguyên n cho trước
// 1 ≤ n ≤ 10e9
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
vector<int> primeFactors2(int n)
{
    vector<int> res;
    for (int i = 2; i <= n; i++)
        if (n % i == 0)
        {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
        // Khi i >= sqrt(n) thì bản thân n lúc này là số nguyên tố (Mấu chốt vượt qua time limit)
        else if (i*i >= n)
        {
            res.push_back(n);
            break;
        }
    return res;
}
int main()
{
    cout << primeFactors2(1) << endl; // { }
    cout << primeFactors2(2) << endl; // { 2 }
    cout << primeFactors2(20) << endl; // { 2, 5 }
    cout << primeFactors2(123456789) << endl; // { 3, 3607, 3803}
    cout << primeFactors2(987654321) << endl; // { 3, 17, 379721 }
    cout << primeFactors2(987612345); // { 3, 5, 823, 2963 }
    return 0;
}
