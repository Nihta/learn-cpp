/*
    Tính trung bình cộng [3x3]
    [1, 2, 3]
    [4, 5, 6] = 45/9 = 5
    [7, 8, 9]
 */
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int> > boxBlur(vector<vector<int> > input)
{
    // Khởi tạo vector 2 chiều lưu kết quả 
    vector<vector<int> > result(input.size() - 2, vector<int>(input[0].size() - 2));

    for(int i = 0; i < result.size(); ++i)
        for(int j = 0; j < result[0].size(); ++j)
        {
            for(int x = 0; x < 3; ++x)
                for(int y = 0; y < 3; ++y)
                    result[i][j] += input[i + x][j + y];
            result[i][j] /= 9;
        }
        
    return result;
}

int main()
{
    vector<vector<vector<int> > > testCase = {
        {{1, 1, 1}, // 1
         {1, 7, 1},
         {1, 1, 1}},

        {{7, 4, 0, 1},  // [5, 4]
         {5, 6, 2, 2},  // [4, 4]
         {6, 10, 7, 8}, 
         {1, 4, 2, 0}}
    };

    vector<vector<int> > temp;
    for (auto &&i : testCase)
    {
        temp = boxBlur(i);
        for (auto &&x : temp)
        {
            for (auto &&y : x)
                cout << y << " ";
            cout << endl;
            
        }
        cout << endl;
    }
    



    return 0;
}