/**
 * Tính số đồng xu tối thiểu mà bạn có thể dùng để mua chuối có giá price.
 * Vector coins chứ giá trị của những đồng xu:
 *     coins[0] = 1
 *     coins[i] % coins[i-1] == 0
 */
#include <iostream>
#include <vector>
using namespace std;

int minimalNumberOfCoins(vector<int> coins, int price) {
    int result = 0;
    for (int i = coins.size()-1; i >= 0 && price > 0; i--)
        while (coins[i] <= price)
        {
            price -= coins[i];
            result++;
        }
    return result;
}

int main() {
    cout << minimalNumberOfCoins({1, 2, 10}, 28);
    return 0;
}