/**
 * Có bao nhiêu nguyên x có đúng k ước với: l < x <= r
*/

#include <iostream>
using namespace std;

int divNumber(int k, int l, int r)
{
    int res = 0;
    for (int i = l; i <= r; i++)
    {
        int count = 0;
        for (int j = 1; j <= i && count <= k; j++)
            if (i % j == 0)
                count++;

        if (count == k)
            res++;
    }
    return res;
}
int main()
{
    cout << divNumber(3, 2, 49); // 4
    return 0;
}
