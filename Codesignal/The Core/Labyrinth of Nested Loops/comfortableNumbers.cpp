/**
 * a cảm thấy comfortable với b nếu a ≠ b và b nằm trong đoạn
 * [a - s(a), a + s(a)] với s(a) là tổng các chữ số trong a.
 * Có bao nhiêu cặp (a, b) với a < b nằm trong đoạn [l, r] mà a và b đều
 * cảm thấy comfortable với nhau
 */
#include <iostream>
using namespace std;

int comfortableNumbers(int l, int r) {
    int count = 0;
    for (int a = l; a < r; a++)
        for (int b = a+1; b <= r; b++)
        {
            int sa = 0;
            for(int tmp = a; tmp != 0; tmp/=10)
                sa += tmp%10;

            if(a - sa <= b && b <= a + sa)
            {
                int sb = 0;
                for (int tmp = b; tmp != 0; tmp/=10)
                    sb += tmp%10;

                if(b - sb <= a && a <= b + sb)
                    count++;
            }
        }
    return count;
}

int main() {
    cout << comfortableNumbers(10, 12); // 2
    return 0;
}