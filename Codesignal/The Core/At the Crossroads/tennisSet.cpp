/**
 * Trong quần vợt:
 * Người chơi đầu tiên thắng 6 trận được tuyên bố là người chiến thắng trừ khi đối thủ của họ đã thắng 5 trận,
 * trong trường hợp đó, tiếp tục chơi cho đến khi một trong 2 người chơi thắng 7 trận.
 * Cho hai số nguyên score1 và score2, nhiệm vụ của bạn là xác định xem có thể
 * kết thúc một trận quần vợt với tỉ số cuối cùng là score1 : score2 không?
 */
#include <iostream>
using namespace std;

bool tennisSet(int score1, int score2) {
    return (score1 == 6 && score2 < 5) || (score2 ==6 && score1 < 5)
    || (score1 == 7 && 5 <= score2 && score2 <= 6)
    || (score2 == 7 && 5 <= score1 && score1 <= 6);
}

int main() {
    cout << boolalpha << tennisSet(7, 6);
    return 0;
}