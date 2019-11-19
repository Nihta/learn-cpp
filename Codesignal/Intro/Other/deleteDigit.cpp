/*
Cho một số nguyên, tìm số tối đa bạn có thể nhận được bằng cách xóa chính xác một chữ số của số đã cho
 */
#include <iostream>
using namespace std;

int deleteDigit(int n)
{
    int result = -1;
    string s = to_string(n);
    for(int i = 0; i < s.length(); ++i)
    {
        string tmp = s;
        tmp.erase(i, 1);
        if (result < stoi(tmp))
            result = stoi(tmp);
    }
    return result;
}

int main()
{
    cout << deleteDigit(5231);
    return 0;
}