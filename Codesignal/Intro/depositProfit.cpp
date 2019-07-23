/*
Bạn đã gửi một số tiền cụ thể vào tài khoản ngân hàng của bạn (deposit)
Mỗi năm số dư của bạn tăng với rate% như nhau (lãi kép)
Với giả định rằng bạn không thực hiện bất kỳ khoản tiền gửi bổ sung nào
Hãy tìm hiểu mất bao lâu để số dư của bạn vượt qua threshold cụ thể
 */
#include <iostream>
using namespace std;

// Note: Dùng kiểu số nguyên sẽ gây ra lặp vô hạn
int depositProfit(int deposit, int rate, int threshold) {
    int year = 0;

    double money = deposit;
    while (money < threshold)
        money *= (double)(100 + rate)/100, ++year;

    return year;
}

int main()
{
    cout << depositProfit(1, 1, 200); // 533 Năm
    return 0;
}