/**
 * Hãy xem xét một biểu thức số học có dạng a # b = c.
 * Kiểm tra xem có thể thay thế # bằng một trong bốn toán tử: +, -, * hoặc /
 * để có được biểu thức chính xác không?
 */
#include <iostream>
using namespace std;

bool arithmeticExpression(int a, int b, int c) {
    if(a+b == c || a-b == c || a*b == c || (a/b == c && a%b == 0))
        return true;
    return false;
}

int main() {
    cout << int('A');
    cout << boolalpha << arithmeticExpression(50, 10, 5);
    return 0;
}
