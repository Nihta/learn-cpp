/*
    Cho một mảng các số nguyên.
    Xác định xem có thể thu được một mảng tăng nghiêm ngặt hay không
    ( a0 < a1 < a2 < ... ) bằng cách loại bỏ không quá một phần tử ra khỏi mảng
 */
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

bool almostIncreasingSequence(vector<int> sequence) {
    vector<int> sequence2(sequence);
    for (int i = 0; i < sequence.size() - 1; ++i)
    {
        // Tìm vị trí phần tử lỗi
        if (sequence.at(i) >= sequence.at(i+1))
        {
            // Test cách xóa phần tử tại vị trí i
            sequence.erase(sequence.begin() + i);
            int check = 1;
            for (int j = 0; j < sequence.size() - 1; ++j)
            {
                if (sequence.at(j) >= sequence.at(j+1))
                {
                    check = 0;
                    break;
                }
            }
            // check = 1 khi cách xóa này thỏa mãn yêu cầu đề bài
            if (check) return true;

            // Check cách xóa phần tử tại vị trí i+1
            sequence2.erase(sequence2.begin() + i+1);
            for (int j = 0; j < sequence2.size() - 1; ++j)
            {
                if (sequence2.at(j) >= sequence2.at(j+1))
                    return false;
            }
        }
    }
    return true;
}

bool almostIncreasingSequence2(vector<int> sequence)
{
    int n = sequence.size(), p, count = 0;
    for (int i = 1; i < sequence.size(); ++i)
    {
        if (sequence[i-1] >= sequence[i])
        {
            ++count;
            p = i;
            // Có 2 lỗi => Không phải mảng tăng nghiêm ngặt
             if (count > 1) return false;
        }
    }

    // Không có lỗi nào => Mảng tăng nghiêm ngặt
    if (count == 0) return true;

    // Xét trường hợp có 1 lỗi
    // Trường hợp lỗi tại vị trí đầu hoặc cuối: 1 2 3 [1] or 4 [1] 2 3 
    if (p == n-1 || p == 1) return true;
    // Trường hợp xóa sequence.at(p) thu được mảng tăng: 1 3 [2] 4 5
    if (sequence[p-1] < sequence[p+1]) return true;
    // Trường hợp xóa sequece.at(p-1) thu được mảng tăng: 1 3 [2] 4 5
    if (sequence[p-2] < sequence[p]) return true;

    // Trường hợp có 1 lỗi nhưng vẫn sai: 1 2 1 2
    return false;
}

bool almostIncreasingSequence3(vector<int> sequence) {
    // v[n-1]
    int preV = INT_MIN;
    // v[n-2]
    int prePreV = INT_MIN;
    int count = 0;

    for (auto&& n : sequence)
    {
        if (!(n > preV))
        {
            count++;
            if (count > 1) return false;
            // Nếu v[n] > n[n-2] loại bỏ v[n-1] else loại bỏ v[n]
            if (n > prePreV) //  2 4 [3] 5 6         2 4 [1] 5 6
                preV = n;
        }
        else 
        {
            prePreV = preV;
            preV = n;
        }
    }
    return true;
} 
int main() {
    vector<int> v = {1,2,3,1,10,100};
    cout << almostIncreasingSequence(v) << endl;
    cout << almostIncreasingSequence2(v) << endl;
    cout << almostIncreasingSequence3(v) << endl;
    return 0;
}