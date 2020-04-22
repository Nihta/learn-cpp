/**
 * Xác định xem có thể sắp xếp một mảng (nghiêm ngặt) bằng cách đảo ngược một
 * trong những contiguous subarrays.
 * Contiguous subarray: một tập hợp con các phần tử của mảng đó bao gồm các phần
 * tử liên tiếp.
*/
#include <iostream>
#include <vector>
using namespace std;

bool reverseToSort(std::vector<int> v) {
    int start = -1;
    int end = -1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i-1] > v[i])
        {
            if (start == -1)
                start = i-1;
        } else {

        }
    }

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i-1] >= v[i])
            return false;
    }
    return true;
}


int main() {

    return  0;
}
