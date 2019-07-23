// Cho 1 địa chỉ email. Tìm phần tên miền của email?
#include <iostream>
using namespace std;

string findEmailDomain(string s)
{
    // Tìm vị trí của chữ '@' sau cùng
    int pos = s.rfind('@');
    // int pos = s.find_last_of('@');

    // Xóa từ đầu đến chữ '@' sau cùng đó sẽ thu được teemn miền
    s.erase(s.begin(), s.begin() + pos + 1);
    return s;
}

string findEmailDomain2(string s) {
    return s.substr(s.find_last_of('@')+1);
}

int main()
{
    cout << findEmailDomain("hahaha@github.com");
    return 0;
}