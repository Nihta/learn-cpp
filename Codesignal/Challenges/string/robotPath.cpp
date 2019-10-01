
/**
 * Một robot đứng trên tọa độ 2 chiều tại điểm (0, 0). Nó di chuyển theo một
 * chuỗi các hướng dẫn. Mỗi hướng dẫn được xử lý như sau:
 *     'L' giảm tọa độ đầu tiên xuống một,
 *     'R' tăng tọa độ đầu tiên thêm một,
 *     'U' tăng tọa độ thứ hai thêm một,
 *     'D' giảm tọa độ thứ hai xuống một.
 * Nhưng robot không được phép đi chuyển quá phạm vi một hình vuông được
 * xác định trước ( |x|<= bound && |y| <= bound). Nếu việc thực hiện
 * lệnh hiện tại sẽ dẫn đến robot rời khỏi hình vuông, thì lệnh đó sẽ bị bỏ qua.
 * Cho một chuỗi các hướng dẫn và một hình vuông hạn chế, xuất ra vector gồm hai
 * số nguyên biểu thị vị trí cuối cùng của robot sau khi thực hiện tất cả lệnh.
*/
#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    for (auto &&i : v)
        os << i << ' ';
    return os;
}

vector<int> robotPath(string instructions, int bound)
{
    vector<int> res = {0, 0};
    for (auto &&c : instructions)
    {
        switch (c)
        {
        case 'L':
            if (res[0] > -bound)
                --res[0];
            break;
        case 'R':
            if (res[0] < bound)
                ++res[0];
            break;
        case 'U':
            if (res[1] < bound)
                ++res[1];
            break;
        case 'D':
            if (res[1] > -bound)
                --res[1];
            break;
        }
    }
    return res;
}

int main()
{
    cout << robotPath("LLLLDDDDUR", 2); // {-1, -1}
    return 0;
}
