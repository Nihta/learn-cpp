/**
 * Hãy xem xét thuật toán mã hóa sau:
 *     Đối với mỗi ký tự thay thế nó bằng mã ASCII thập phân của nó.
 *     Nối tất cả các số thu được.
 * Cho một chuỗi được mã hóa, trả về chuỗi ban đầu nếu biết rằng nó chỉ bao gồm
 * các chữ cái viết thường.
 */
#include <iostream>
using namespace std;

string decipher(string cipher) {
    string result;
    int tmp = 0;
    for (char ch : cipher)
    {
        tmp = tmp*10 + (ch - '0');
        if('a' <= tmp && tmp <= 'z')
            result += char(tmp), tmp = 0;
    }
    return result;
}

int main() {
    cout << decipher("10197115121"); // easy
    return 0;
}