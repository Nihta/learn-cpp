/**
 * Khi một ngọn nến đốt xong, nó còn lại một phần sáp thừa.
 * Từ makeNew (số lượng) sáp thừa trên có thể tạo thành một cây nến khác.
 * Bạn có candlesNumber cây nến.
 * Tổng số nến bạn có thể đốt là bao nhiêu?
 * Giả sử rằng bạn tạo ra nến mới ngay khi bạn có đủ số sáp thừa?
 */
#include <iostream>
using namespace std;

int candles(int candlesNumber, int makeNew) {
    int result = 0, leftovers = 0;
    while(candlesNumber != 0)
    {
        result += candlesNumber;
        leftovers += candlesNumber;
        candlesNumber = leftovers/makeNew;
        leftovers -= leftovers/makeNew*makeNew;
    }
    return result;
}

/**
 * Đầu tiên đốt n cây -> ta còn lại c-n cây và cộng thêm 1 cây tái chế từ n phần
 * nến thừa vừa đốt
 */
int candles2(int c, int n) {
    return c >= n ? n + candles(c - n + 1, n) : c;
}

int main() {
    cout << candles(15, 5) << endl; // 18
    cout << candles2(15, 5);
    return 0;
}