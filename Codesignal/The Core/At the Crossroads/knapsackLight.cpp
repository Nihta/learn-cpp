/**
 * Bạn tìm thấy 2 item:
 *    Item1 nặng weight1, có giá trị value1
 *    Item2 nặng weight2, có giá trị value2
 * Tuy nhiên bạn chỉ có thể mang tối đa maxW
 * Trả về giá trị tối đa mà bạn có thể mang đi được?
 */
#include <iostream>
using namespace std;

int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
    if (weight1 + weight2 <= maxW)
        return value1 + value2;
    if (value1 > value2 && weight1 <= maxW)
        return value1;
    if (weight2 <= maxW)
        return value2;
    if (weight1 <= maxW)
        return value1;
    return 0;
}

int main() {
    cout << knapsackLight(10, 5, 6, 4, 8); // 10
    return 0;
}