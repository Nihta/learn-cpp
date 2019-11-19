/**
 * Cần bổ sung tối thiểu bao nhiêu số để thu được mảng tăng dạng x, x+1, x+2
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int makeArrayConsecutive2(vector<int> v) {
    return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()) - v.size() + 1;
}

int main() {
    vector<int> v = {6, 2, 3, 8}; // 3
    cout << makeArrayConsecutive2(v);
    return 0;
}