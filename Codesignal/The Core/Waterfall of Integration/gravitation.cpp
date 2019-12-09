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
#include <algorithm>
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

/*
 * Ý tưởng: Ở mỗi cột tính số lượng '.' từ vị trí dấu '#' cao nhất đến đáy hộp
 * Các cột có số '.' theo cách tính trên ít nhất là các cột bất động đầu tiên
*/
std::vector<int> gravitation(std::vector<std::string> rows)
{
    std::vector<int> vCount;
    for (int j = 0; j < rows[0].size(); j++)
    {
        bool start = false;
        int count = 0;
        for (int i = 0; i < rows.size(); i++)
        {
            if (rows[i][j] == '#') // Bắt đầu đếm số lượng '.'
                start = true;
            if (start && rows[i][j] == '.')
                count++;
        }
        vCount.push_back(count);
    }

    int minCount = *min_element(vCount.begin(), vCount.end());
    std::vector<int> res;
    for (int i = 0; i < vCount.size(); i++)
        if (vCount[i] == minCount)
            res.push_back(i);

    return res;
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
