/*
Hai cánh tay mạnh như nhau nếu trọng lượng nặng nhất mà chúng có thể nâng bằng nhau
Hai người mạnh như nhau nếu cánh tay mạnh nhất của họ mạnh như nhau (cánh tay mạnh nhất có thể là cả bên phải và bên trái), và cánh tay yếu nhất của họ cũng vậy.
Cho khả năng nâng cánh tay của bạn và bạn của bạn kiểm tra xem hai người có mạnh như nhau không?
 */
#include <iostream>
#include <algorithm>
using namespace std;

bool areEquallyStrong(int youLeft, int youRight, int friLeft, int friRight) {
    return minmax(youLeft, youRight) == minmax(friLeft, friRight);
}

int main()
{
    cout << boolalpha << areEquallyStrong(10, 8, 8, 10);
    return 0;
}