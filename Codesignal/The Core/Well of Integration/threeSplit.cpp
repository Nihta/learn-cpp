/**
 * Bạn có một dải giấy dài với các số nguyên được viết trên đó trong một dòng
 * duy nhất từ ​​trái sang phải. Bạn muốn cắt giấy thành chính xác ba mảnh sao
 * cho mỗi mảnh chứa ít nhất một số nguyên và tổng các số nguyên trong mỗi mảnh
 * là như nhau. Bạn không thể cắt qua một số, tức là mỗi số ban đầu sẽ rõ ràng
 * thuộc về một trong các phần sau khi cắt. Có bao nhiêu cách bạn có thể làm
 * điều đó?
 * Đảm bảo rằng tổng của tất cả các phần tử trong mảng chia hết cho 3.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSplit(vector<int> v) {
    // Tính tổng mỗi mảnh
    long long sum = 0;
    for (int i : v)
        sum += i;
    sum /= 3;

    // 2 mảnh = sum <=> 3 mảnh = sum
    int result = 0;
    long long s1 = 0;
    for (int i = 0; i < v.size()-2; i++) {
        s1 += v[i];
        if (s1 == sum) {
            long long s2 = 0;
            for (int j = i+1 ; j < v.size()-1; j++) {
                s2 += v[j];
                if (s2 == sum)
                    result++;
            }
        }
    }

    return result;
}

int main() {
    vector<int> v = {0, -1, 0, -1, 0, -1}; // 4
    cout << threeSplit(v);
    return 0;
}