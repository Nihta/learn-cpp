/**
 * Cho một string bao gồm các chữ cái tiếng Anh viết thường, tìm số chính
 * phương lớn nhất có thể thu được bằng cách sắp xếp lại các ký tự của string
 * và thay thế chúng bằng bất kỳ chữ số nào bạn muốn (số 0 không được phép đứng
 * đầu) trong đó các ký tự luôn luôn ánh xạ đến cùng một chữ số và các ký tự
 * khác nhau luôn ánh xạ tới các chữ số khác nhau.
 * Nếu không có, trả về -1.
 * 1 ≤ s.length < 10
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// Đếm tần suất xuất hiện các kí tự sau đó sắp xếp tăng dần
vector<int> countChar(string s)
{
    set<char> setCh;
    vector<int> vCh;
    for (auto ch : s)
        setCh.insert(ch);
    for (auto ch : setCh)
        vCh.push_back(count(s.begin(), s.end(), ch));
    sort(vCh.begin(), vCh.end());
    return vCh;
}
int constructSquare(string s) {
    int result = -1;
    vector<int> rule = countChar(s);

    for(int i = 3; ; i++)
    {
        string num = to_string(i*i);
        vector<int> test = countChar(num);

        if (num.length() < s.length())
            continue;
        if (num.length() > s.length())
            break;
        if (test == rule)
            result = i*i;
    }

    return result;
}

int main() {
    cout << constructSquare("aba"); // 900
    return 0;
}