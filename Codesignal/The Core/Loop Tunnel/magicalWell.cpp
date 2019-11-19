/**
 * Bạn đang đứng ở một cái giếng kỳ diệu.
 * Có hai số nguyên dương được viết trên đó: a và b.
 * Mỗi khi bạn ném một viên bi ma thuật vào giếng, nó sẽ cho bạn a*b $
 * và sau đó cả a và b đều tăng thêm 1.
 * Bạn có n viên bi ma thuật. Hỏi Bạn sẽ kiếm được bao nhiêu tiền?
 */
#include <iostream>
using namespace std;

int magicalWell(int a, int b, int n) {
    int money = 0;
    while(n--)
        money += a++ * b++;
    return money;
}

int main() {
    cout << magicalWell(1, 2, 2); // 8
    return 0;
}