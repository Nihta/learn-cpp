/**
 * Cho một ma trận số nguyên hình chữ nhật, kiểm tra xem có thể sắp xếp lại các
 * hàng của nó theo cách sao cho tất cả các cột của nó trở thành các dãy tăng
 * nghiêm ngặt (đọc từ trên xuống dưới) hay không?
*/
#include <iostream>
#include <vector>
using namespace std;

bool rowsRearranging(std::vector<std::vector<int>> matrix)
{
    // Sắp xếp lại các hàng của matrix dựa vào phần tử đầu tiên của mỗi hàng
    for (int i = 0; i < matrix.size() - 1; i++)
        for (int j = i + 1; j < matrix.size(); j++)
            if (matrix[i][0] > matrix[j][0])
                swap(matrix[i], matrix[j]);

    // Kiểm tra từng cột
    for (int j = 0; j < matrix[0].size(); j++)
        for (int i = 1; i < matrix.size(); i++)
            if (matrix[i-1][j] >= matrix[i][j])
                return false;

    return true;
}

int main()
{
    cout << std::boolalpha << rowsRearranging({{6, 4}, {2, 2}, {4, 3}}) << endl; // true
    return 0;
}
