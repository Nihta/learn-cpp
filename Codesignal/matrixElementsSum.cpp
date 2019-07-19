/*
    Cộng tất cả các giá trị trong ma trận không xuất hiện bên dưới phần tử không
    Ví dụ:
        [ 0 5 0 ]
        [ 1 7 2 ]
        [ 0 8 3 ]
    Các phần tử 1, 2, 3 bị loại do nằm bên dưới phần tử 0
    matrixElementsSum(matrix) = 5 + 7 + 8 = 20
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrixElementsSum(vector<vector<int> > matrix)
{
    // Danh sách các cột có phần tử 0
    vector<int> blackList;
    int sum = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] != 0)
            {
                // Nếu không tìm thấy hàng j trong blackList
                if(find(blackList.begin(),blackList.end(), j)==blackList.end())
                    sum += matrix[i][j];
            }
            else
            {
                // Thêm hàng j vào danh sách đen(thời điểm mattrix[i][j] == 0)
                blackList.push_back(j);
            }
            
        }
        
    }
    return sum;
}

// Tính tổng lần lượt các phần tử trong mỗi cột cho đến khi gặp số 0
// Sau đó cộng các tổng của các cột lại
// Xoay ngược ma trận sẽ dẽ nhìn hơn :v
int matrixElementsSum2(vector<vector<int> > matrix)
{
    int sum = 0;
    for (int j = 0; j < matrix[0].size(); j++)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][j] == 0) break;
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int> > v2D = {{0, 5, 0}, {1, 7, 2}, {0, 8, 3}};
    cout << matrixElementsSum(v2D) << endl;
    cout << matrixElementsSum2(v2D) << endl;

    return 0;
}
