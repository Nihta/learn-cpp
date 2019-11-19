/**
 * Cho một vector các số nguyên và số nguyên dương k, nhiệm vụ của bạn là
 * xóa đi k số đầu tiên mà số đó nhỏ hơn số đứng ngay nó (a[i] và a[i+1]).
 * Đảm bảo có nhiều hơn hoặc đủ k phần tử để xóa.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    for (auto &&i : v)
        os << i << ' ';
    return os;
}

vector<int> removeElements(vector<int> v, int k)
{
    vector<int> res;
    stack<int> st;
    int count = 0, i;

    for (i = 0; i < v.size() && count != k; i++)
        if (st.empty() || st.top() >= v[i])
            st.push(v[i]);
        else
        { // Xóa hết tất cả số trong stack không thỏa mãn số đứng trước >= số liền sau
            while (!st.empty() && st.top() < v[i] && count != k)
                st.pop(), count++;
            st.push(v[i]);
        }

    // Chuyển stack thành vector
    while (!st.empty())
    {
        res.push_back(st.top()),
            st.pop();
    }
    reverse(res.begin(), res.end());

    // Thêm các phần tử còn lại trong vector vào do lúc xóa xong k số vòng lặp dừng
    for (; i < v.size(); i++)
        res.push_back(v[i]);

    return res;
}

int main()
{
    cout << removeElements({20, 10, 25, 30, 40}, 2); // 25, 30, 40
    return 0;
}
