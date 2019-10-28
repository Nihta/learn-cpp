/**
 * Một bãi đậu xe mới vừa được mở trong thành phố của bạn. Giá của nó là:
 *     30 phút đầu tiên (bao gồm) miễn phí
 *     Từ 31 phút đến 2 giờ, cứ sau 10 phút có giá 1$
 *     Cứ sau 10 phút hơn 2 giờ có giá 2$
 * Vì bạn bị tính phí cứ sau 10 phút, bạn nên làm tròn số phút dành cho bãi
 * đỗ xe lên tới bội số gần nhất của 10. Ví dụ: nếu bạn đậu xe trong 43 phút
 * thì bạn sẽ phải trả cho 50 phút.
 * Bạn được cung cấp 2 string: thời điểm bạn đến bãi đậu xe và thời điểm mà bạn
 * rời khỏi đó. Bạn muốn biết bạn sẽ phải trả bao nhiêu tiền cho bãi đậu xe mới.
 * Đảm bảo rằng tất cả các sự kiện diễn ra trong một ngày.
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int parkingCost(string t1, string t2)
{
    // Tìm tổng số phút mà người đó đỗ xe
    stringstream timeIn, timeOut;
    timeIn << t1;
    timeOut << t2;
    int h1, m1, h2, m2;
    char tmp;
    timeIn >> h1 >> tmp >> m1;
    timeOut >> h2 >> tmp >> m2;
    int sumMinute = (h2 - h1) * 60 + m2 - m1;

    // Tính tiền
    if (sumMinute <= 30)
        return 0;
    int cost = 0;
    // Trừ 3$ free
    if (sumMinute <= 120)
        cost = sumMinute / 10 + (sumMinute % 10 != 0) - 3;
    else
    {
        cost = 12 - 3;
        sumMinute -= 120;
        cost += 2 * (sumMinute / 10 + (sumMinute % 10 != 0));
    }

    return cost;
}

int main()
{
    cout << parkingCost("14:11", "14:39") << endl; // 0
    cout << parkingCost("07:02", "07:42") << endl; // 1
    cout << parkingCost("21:57", "23:58") << endl; // 11
    return 0;
}
