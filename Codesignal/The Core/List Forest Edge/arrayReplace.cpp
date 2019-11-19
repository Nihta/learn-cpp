/**
 * Thay thế tất cả phần tử elemToReplace bằng phần tử substitutionElem
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arrayReplace(vector<int> inputArray, int elemToReplace, int substitutionElem)
{
    for (int i = 0; i < inputArray.size(); i++)
        if(inputArray[i] == elemToReplace)
            inputArray[i] = substitutionElem;
    return inputArray;
}

vector<int> arrayReplace2(vector<int> v, int elemToReplace, int substitutionElem)
{
    replace(v.begin(), v.end(), elemToReplace, substitutionElem);
    return v;
}


int main() {
    vector<int> v = {1, 2, 2, 1, 2, 2, 1};
    for(int i : arrayReplace(v, 1, 9))
        cout << i << " ";
    cout << endl;
    for(int i : arrayReplace2(v, 1, 6))
        cout << i << " ";
    return 0;
}