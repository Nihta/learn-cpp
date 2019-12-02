/**
 * Caesar Box là một mật mã chuyển vị đơn giản được sử dụng trong Đế chế La Mã,
 * trong đó các ký tự của thông điệp đã cho được chia thành nhiều dòng tạo thành
 * một hình vuông khi xếp chồng lên nhau và sau đó ghép lại theo cột.
 * Cho một thông điệp, mã hóa nó.
 *
 * Đảm bảo string có độ dài là n^2
 *
 *                 a m
 *    a message => ess => aea sgmse
 *                 age
*/
#include <iostream>
#include <cmath>
using namespace std;

string caesarBoxCipherEncoding(string s)
{
    int n = sqrt(s.size());
    string res;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res.push_back(s[i + j * n]);
    return res;
}

int main()
{
    cout << caesarBoxCipherEncoding("a message") << endl;        // aea sgmse
    cout << caesarBoxCipherEncoding("sixteenletters16") << endl; // seerietsxnt1tle6
    return 0;
}
