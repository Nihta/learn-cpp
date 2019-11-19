// Tìm vị trí bit 0 ngoài cùng bên phải thứ 2(pos)
// Return dạng 2 mũ pos
#include <iostream>
using namespace std;

int secondRightmostZeroBit(int n) {
    return ((n+1|n)+1) & ~n;
}

int main() {
    // 37 100101
    cout << secondRightmostZeroBit(37); // 8
    return 0;
}
/**
 * 100101
 * +1 chuyển bit 0 đầu tiên(phải sang) thành 1
 * 100010
 * |n chuyển bit 0 vừa tạo ra (do + 1) trở lại thành 1
 * 100111 +1 chuyển bit 0 thứ 2 (so với n) thành 1
 * 
 * ~n (011010) Chuyển tất cả 0 (tồn tại ban đầu trong n) thành 1
 * 
 * 101000 & ~n => kết quả
 * 
 * 001000
 */