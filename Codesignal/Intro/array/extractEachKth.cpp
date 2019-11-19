// Cho mảng số nguyên, loại bỏ tất cả phần tử có vị trí chia hết cho k
#include <iostream>
#include <vector>
using namespace std;

vector<int> extractEachKth(vector<int> v, int k)
{
    for(int i = v.size()/k; i >= 1; --i)
        v.erase(v.begin() + i*k-1);
    return v;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    extractEachKth(v, 3);
    for(int i : v)
        cout << i << " ";
    return 0;
}