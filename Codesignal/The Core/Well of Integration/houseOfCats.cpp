/**
 * Có một số người và mèo ở trong một ngôi nhà. Bạn được cung cấp số lượng chân.
 * Nhiệm vụ của bạn là trả về một mảng chứa mọi khả năng số mèo có thể có
 * trong nhà được sắp xếp theo thứ tự tăng dần.
 * Đảm bảo rằng mỗi người có 2 chân và mỗi con mèo có 4 chân.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> houseOfCats(int legs) {
    vector<int> result;
    for (int i = 0; 2*i <= legs; i++)
        if ((legs - 2*i)%4 == 0)
            result.push_back(i);
    return result;
}

int main() {
    for (int i : houseOfCats(44))
        cout << i << " ";
    return 0;
}