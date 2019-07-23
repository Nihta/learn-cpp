/**
 * Bạn được cho hai số nguyên, n và m.
 * Tìm vị trí của bit ngoài cùng bên phải giống nhau trong biểu diễn nhị phân
 * của chúng (đảm bảo rằng một bit như vậy tồn tại), đếm từ phải sang trái.
 * Return kết quả dạng 2 mũ pos
 */
#include <iostream>
using namespace std;

int equalPairOfBits(int n, int m) {
    return ~(n ^ m) & ((n ^ m) + 1);
}

int main() {
    cout << equalPairOfBits(10, 11); // 2
    return 0;
}