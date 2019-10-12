/**
 * Một số người chạy dọc theo một đường thẳng theo cùng một hướng. Họ bắt đầu
 * chạy đồng thời ở các vị trí khác nhau và chạy với tốc độ không đổi (khác nhau).
 * Nếu hai hoặc nhiều người gặp nhau ở cùng một điểm, điểm đó gọi là một meeting.
 * Số lượng người tập trung tại cùng một điểm được gọi là meeting cardinality.
 * Hãy tìm số lượng meeting cardinality tối đa giả định rằng mọi người chạy vô
 * tận. Nếu không có meeting, hãy return -1.
 * Xem runnersMeetings.gif
 * Note: Không tính điểm gặp nhau <= 0
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int runnersMeetings(vector<int> startPosition, vector<int> speed)
{
    int res = -1;
    for (int i = 0; i < startPosition.size() - 1; i++)
    {
        map<int, int> meetingCardinality; // <vị trí, số lượng>
        for (int j = i + 1; j < startPosition.size(); j++)
        {
            // point là vị trí mà người i và j gặp nhau (nếu có thể)
            // S = t*v1 + x1 = t*v2 + x2 <=> t = (x2-x1)/(v1-v2)
            double time = (double)(startPosition[j] - startPosition[i])/(speed[i] - speed[j]);
            if (time <= 0)
                continue;
            int point = time * speed[i] + startPosition[i];
            if (point > 0)
            {
                if (meetingCardinality.count(point) == 0)
                    meetingCardinality[point] = 2;
                else
                    meetingCardinality[point]++;

                if (meetingCardinality[point] > res)
                    res = meetingCardinality[point];
            }
        }
    }
    return res;
}

int main()
{
    cout << runnersMeetings({1, 4, 2}, {27, 18, 24}) << endl; // 3
    cout << runnersMeetings({1, 1000}, {23, 22}) << endl;     // 2
    cout << runnersMeetings({1, 2, 3}, {1, 1, 1});            // -1
    return 0;
}
