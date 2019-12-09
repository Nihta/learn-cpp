/**
 * Cho một mảng số nguyên v, tìm contiguous subarray có tổng tối đa.
 * Trả về tổng đó.
 * Contiguous subarray: là tập con của mảng gồm các phần tử liên tiếp.
 * Lưu ý [] cũng là một tập con của mảng.
*/
#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(std::vector<int> v)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum > res)
                res = sum;
        }
    }
    return res;
}

int main()
{
    cout << maxSubarray({-1, 7, -2, 3, 4, 0, 1, -1}) << endl; // 13
    cout << maxSubarray({-1, -2, -5, -1}) << endl;            // -1
    return 0;
}
