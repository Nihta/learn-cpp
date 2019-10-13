/**
 * Cho hai số nguyên dương a và b, hãy xem xét thao tác sau: nếu một trong các
 * số nguyên chia hết cho số kia thì thay thế số nguyên này bằng kết quả của phép
 * chia. Hoạt động này được áp dụng tuần tự cho đến khi nó ngừng hoạt động.
 * Trả về số lần thao tác được áp dụng.
 * Đảm bảo tồn tại câu trả lời.
*/

#include <iostream>
using namespace std;

int numberOfOperations(int a, int b)
{
    if (a < b)
        std::swap(a, b);
    if (a % b != 0)
        return 0;
    return 1 + numberOfOperations(a / b, b);
}

int main()
{
    cout << numberOfOperations(432, 72) << endl; // 4
    cout << numberOfOperations(7, 14); // 1
    return 0;
}
