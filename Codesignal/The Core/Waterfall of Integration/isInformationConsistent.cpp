/**
 * Mỗi nhân chứng tương ứng với mỗi hàng của một vector
 * Và mỗi cột tương ứng là mỗi câu hỏi với câu trả lời:
 *     - Có tội: 1
 *     - Vô tội: -1
 *     - Không có ý kiếm: 0
 * Kiểm tra xem các nhân chứng có đang nói thật hay không biết rằng: không thể
 * tồn tại nhân chứng A và B và một bị cáo C mà A nói C có tội trong khi B
 * nói C vô tội
*/
#include <iostream>
#include <vector>
using namespace std;

bool isInformationConsistent(std::vector<std::vector<int>> evidences)
{
    for (int j = 0; j < evidences[0].size(); j++)
    {
        int answer = 0;
        for (int i = 0; i < evidences.size(); i++)
        {
            if (answer == 0 && evidences[i][j] != 0)
                answer = evidences[i][j];
            if (evidences[i][j] != 0 && answer != evidences[i][j])
                return false;
        }
    }
    return true;
}

int main()
{
    cout << std::boolalpha << isInformationConsistent({{0, 0, -1},
                                                       {-1, 1, -1},
                                                       {-1, 1, 0},
                                                       {0, 1, 0}}) << endl; // true
    cout << isInformationConsistent({{1, 0},
                                     {-1, 0},
                                     {1, 1},
                                     {1, 1}})
         << endl; // false
    return 0;
}
