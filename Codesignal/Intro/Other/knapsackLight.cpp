/*
Bạn tìm thấy 2 hòm kho báu:
    Hòm 1:
            Nặng weight1
            Có trị giá value1
    Hòm 2:
            Nặng weight2
            Có trị giá value2
Bạn có thể mang vật nặng tối đa maxW
Tính giá trị số kho báu mà bạn có thể mang theo
 */
#include <iostream>
using namespace std;

int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW)
{
    // Mang cả 2 hòm
    if(weight1 + weight2 <= maxW)
        return value1 + value2;

    // Mang cả 1 trong 2 hòm ( bé hơn maxW) có giá trị lớn hơn
    int value = 0;
    if(weight1 <= maxW)
        value = value1;
    if(weight2 <= maxW && value < value2)
        value = value2;

    return value;
}

int main()
{
    cout << knapsackLight(10, 5, 6, 4, 8) << "$" << endl; // 10
    cout << knapsackLight(10, 5, 6, 4, 9) << "$" << endl; // 16
    cout << knapsackLight(10, 2, 15, 3, 1) << "$" << endl; // 0
    return 0;
}