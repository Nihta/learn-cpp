// Cho một địa chỉ email hợp lệ, tìm phần tên miền của nó
#include <iostream>
using namespace std;

string findEmailDomain(string s) {
    return s.substr(s.find_last_of('@') + 1);
}

int main() {
    cout << findEmailDomain("nihta-nihta@gmail.com");
    return 0;
}