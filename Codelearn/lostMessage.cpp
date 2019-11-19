/**
 * FBI có 1 hệ thống truyền tin mật. Mỗi tin truyền đi sẽ có 1 mã riêng.
 * Mỗi lần tin truyền đi và nhận được sẽ có 1 phản hồi về cho trung tâm
 * để báo là tin đã được gửi và nhận an toàn.
 * Tin gửi đi sẽ có nội dung là: S:{ID}.
 * Tin nhận được sẽ có nội dung phản hồi là: R:{giá trị đảo ngược của ID}
 * Ví dụ với mã tin nhắn là "ABCD" ta sẽ có tin nhắn phản hồi như sau:
 * Tin nhắn gửi đi sẽ là S:ABCD và tin nhắn phản hồi sẽ là R:DCBA
 * Một ngày, FBI phát hiện có 1 tin đã gửi đi nhưng lại chưa nhận được phản hồi.
 * Cho trước danh sách các tin gửi đi và nhận về ( không theo thứ tự ) ấy,
 * hãy giúp FBI tìm ra mã của tin nhắn bị thất lạc đó.
 * Đảm bảo dữ liệu đúng đắn: mỗi ID chỉ được sử dụng tối đa 1 lần, luôn có
 * duy nhất 1 tin nhắn gửi đi nhưng không nhận được tin nhắn trả về.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string lostMessage(vector<string> v) {
    string res;
    vector<string> S, R;

    // Phân loại tin nhắn gửi và nhận
    for (auto &&s : v)
        if (s[0] == 'S')
            S.push_back(s);
        else
            R.push_back(s);

    // Check mỗi tin nhắn gửi đi xem nó có tin nhắn trả về tương ứng không
    for (auto &&s : S)
    {
        // Lấy ID
        string tmp = s.substr(2, s.size() - 2);
        // Đảo ngược ID
        reverse(tmp.begin(), tmp.end());
        // Chỉnh cho giống dạng tin nhắn phản hồi
        tmp = "R:" + tmp;
        if (find(R.begin(), R.end(), tmp) == R.end()) {
            return s.substr(2, s.size() - 2);
        };
    }
    return "delete warning :)";
}

int main() {
    vector<string> v = {"S:AAA", "S:123", "R:AAA", "S:ABCD", "R:321"};
    cout << lostMessage(v); // ABCD
    return  0;
}
