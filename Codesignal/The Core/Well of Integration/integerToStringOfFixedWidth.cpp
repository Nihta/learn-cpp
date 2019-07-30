/**
 * Cho một số nguyên dương và một độ dài nhất width định, chúng ta cần sửa đổi
 * số đã cho để có độ dài width. Bạn được phép làm điều đó bằng cách cắt các
 * chữ số đầu đầu (nếu cần rút ngắn) hoặc bằng cách thêm 0 vào trước số ban đầu.
 */
#include <iostream>
#include <vector>
using namespace std;

string integerToStringOfFixedWidth(int number, int width) {
    string s = to_string(number);
    if (s.length() == width)
        return s;
    if (s.length() < width)
        s = string(width - s.length() ,'0') + s;
    else
        s.erase(0, s.length() - width);
    return s;
}

int main() {
    cout << integerToStringOfFixedWidth(1234, 5);
    return 0;
}