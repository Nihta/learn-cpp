/**
 * Cuộc bầu cử đang được tiến hành! Cho đến nay, đã có một số phiếu bầu cho mỗi
 * ứng cử viên và số nguyên k bằng với số cử tri chưa bỏ phiếu, hãy tìm số ứng
 * cử viên vẫn có cơ hội giành chiến thắng trong cuộc bầu cử . Người chiến
 * thắng trong cuộc bầu cử phải đảm bảo nhiều phiếu hơn bất kỳ ứng cử viên nào
 * khác. Nếu hai hoặc nhiều ứng cử viên nhận được số phiếu (tối đa) như nhau,
 * giả sử không có người chiến thắng nào cả.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int electionsWinners(vector<int> v, int k)
{
    // Số phiếu cao nhất mà một người được bầu
    int max = *max_element(v.begin(), v.end());
    // Số lượng người đặt số phiếu max
    int countMax = count(v.begin(), v.end(), max);

   if(k == 0) // Nếu như tất cả mọi người đã bỏ phiếu
        return countMax == 1 ? 1 : 0;
    else
    {
        int count = 0;
        for (int i : v)
            if (i == max || i + k > max)
                ++count;
        return count;
    }
}

int main() {
    vector<int> v = {2, 3, 5, 2};
    int k = 3;
    cout << electionsWinners(v, k);
    return 0;
}