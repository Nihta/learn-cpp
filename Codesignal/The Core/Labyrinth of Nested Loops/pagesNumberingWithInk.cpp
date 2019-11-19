/**
 * Bạn chịu trách nhiệm thiết kế cơ chế đánh số trang trong máy in.
 * Bạn biết máy in có thể in bao nhiêu chữ số với mực còn lại .
 * Bạn phải đánh bắt đầu từ trang hiện tại current (phải đánh cả nó)
 * Cho số trang hiện tại (current) và số lượng chữ số mà máy có thể in cho đến
 * khi hết mực (numberOfDigits), tìm trang cuối mà máy có thể đánh số.
 * Một trang được tính là đánh số nếu nó được in số đầy đủ trên đó, ví dụ: nếu
 * nó in trang 102 nhưng chỉ có mực cho hai chữ số thì trang này sẽ không được 
 * coi là được đánh số.
 */
#include <iostream>
using namespace std;

int pagesNumberingWithInk(int current, int numberOfDigits) {
    string tmp;
    do
    {
        tmp = to_string(current++);
        numberOfDigits -= tmp.size();
    } while (tmp.size() <= numberOfDigits);

    return current - 1;
}

int main() {
    cout << pagesNumberingWithInk(8, 4); // 10: 8, 9, 10
    return 0;
}