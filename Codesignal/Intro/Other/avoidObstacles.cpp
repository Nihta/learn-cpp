/*
Bạn được cung cấp một loạt các số nguyên biểu thị tọa độ của các chướng ngại vậtnằm trên một đường thẳng.
Giả sử rằng bạn đang nhảy từ điểm có tọa độ 0 sang phải.
Bạn chỉ được phép thực hiện các bước nhảy có cùng độ dài được biểu thị bằng một số nguyên.
Tìm độ dài tối thiểu của bước nhảy đủ để tránh tất cả các chướng ngại vật.
*/
#include <iostream>
#include <vector>
using namespace std;

// Độ dài tối thiểu là số mà tất cả các số trong vector đều không chia hết cho nó
int avoidObstacles(vector<int> v)
{
    for(int result = 2; true; ++result)
    {
        int check = 1;
        for(int i : v)
            check = check && i%result;
        if(check)
            return result;
    }
}

int main() {
    vector<vector<int> > testCase = {
        {5, 3, 6, 7, 9},   // 4
        {2, 3},            // 4
        {5, 8, 9, 13, 14}, // 6
        {1, 4, 10, 6, 2}   // 7
    };

    for (auto &&v : testCase)
        cout << avoidObstacles(v) << endl;
    
    return 0;
}