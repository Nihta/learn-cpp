/**
 * Mark có một ma trận mảng hình chữ nhật cho ngày sinh nhật của anh ấy,
 * và bây giờ anh ấy đang nghĩ về tất những điều thú vị anh ấy có thể làm với nó.
 * Anh ấy thích dịch chuyển, vì vậy anh ấy quyết định chuyển tất cả các đường viền
 * i của nó theo chiều kim đồng hồ nếu i chẵn và ngược chiều kim đồng hồ nếu i
 * là số lẻ. Đây là cách Mark định nghĩa i-contours:
 *     0-contours của một mảng hình chữ nhật là sự kết hợp của các cột bên trái
 * và bên phải cũng như các hàng trên cùng và dưới cùng;
 *     Xem xét ma trận ban đầu không có 0-contours: 0-contours của nó là đường
 * viền 1 của ma trận ban đầu;
 *     Định nghĩa 2-contour, 3-contour, v.v ... theo cách tương tự bằng cách
 * loại bỏ các 0-contours khỏi các mảng thu được.
*/
#include <iostream>
#include <vector>
using namespace std;

void solution(vector<vector<int>> &matrix, int left, int right, int top, int bottom, int count)
{
    // Phần neo
    if (left > right || top > bottom) // Hết
        return;
    if (left == right && top == bottom) // Còn một ô duy nhất
        return;

    // Phần đệ quy
    if (count % 2 == 0) // Nếu chẵn quay theo chiều kim đồng hồ
    {
        if (top == bottom) // Nếu còn duy nhất một hàng
        {
            // end là giá trị ô nằm ở cuối chiều dịch chuyển (chiều kim đông hồ)
            int end = matrix[top][right];
            for (int i = left; i <= right; i++)
                swap(end, matrix[top][i]);
        }
        else if (left == right) // Nếu còn duy nhất một cột
        {
            int end = matrix[bottom][left];
            for (int i = top; i <= bottom; i++)
                swap(end, matrix[i][left]);
        }
        else
        {
            int end = matrix[top + 1][left];
            // Hàng trên
            for (int i = left; i <= right; i++)
                swap(end, matrix[top][i]);
            // Cột phải
            for (int i = top + 1; i <= bottom; i++)
                swap(end, matrix[i][right]);
            // Hàng dưới
            for (int i = right - 1; i >= left; i--)
                swap(end, matrix[bottom][i]);
            // Cột trái
            for (int i = bottom - 1; i >= top + 1; i--)
                swap(end, matrix[i][left]);
        }
    }
    else // Nếu lẻ quay theo chiều kim đồng hồ
    {
        if (top == bottom)
        {
            int end = matrix[top][left];
            for (int i = right; i >= left; i--)
                swap(end, matrix[top][i]);
        }
        else if (left == right)
        {
            int end = matrix[top][left];
            for (int i = bottom; i >= top; i--)
                swap(end, matrix[i][left]);
        }
        else
        {
            int end = matrix[top][left];
            for (int m = top + 1; m <= bottom; m++)
                swap(end, matrix[m][left]);
            for (int m = left + 1; m <= right; m++)
                swap(end, matrix[bottom][m]);
            for (int m = bottom - 1; m >= top; m--)
                swap(end, matrix[m][right]);
            for (int m = right - 1; m >= left; m--)
                swap(end, matrix[top][m]);
        }
    }

    solution(matrix, left + 1, right - 1, top + 1, bottom - 1, count + 1);
}

std::vector<std::vector<int>> contoursShifting(std::vector<std::vector<int>> matrix)
{
    int h = matrix.size();
    int w = matrix[0].size();
    solution(matrix, 0, w - 1, 0, h - 1, 0);
    return matrix;
}

int main()
{
    vector<vector<int>> res = contoursShifting({{1, 2, 3, 4},
                                                {5, 6, 7, 8},
                                                {9, 10, 11, 12},
                                                {13, 14, 15, 16},
                                                {17, 18, 19, 20}});
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << endl;
    }
    return 0;
}
