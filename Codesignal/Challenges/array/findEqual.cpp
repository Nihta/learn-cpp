// Kiểm tra xem mảng có ít nhất 2 số bằng nhau không
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool findEqual(std::vector<int> sequence)
{
    for (int i : sequence)
        if (count(sequence.begin(), sequence.end(), i) >= 2)
            return true;
    return false;
}

int main()
{
    cout << std::boolalpha << findEqual({1, 2, 3, 1, 4}) << endl; // true
    cout << findEqual({1, 2, 3, 4, 5}) << endl; // false
    return 0;
}
