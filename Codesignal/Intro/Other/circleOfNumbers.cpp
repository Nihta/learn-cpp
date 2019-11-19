/*
Xem xét các số nguyên từ 0 đến n - 1 được viết dọc theo vòng tròn theo cách
sao cho khoảng cách giữa hai số lân cận bằng nhau (lưu ý rằng 0 và n - 1 cũng lân cận)
Cho n và FirstNumber, tìm số được viết ở vị trí hoàn toàn ngược lại với FirstNumber.

Ví dụ: n = 12 (giống đồng hồ) FirstNumber = 3 => result = 9
*/
#include <iostream>
using namespace std;

int circleOfNumbers(int n, int firstNumber)
{
    return (n/2 + firstNumber)%n;
}

int main()
{
    cout << circleOfNumbers(12, 3);
    return 0;
}