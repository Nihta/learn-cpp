/**
 * N cây nến được đặt trong một hàng, một số trong số đó ban đầu được thắp sáng. Chọn mỗi cây nến từ thứ 1 đến thứ N, áp dụng thuật toán sau: nếu quan sát được một cây nến thắp sáng thì trạng thái của nến này và tất cả các nến trước nó được đổi thành ngược lại. Cây nến nào sẽ vẫn sáng sau khi áp dụng thuật toán cho tất cả các nến theo thứ tự chúng được đặt trong hàng?
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> switchLights(vector<int> v) {
    int  changed = 0;
    for (int i = v.size()-1; i >= 0; i--)
    {
        if (v[i] == 1) // Nếu nến cháy
            changed++;
        if (changed%2 == 1) // Nếu số lần thay đổi trạng thái là lẻ
            v[i] = !v[i];
    }
    return v;
}

int main() {
    vector<int> v = {1, 1, 1, 1, 1};
    for (int i : switchLights(v))
        cout << i << " ";
    return 0;
}