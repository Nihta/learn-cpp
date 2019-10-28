/**
 * Địa chỉ của một trang web thường có dạng sau: <Protocol>://<domain>.com[/<context>]
 * trong đó <Protocol>, <domain> và <context> và là các string không trống
 * bao gồm các chữ cái tiếng Anh viết thường.
 * Lưu ý rằng có thể không có phần <context> trong một địa chỉ.
 * Tìm <Protocol>, <domain> và <context> (nếu có).
*/

#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<string> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}

vector<string> splitAddress(string address)
{
    vector<string> res;
    int protocolSize = address.find(':');
    res.push_back(address.substr(0, protocolSize));
    int domianFullSize;
    for (int i = 0; i < address.size() - protocolSize -3; i++)
        if (address[i+protocolSize+3] == '/')
        {
            domianFullSize = i;
            break;
        }
    res.push_back(address.substr(protocolSize + 3, domianFullSize-4));
    int tmp = protocolSize + 3 + domianFullSize;
    if (tmp != address.size())
        res.push_back(address.substr(tmp + 1, address.size() - tmp));
    return res;
}

int main()
{
    cout << splitAddress("https://codesignal.com/nihta");
    return 0;
}
