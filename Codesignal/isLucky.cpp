/*
    Cho 1 số nguyên có số lượng các chữ số chẵn
    Check tổng các chữ số nửa đầu có bằng tổng các chữ số nửa sau hay không?
    Ví dụ:
        123213 : true   1+2+3 == 2+1+3
        123456 : false  1+2+3 != 4+5+6
*/
#include <iostream>
#include <vector>
using namespace std;

bool isLucky(int n)
{
    // Tách n thành các chữ số cho vào vector
    vector<int> v;
    while (n != 0)
    {
        v.push_back(n%10);
        n /= 10;
    }

    // Tính tổng nửa đầu và nửa sau
    int sum1 = 0, sum2 = 0;
    int size = v.size();
    for (int i = 0; i < size/2; i++)
        sum1 += v[i];
    for (int i = size/2; i < size; i++)
        sum2 += v[i];

    return sum1 == sum2;
}

bool isLucky2(int n)
{
    // s = "123213"
    // 1+2+3 == 2+1+3 <=> (1+2+3) - (2+1+3) == 0 <=> (1-3)+(2-1)+(3-2) == 0
    string s = to_string(n);
    int sum = 0;
    for(int i = 0; i < s.length()/2; i++)
        sum += ( s.at(i) - s.at(s.length() - i - 1) );
    return sum == 0;
}

int main()
{
    int n = 123213;
    cout << isLucky(n) << endl;
    cout << isLucky2(n) << endl;
    return 0;
}