/**
 * Cho một số nguyên: 20 ≤ n ≤ 6000
 * Trả về danh sách ngắn nhất các số Fibonacci khác nhau có tổng bằng n,
 * được sắp xếp theo thứ tự tăng dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}

bool backtracking(vector<int> &res, vector<int> &fab, const int n)
{
    // Base case
    int sumRes = 0;
    for (int i : res)
        sumRes += i;
    if (sumRes == n)
        return true;

    // Quay lui
    if (sumRes > n)
        return false;

    for (int i = fab.size() - 1; i >= 0; i--)
    {
        if (fab[i] < 0)
            continue;
        // Đánh dấu các số đã được sử dụng trong fab bằng cách chuyển nó thành số âm
        res.push_back(fab[i]);
        fab[i] *= -1;

        if (backtracking(res, fab, n))
            return true;
        else
        {
            res.pop_back();
            fab[i] *= -1;
        }
    }

    // Quay lui
    return false;
}

vector<int> fibonacciSum(int n)
{
    vector<int> fab = {0, 1};
    while (fab.back() < n)
        fab.push_back(fab.back() + fab[fab.size() - 2]);

    vector<int> res;
    backtracking(res, fab, n);
    reverse(res.begin(), res.end());

    return res;
}

vector<int> fibonacciSum2(int n)
{
    vector<int> fab = {0, 1};
    while (fab.back() < n)
        fab.push_back(fab.back() + fab[fab.size() - 2]);

    vector<int> res;
    for (int i = fab.size() - 1; i >= 0 && n; i--)
        if (fab[i] <= n)
        {
            res.push_back(fab[i]);
            n -= fab[i];
        }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << fibonacciSum(20) << endl; // 2, 5, 13
    cout << fibonacciSum2(20);        // 2, 5, 13

    return 0;
}
