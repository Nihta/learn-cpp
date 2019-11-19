//Kiểm tra char có phải số hay không
#include <iostream>
using namespace std;

bool isDigit(char symbol) {
    return isdigit(symbol);
}

int main()
{
    char ch = '5';
    cout << boolalpha << isDigit(ch);
    return 0;
}