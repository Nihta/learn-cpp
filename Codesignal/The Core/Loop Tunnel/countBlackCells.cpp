/**
 * Hãy tưởng tượng một lưới hình chữ nhật màu trắng gồm n hàng và m cột được
 * chia thành hai phần bởi một đường chéo chạy từ góc trên cùng bên trái sang
 * góc dưới cùng bên phải. Bây giờ tô lưới bằng hai màu theo các quy tắc sau:
 *    Một ô được sơn màu đen nếu nó có ít nhất một điểm chung với đường chéo
 *    Nếu không, ô sẽ được sơn màu trắng.
 * Đếm số lượng ô được sơn màu đen.
 * 
 * Hữu ích https://en.wikipedia.org/wiki/Slope
 */
#include <iostream>
#include <algorithm>
using namespace std;


int countBlackCells(int n, int m) {
    return n - 1 + m - 1 + __gcd(n , m);
}

int main() {
    cout << countBlackCells(3, 4) << endl; // 6
    return 0;
}