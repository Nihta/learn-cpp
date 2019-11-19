/*
    Số lượng phần tử tối thiểu cần bổ sung để được dãy tăng liên tục mà số sau lớn hơn số trước 1
    Ví dụ: [7,2,4] cần bổ sung tối thiểu 3 số là: 3, 5, 6
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int makeArrayConsecutive2(std::vector<int> statues) {
    int result = 0;
    sort(statues.begin(), statues.end());
    for(int i = 0; i < statues.size() - 1; i++)
        result += (statues[i+1] - statues[i] - 1);
    return result;
}
int main() {
    vector<int> intVec = {7, 2, 4};
    cout << "Result: " << makeArrayConsecutive2(intVec) << endl;
    return 0;
}