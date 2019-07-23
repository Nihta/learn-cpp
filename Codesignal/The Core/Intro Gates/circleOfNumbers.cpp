/**
 * Xem xét các số nguyên từ 0 đến n - 1 được viết dọc theo vòng tròn
 * theo cách sao cho khoảng cách giữa hai số lân cận bằng nhau
 * Lưu ý rằng 0 và n - 1 cũng lân cận (n = 12 giống đồng hồ).
 * Cho n và FirstNumber, tìm số được viết ở vị trí hoàn toàn ngược lại với FirstNumber.
 */
#include <iostream>
using namespace std;

int circleOfNumbers(int n, int firstNumber) {
    return (firstNumber + n/2) % n;
}

int main() {
    cout << circleOfNumbers(10, 2); // 7
    return 0;
}