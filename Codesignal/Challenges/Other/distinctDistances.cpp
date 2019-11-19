/**
 * Đề thực tế khác =) nhưng nó tương tự return 3 nếu 3 cạnh có thể tạo thành tam
 * giác ngược lại return 4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distinctDistances(std::vector<int> v)
{
    sort(v.begin(), v.end());
    return v[0] + v[1] >= v[2] ? 3 : 4;
}

int main()
{
    cout << distinctDistances({3, 4, 5}) << endl;  // 3
    cout << distinctDistances({4, 5, 10}); // 4
    return 0;
}
