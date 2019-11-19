/*
Cho một mảng các số nguyên.
Tìm sự khác biệt tuyệt đối tối đa giữa bất kỳ hai phần tử lân cận nào của nó.

Input:      {1,2,10,0,5}
Output:     10 - 0 = 10
*/
#include <iostream>
#include <vector>
using namespace std;

int arrayMaximalAdjacentDifference(vector<int> v)
{
    int result = 0;
    for(int i = 1; i < v.size(); ++i)
        result = max(result, abs(v[i] - v[i-1]));
    return result;
}

int main()
{
    cout << arrayMaximalAdjacentDifference({1,2,10,0,5});
    return 0;
}