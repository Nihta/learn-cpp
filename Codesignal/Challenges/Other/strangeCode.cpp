/**
 * Bạn đã tìm thấy một máy mà khi được cung cấp hai số s và e sẽ tạo ra một mã
 * lạ gồm các chữ cái 'a' và 'b'. Máy dường như đang sử dụng thuật toán sau:
 *     1. Kiểm tra xem s có nhỏ hơn e - 1 thì tiếp tục bước 2, nếu không thoát.
 *     2. Tăng thêm s lên 1, giảm e đi 1
 *     3. Nếu đây là chữ cái đầu tiên mà nó sản xuất, thì tạo 'a'. Mặt khác, tạo
 *        ra một chữ cái khác với chữ cái mà nó tạo ra lần cuối (chỉ có thể tạo
 *        ra a và b)
 *      4. Quay lại bước 1
 *  Bạn phải viết một hàm mô phỏng hoạt động của máy.
*/

#include <iostream>
#include <vector>
using namespace std;

string strangeCode(int s, int e)
{
    string res;
    int step = (e - s) / 2;
    for (int i = 1; step-- > 0; i *= -1)
        res += i == 1 ? 'a' : 'b';
    return res;
}

int main()
{
    cout << strangeCode(10, 15) << endl; // "ab"
    cout << strangeCode(10, 9) << endl;  // ""
    cout << strangeCode(10, 16) << endl; // "aba"
    return 0;
}
