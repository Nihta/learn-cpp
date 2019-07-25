/**
 * Định nghĩa the middle of the array  như sau:
 *    Nếu mảng có số lượng số phần lẻ, middle là phần tử ở giữa (chỉ mục size/2)
 *    Nếu mảng có phần tử chẵn thì middle = tổng của 2 phần tử ở giữa mảng
 * Một mảng gọi là smooth nếu phần tử đầu bằng phần tử cuối và bằng middle
 */
#include <iostream>
#include <vector>
using namespace std;

bool isSmooth(vector<int> v) {
    int middle;
    if(v.size()%2 == 1)
        middle = v.at(v.size()/2);
    else
        middle = v.at(v.size()/2-1) + v.at(v.size()/2);
    return v.front() == v.back() && v.back() == middle;
}

int main() {
    vector<int> v = {7, 2, 2, 5, 10, 7};
    cout << boolalpha << isSmooth(v);
    return 0;
}