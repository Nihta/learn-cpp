/**
 * Gọi hai số nguyên và B là friends A nếu mỗi số nguyên từ vector divisors là
 * ước số của cả A và B hoặc không phải ước của A và B. Các số là friends của
 * nhau sẽ được xếp vào 1 clans. Các số còn lại không có friends thì mỗi số tạo 1 clans.
 * Có bao nhiêu clans là các số nguyên từ 1 đến k (bao gồm k).
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/**
 * Mỗi vector v chứa các ước của các số từ 1 -> k.
 * Các số có v giống nhau thì nằm 1 clan.
 * Dùng s để loại bỏ các v trùng lặp
 * size của set sẽ là số clan
 */
int numberOfClans(vector<int> divisors, int k) {
    set<vector<int>> clans;
    for (int i = 1; i <= k; i++) {
        vector<int> v;
        for (int d : divisors)
            if (i%d == 0)
                v.push_back(d);
        clans.insert(v);
    }
    return clans.size();
}

int main() {
    cout << numberOfClans({2, 3}, 6); // 4 : (1, 5) ,(2, 4) ,(3) ,(6)
    return 0;
}