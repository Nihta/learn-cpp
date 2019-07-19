/*
Kiểm tra xem tất cả các chữ số của số nguyên đã cho có phải tất cả là chẵn hay không.
 */
#include <iostream>
using namespace std;

bool evenDigitsOnly(int n)
{
    string s = to_string(n);

    for (char ch : s)
        if((ch - '0')%2 != 0)
            return false;

    return true;
}

bool evenDigitsOnly2(int n)
{
    while(n)
    {
        if(n%10%2 != 0)
            return false;
        n/=10;
    }

    return true;
}

int main()
{
    int i = 24680;
    cout << boolalpha << evenDigitsOnly(i);
    return 0;
}