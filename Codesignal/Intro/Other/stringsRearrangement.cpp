/*
Cho một một vector bao gồm các string(các chữ thường) có độ dài bằng nhau:
    2 ≤ inputArray.length ≤ 10
    1 ≤ inputArray[i].length ≤ 15
Bạn muốn biết liệu có thể sắp xếp lại thứ tự các phần tử theo cách sao cho mỗi cặp string liên tiếp khác nhau theo chính xác một ký tự. Ví dụ (abc, abd).
Trả về true nếu có thể và false nếu không.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool stringsRearrangement(vector<string> v)
{
    // Cần sử dụng sort và do while để có thể lấy tất cả các hoán vị
    sort(v.begin(), v.end());

    do // Kiểm tra xem hoán vị hiện tại có thỏa mãn yêu cầu hay không
    {
        // Kiểm tra lần lượt 2 string gần nhau
        int check = 1;
        for (int i = 1; i < v.size(); ++i)
        {
            // Check 2 string gần nhau xem chúng có khác nhau đúng 1 kí tự hay không
            int count = 0;
            for (int j = 0; j < v[i].size(); ++j)
                if(v[i-1][j] != v[i][j])
                    ++count;

            if(count != 1)
            {
                check = 0;
                break;
            }
        }

        if (check)
            return 1;

    } while(next_permutation(v.begin(), v.end()));

    return false;
}

int main()
{
    vector<string> v = {"abc", 
 "abx", 
 "axx", 
 "abc"};

    cout << boolalpha << stringsRearrangement(v);

    return 0;
}