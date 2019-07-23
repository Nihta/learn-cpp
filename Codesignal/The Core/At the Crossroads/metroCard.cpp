/**
 * Cho số ngày trong tháng trước. (28 or 29 or 30 or 31)
 * Tính xem tháng này có thể có bao nhiêu ngày
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> metroCard(int lastNumberOfDays) {
    if (lastNumberOfDays == 31)
        return {28, 30, 31};
    return {31};
}

int main() {
    for(int i : metroCard(31))
        cout << i << " ";
    return 0;
}