/*
Cho một số nguyên product: 0 ≤ product ≤ 600
Tìm sô nguyên dương nhỏ nhất (lớn hơn 0) mà tích các chữ số bằng với product
Không tìm được return -1 
 */
#include <iostream>
using namespace std;

int digitsProduct(int product) {
    if (product < 10)
        return product == 0 ? 10 : product;

    string result = "";
    for (int i = 9; i >= 2; i--) 
        while (product % i == 0)
        {
            product /= i;
            result = char('0' + i) + result;
        }

    return product == 1 ? stoi(result) : -1;
}

int main()
{
    int i = 450; // 2559
    cout << digitsProduct(i);
    return 0;
}