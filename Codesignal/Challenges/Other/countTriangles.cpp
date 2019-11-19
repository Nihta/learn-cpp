/**
 * Cho một tập hợp các điểm, tìm số tam giác có diện tích khác không
 * được hình thành bởi ba điểm trong tập hợp điểm đã cho.
*/
#include <iostream>
#include <vector>
using namespace std;

int countTriangles(vector<int> x, vector<int> y)
{
    int res = 0;
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = i + 1; j < x.size(); j++)
        {
            for (int k = j + 1; k < x.size(); k++)
            {
                double s = (x[i] - x[j]) * (y[i] - y[k]) - (x[i] - x[k]) * (y[i] - y[j]);
                if (s != 0)
                    res++;
            }
        }
    }
    return res;
}

int main()
{
    cout << countTriangles({0, 0, 1, 1}, {0, 1, 1, 0}); // 4
    return 0;
}
