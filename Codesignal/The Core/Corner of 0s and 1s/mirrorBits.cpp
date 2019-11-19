// Đảo ngược thứ tự của các bit trong một số nguyên cho trước.
#include <iostream>
#include <bitset>
using namespace std;

int mirrorBits(int a) {
    int result = 0;
    while(a != 0) {
        result <<= 1;
        result |= (a & 1);
        a >>= 1;
    }
    return result;
}


int main() {
    // 97 = 1100001
    cout << mirrorBits(97) << endl;
    return 0;
}