/**
 * Bạn muốn biến số nguyên đã cho thành một số chỉ có một chữ số khác không
 * bằng cách sử dụng phương pháp làm tròn đuôi.
 * Điều này có nghĩa là ở mỗi bước, chúng ta lấy chữ số cuối cùng của số và
 * làm tròn nó thành 0 hoặc 10.
 * Nếu nó nhỏ hơn 5, chúng ta làm tròn nó thành 0, nếu nó lớn hơn hoặc bằng 5
 * chúng ta làm tròn nó thành 10 (tăng chữ số nằm trước nó thêm 1).
 * Quá trình dừng lại ngay lập tức khi chỉ còn một chữ số khác không.
 */
#include <iostream>
using namespace std;

int rounders(int n) {
    int i;
    for(i = 1; n/10 != 0; i*=10, n/=10)
        if(n%10 >= 5)
            n+=10;

    return i * n;
}

int main() {
    cout << rounders(1234); // 1000
    return 0;
}