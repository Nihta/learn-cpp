/**
 * Hôm qua bạn tìm thấy một số đôi giày ở phía sau tủ quần áo của bạn.
 * Mỗi chiếc giày được mô tả bởi hai giá trị: type cho biết đó là chiếc giày
 * bên trái hay bên phải; size là kích thước của giày.
 * Nhiệm vụ của bạn là kiểm tra xem có thể ghép tất cả đôi giày bạn tìm thấy
 * theo cách sao cho mỗi đôi bao gồm một chiếc bên phải và một chiếc bên trái
 * có kích thước bằng nhau.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool pairOfShoes(vector<vector<int>> shoes) {
    vector<int> left, right;
    for (auto v : shoes)
        (v[0]) ? right.push_back(v[1]) : left.push_back(v[1]);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    return left == right;
}

int main() {
    vector<vector<int>> v = {{0, 21},
                             {1, 23},
                             {1, 21},
                             {0, 23}};
    cout << boolalpha << pairOfShoes(v);
    return 0;
}