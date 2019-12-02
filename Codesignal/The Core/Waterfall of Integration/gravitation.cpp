/**
 * Bạn được cung cấp một hộp dọc chia thành các cột bằng nhau.
 * Ai đó đã đánh rơi vài viên đá từ đỉnh của cái hộp từ các cột.
 * Đá rơi thẳng xuống với tốc độ không đổi (bằng với tất cả các viên đá)
 * trong khi có thể (tức là trong khi chúng chưa chạm đất hoặc chúng không bị
 * chặn bởi một viên đá bất động khác).
 * Cho trạng thái của các viên đá trong hộp tại một thời điểm nào đó,
 * tìm ra cột nào trở nên bất động trước tiên.
 * Xem: gravitation.png
*/
#include <iostream>
#include <vector>
using namespace std;

// Output Operator Overloading
template <typename T>
ostream &operator<<(ostream &os, vector<T> vt)
{
    os << "(" << vt.size() << ") { ";
    for (auto it = vt.begin(); it != vt.end(); it++)
        os << *it << (it + 1 != vt.end() ? ", " : "");
    os << " }";
    return os;
}

std::vector<int> gravitation(std::vector<std::string> rows)
{

    return {1, 2};
}

int main()
{
    cout << gravitation({"#..##",
                         ".##.#",
                         ".#.##",
                         "....."})
         << endl; // 1, 4
    cout << gravitation({"#..##",
                         ".##.#",
                         ".#.##",
                         "..##."})
         << endl; // 1, 2, 3, 4
    return 0;
}
