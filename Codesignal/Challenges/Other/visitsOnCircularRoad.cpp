/**
 * Có n ngôi nhà trong một ngôi làng trên con đường hình tròn được đánh số
 * từ 1 đến n bắt đầu từ một số ngôi nhà theo thứ tự chiều kim đồng hồ.
 * Phải mất một phút để đi từ một ngôi nhà đến bất kỳ hai ngôi nhà liền kề
 * và không có con đường nào khác trong ngôi làng này ngoài con đường hình tròn.
 * Tìm thời gian tối thiểu cần thiết để thực hiện tất cả các lượt di chuyển
 * theo thứ tự mong muốn bắt đầu từ nhà 1.
 * Xem: visitsOnCircularRoad.png
*/
#include <iostream>
#include <vector>
using namespace std;

int visitsOnCircularRoad(int n, std::vector<int> visitsOrder)
{
    int current = 1;
    int res = 0;
    for (int i = 0; i < visitsOrder.size(); i++)
    {
        // Chọn đường đi ngắn nhất trong 2 các là đi ngược và đi xuôi chiều kim đồng hồ
        res += min(abs(visitsOrder[i] - current),
                   n - abs(visitsOrder[i] - current));
        current = visitsOrder[i];
    }
    return res;
}

int main()
{
    cout << visitsOnCircularRoad(4, {1, 3, 2, 3, 1}) << endl; // 6
    return 0;
}
