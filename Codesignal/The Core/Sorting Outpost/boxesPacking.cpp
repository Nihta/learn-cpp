/**
 * Tóm tắt: Kiểm tra xem có thể nhét nhiều cái hộp thành 1 hộp duy nhất hay không ?
 * Một hộp có thể được đặt vào một hộp khác nếu tất cả các cạnh của cái thứ nhất
 * nhỏ hơn hộp thứ hai tương ứng.
 * Bạn có thể xoay từng hộp theo ý muốn, tức là bạn có thể trao đổi chiều dài,
 * chiều rộng và chiều cao của nó nếu cần.
*/
#include <iostream>
#include <vector>
using namespace std;

bool boxesPacking(std::vector<int> length, std::vector<int> width, std::vector<int> height)
{
    // Gộp giữ liệu lại thành một vector 2 chiều
    vector<vector<int>> dataBox = {width, length, height};
    // Sắp xếp các phần tử trong mỗi cột
    for (int j = 0; j < dataBox[0].size(); j++)
        for (int i = 0; i < 2; i++)
            for (int z = i + 1; z < 3; z++)
                if (dataBox[i][j] > dataBox[z][j])
                    swap(dataBox[i][j], dataBox[z][j]);

    // Sắp xếp cột dựa vào các phần tử trên hàng đàu tiên
    for (int i = 0; i < dataBox[0].size() - 1; i++)
        for (int j = i + 1; j < dataBox[0].size(); j++)
            if (dataBox[0][i] > dataBox[0][j])
                swap(dataBox[0][i], dataBox[0][j]),
                swap(dataBox[1][i], dataBox[1][j]),
                swap(dataBox[2][i], dataBox[2][j]);

    // Check xem có thể bỏ hộp thứ i-1 và hộp thứ i không ?
    for (int i = 1; i < dataBox[0].size(); i++)
        if (dataBox[0][i - 1] >= dataBox[0][i]
        || dataBox[1][i - 1] >= dataBox[1][i]
        || dataBox[2][i - 1] >= dataBox[2][i])
            return false;

    return true;
}

int main()
{
    cout << std::boolalpha << boxesPacking({5, 7, 4, 1, 2}, {4, 10, 3, 1, 4}, {6, 5, 5, 1, 2}) << endl; // true
    return 0;
}

/**
 *  1 2 3 4 5
 *  1 2 4 5 7
 *  1 4 5 6 10
*/
