/*
Cho một mảng
Thay thấy tất cả các phần tử bằng elemToReplace thành substitutionElem trong mảng đó
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arrayReplace(vector<int> v, int elemToReplace, int substitutionElem){
    replace(v.begin(), v.end(), elemToReplace, substitutionElem);
    return v;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 1, 1, 1, 6, 7, 8, 9, 1};
    v = arrayReplace(v, 1, 10);
    for(int i : v)
        cout << i << " ";
    return 0;
}