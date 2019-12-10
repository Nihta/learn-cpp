/**
 * Cho mảng a: 1 ≤ a.length ≤ 1000, -1 ≤ a[i] ≤ 1000
 * Bao gồm phần tử -1 và các số nguyên dương
 * Giữ nguyên các phần tử -1 và sắp xếp các phần tử khác theo thứ tự không giảm
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortByHeight(vector<int> v)
{
    // Vector vSort bao gồm các phần tử khác -1
    vector<int> vSort;
    for(auto i : v)
        if(i != -1)
            vSort.push_back(i);
    // Sắp xếp
    sort(vSort.begin(), vSort.end());

    // Thay thế các phần tử != -1 trong v bằng các phần tử đã sắp xếp trong vSort
    int index = 0;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] != -1)
            v[i] = vSort[index++];

    return v;
}

int main() {
    vector<int> v ={-1, 50, 40, -1, 10, 20, 30}; // {-1, 10, 20, -1, 30, 40, 50}
    for (auto &&i : sortByHeight(v))
        cout << i << " ";
    return 0;
}
