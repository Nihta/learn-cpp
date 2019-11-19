/* 
 n đứa trẻ đã có m miếng kẹo.
 Chúng muốn ăn nhiều kẹo nhất có thể, nhưng mỗi đứa trẻ phải ăn chính xác lượng kẹo như các đứa trẻ khác.
 Xác định có bao nhiêu miếng kẹo sẽ được ăn bởi tất cả trẻ em cùng nhau.
 Các miếng kẹo lẻ sẽ không thể chia.
 */
#include <iostream>
using namespace std;

int candies(int n, int m) {
    return m/n*n;
}

int main() {
    cout << candies(3, 10);
    return 0;
}