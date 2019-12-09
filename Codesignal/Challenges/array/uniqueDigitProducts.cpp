/**
 * Gọi product(x) là tích các chữ số của x.
 * Cho một mảng các số nguyên a, tính product(x) cho mỗi x trong a và trả về
 * số lượng kết quả khác nhau mà bạn nhận được.
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int product(int x)
{
    if (x == 0)
        return 0;
    int res = 1;
    while (x != 0)
    {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int uniqueDigitProducts(std::vector<int> a)
{
    set<int> uniqueProduct;
    for (int x : a)
        uniqueProduct.insert(product(x));
    return uniqueProduct.size();
}

int main()
{
    cout << uniqueDigitProducts({2, 8, 121, 42, 222, 23}) << endl; // 3
    return 0;
}
