/**
 * Bạn được cấp một số nguyên 32 bit.
 * Lấy biểu diễn nhị phân của nó, chia các bit thành từng cặp (bit số 0 và 1,
 * bit số 2 và 3, v.v.) và trao đổi bit trong mỗi cặp.
 * Sau đó trả về kết quả dưới dạng số thập phân.
 */
#include <iostream>
using namespace std;

// Ý tưởng: Tách bit lẻ dịch sang trái, bit chẵn dịch sang phải
// 0xAAAAAAAA = 1010 1010 1010 1010 1010 1010 1010 1010
// 0x55555555 = 0101 0101 0101 0101 0101 0101 0101 0101
int swapAdjacentBits(int n) {
  return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
}

int main() {
    cout << swapAdjacentBits(74); // 133
    return 0;
}