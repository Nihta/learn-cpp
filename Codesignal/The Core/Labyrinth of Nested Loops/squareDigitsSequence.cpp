/**
 * Xét một dãy các số a0, a1, ..., an, trong đó mỗi phần tử phía sau bằng
 * tổng bình phương các chữ số của phần tử trước.
 * Dãy kết thúc khi một phần tử đã có trong dãy xuất hiện lại lần nữa.
 * Cho phần tử đầu tiên a0, tìm độ dài của chuỗi (tính cả a0 và phần tử trùng)
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int squareDigitsSequence(int a0) {
    vector<int> v(1, a0);
    for (int count = 1; true; count++)
    {
        int aNext = 0;
        for(int tmp = v.back(); tmp != 0; tmp/=10)
            aNext += (tmp%10) * (tmp%10);

        if(find(v.begin(), v.end(), aNext) != v.end())
            return count + 1;

        v.push_back(aNext);
    }
}


int main() {
    int a0 = 16;
    cout << squareDigitsSequence(a0); // 9
    return 0;
}