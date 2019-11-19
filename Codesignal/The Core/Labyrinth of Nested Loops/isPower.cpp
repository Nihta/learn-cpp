// Xác định 1 ≤ n ≤ 400 có phải là lũy thừa của một số nguyên nào đó không?
// n = a^b với b >= 2
#include <iostream>
using namespace std;

bool isPower(int n) {
    if (n == 1)
        return true;
    for(int a = 2; a <= n; a++)
    {
        int i = a*a;
        while (i < n)
            i*=a;
        if (i == n)
            return true;
    }
    return false;
}

int main() {
    cout << boolalpha << isPower(6);
    return 0;
}