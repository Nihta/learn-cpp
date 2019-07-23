/**
 * Chi phí gọi điện thoại được xác định như sau: 
 *    Phút đầu tiên của cuộc gọi có giá min1 xu
 *    Mỗi phút từ thứ 2 đến thứ 10 (bao gồm nó) chi phí min2_10 xu
 *    Mỗi phút từ phút thứ 10 chi phí min11 xu
 * Bạn có s xu trong tài khoản. Thời lượng của cuộc gọi dài nhất (tính bằng
 * phút được làm tròn xuống số nguyên gần nhất) bạn có thể gọi là bao nhiêu?
 */
#include <iostream>
using namespace std;

int phoneCall(int min1, int min2_10, int min11, int S) {
    if (S < min1)
        return 0;

    if (S < min1 + 9 * min2_10)
        return 1 + (S - min1)/min2_10;

    return 1 + 9 + (S - min1 - 9 * min2_10)/min11;
}

int main() {
    cout << phoneCall(3, 1, 2, 20) << "m"; // 14
    return 0;
}