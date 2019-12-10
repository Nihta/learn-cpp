/**
 * Bạn được cung cấp một mảng các số nguyên a,
 * Một range sum query được xác định bởi một cặp số nguyên không âm l và r (l <= r)
 * Đầu ra cho một range sum query trên mảng đã cho a là tổng của tất cả các
 * phần tử trong mảng a có các chỉ số từ l đến r (bao gồm).
 * Bạn có mảng a và danh sách các range sum query q.
 * Tìm một thuật toán có thể sắp xếp lại mảng a theo cách sao cho tổng của tất cả
 * đầu ra của truy được tối đa hóa và trả về tổng này
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ý tưởng: Xếp số lớn nhất vào vị trí có tần xuất xuất hiện nhiều nhất trong query
int maximumSum(std::vector<int> a, std::vector<std::vector<int>> q)
{
    sort(a.begin(), a.end(), [](int i, int j) { return i > j; });

    vector<int> count(a.size(), 0);
    for (vector<int> query : q)
        for (int i = query[0]; i <= query[1]; i++)
            count[i]++;
    sort(count.begin(), count.end(), [](int i, int j) { return i > j; });

    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (count[i] == 0)
            break;
        res += a[i] * count[i];
    }
    return res;
}

int main()
{
    cout << maximumSum({2, 1, 2},
                       {{0, 1}})
         << endl; // 4
    cout << maximumSum({9, 7, 2, 4, 4},
                       {{1, 3},
                        {1, 4},
                        {0, 2}})
         << endl; // 62
    return 0;
}
