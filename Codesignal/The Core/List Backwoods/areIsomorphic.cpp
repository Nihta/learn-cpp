/**
 *  Hai mảng hai chiều là đẳng cấu nếu chúng có cùng số hàng và mỗi cặp hàng
 * tương ứng chứa cùng một số phần tử.
 * Cho hai mảng hai chiều, kiểm tra xem chúng có phải là đẳng cấu không.
*/
#include <iostream>
#include <vector>
using namespace std;

bool areIsomorphic(vector<vector<int>> a, vector<vector<int>> b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
        if (a[i].size() != b[i].size())
            return false;
    return true;
}

int main() {
    cout << std::boolalpha << areIsomorphic({
        {1,1,1},
        {0,0}
    },
    {
        {2,1,1},
        {2,1}
    });
    return  0;
}
