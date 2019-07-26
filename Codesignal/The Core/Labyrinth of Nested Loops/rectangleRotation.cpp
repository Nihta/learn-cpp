/**
 * Một hình chữ nhật có các cạnh a và b được vẽ trên mặt phẳng Cartesian.
 * Tâm của nó (điểm giao nhau của các đường chéo) trùng với điểm (0, 0).
 * Nhưng các cạnh của hình chữ nhật không song song với các trục, thay vào đó
 * chúng đang tạo thành các góc 45 độ với các trục.
 * Có bao nhiêu điểm có tọa độ nguyên được đặt bên trong hình chữ nhật đã cho (bao gồm cả các cạnh của nó)?
 */
#include <iostream>
#include <math.h>
using namespace std;

/**
 * Do 4 cạnh màu xanh tạo góc 45 độ nên công thức 4 cạnh tương ứng là:
 *     f1(x, y) = x + y + u = 0 (Tam giác vuông 1 góc = 45 độ thì 2 cạnh góc
 *     f2(x, y) = x + y - u = 0  vuông bằng nhau)
 *     f3(x, y) = x - y + v = 0 (cạnh trên trái)
 *     f4(x, y) = x - y - v = 0 (cạnh dưới phải)
 *
 *  Điểm O (0,0) nằm trong hình chữ nhật nên:
 *     f1(0,0) =  u > 0
 *     f2(0,0) = -u < 0
 *     f3(0,0) =  v > 0
 *     f4(0,0) = -v < 0
 *
 * Suy ra nếu 1 điểm P(x, y) nằm trong hình chữ nhật thì yêu cầu 4 điều kiện:
 *     f1(x, y) = x + y + u > 0
 *     f2(x, y) = x + y - u < 0
 *     f3(x, y) = x - y + v > 0
 *     f4(x, y) = x - y - v < 0
 * <=> | x + y | < u và | x - y | < v
 */

int rectangleRotation(int a, int b) {
    double u = a/sqrt(2), v = b/sqrt(2);
    int max = int(sqrt(a*a + b*b)), count = 0;
    for (int x = -max; x <= max; x++)
        for (int y = -max; y <= max; y++)
            if(abs(x+y) < u && abs(x-y) < v)
                count++;
    return count;
}

int rectangleRotation2(int a, int b) {
    int c = a/sqrt(2);
    int d = b/sqrt(2);
    return (2*c*d + c + d) | 1;
}
// x|1 <=> nếu x chẵn thì cộng thêm 1

int main() {
    cout << rectangleRotation(6, 4) << endl; // 23
    cout << rectangleRotation2(6, 4);
    return 0;
}