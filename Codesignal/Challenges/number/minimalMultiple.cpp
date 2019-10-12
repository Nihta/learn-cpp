// Tìm bội số nhỏ nhất của số x mà không nhỏ hơn y

#include <iostream>
using namespace std;

int minimalMultiple(int x, int y)
{
    return y % x == 0 ? y : (y / x + 1) * x;
}

int main()
{
    cout << minimalMultiple(3, 9) << endl; // 9
    cout << minimalMultiple(5, 12);        // 15
    return 0;
}
