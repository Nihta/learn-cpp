/**
 * Cho một string, kiểm tra xem nó có phải là geometric progression hay không?
 * Geometric progression là một chuỗi các số trong đó mỗi số sau số đầu tiên
 * được tìm thấy bằng cách nhân số trước với một số cố định, khác không.
 * Guaranteed constraints: 3 ≤ sequence.length ≤ 10, 1 ≤ sequence[i] ≤ 1000.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isGeometricProgression(vector<int> sequence)
{
    // Dùng cách này để tránh các trường hợp số không đổi là số thập phân
    for (int i = 2; i < sequence.size(); i++)
        if (sequence[i - 2] * sequence[i] != sequence[i - 1] * sequence[i - 1])
            return false;
    return true;
}

int main()
{
    cout << std::boolalpha << isGeometricProgression({1, 3, 9, 27, 81, 243}); // true
    cout << '\n'
         << isGeometricProgression({27, 9, 3, 1}); // true
    return 0;
}
