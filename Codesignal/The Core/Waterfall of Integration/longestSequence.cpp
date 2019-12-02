/**
 * Cho một dãy các số nguyên v, tìm độ dài lớn nhất của subsequence mà nó là
 * arithmetic progression (cấp số cộng). 1 ≤ v.size() ≤ 20
 *  Subsequence: là một dãy có thể được bắt nguồn từ một dãy khác bằng cách xóa một số phần tử (có thể, không có) mà không thay đổi thứ tự của các phần tử còn lại.
*/
#include <iostream>
#include <vector>
using namespace std;

int longestSequence(vector<int> v)
{
    int res = 1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            int diff = v[j] - v[i]; // diff là công sai
            if (diff == 0)
                continue;

            int count = 1;
            int numLast = v[i];
            for (int k = j; k < v.size(); k++)
            {
                if (v[k] - numLast == diff)
                {
                    count++;
                    numLast = v[k];
                }
            }
            if (count > res)
                res = count;
        }
    }
    return res;
}

int main()
{
    cout << longestSequence({1, 7, 3, 5, 4, 2}) << endl;       // 3: 1, 3, 5
    cout << longestSequence({4, 1, 2, 4, 3, 5, 4, 6}) << endl; // 4: 1, 2,3,4
    return 0;
}
