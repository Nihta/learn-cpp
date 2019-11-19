/*
Bạn được cung cấp một loạt các tên tệp mong muốn theo thứ tự tạo của chúng.
    5 ≤ names.size ≤ 1000, 1 ≤ names[i].length ≤ 15
Vì hai tệp không thể có tên bằng nhau, nên tệp đến sau sẽ có dạng name(k), trong đó k là số nguyên dương nhỏ nhất sao cho tên tệp thu được chưa được sử dụng.
Trả về một mảng các tên sẽ được đặt cho các tệp.
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<string> fileNaming(vector<string> names)
{
    vector<string> result;
    // Danh sách các files name đã được sử dụng
    set<string> seT;
    
    for(string s: names)
    {
        int count = 1;
        string newName = s;

        // Nếu như tên files hiện tại đã được sử dụng trước đó
        // Lặp cho đến khi tạo được tên mới không trùng
        while(seT.find(newName) != seT.end())
            newName = s + '(' + to_string(count++) + ')';

        seT.insert(newName);
        result.push_back(newName);
    }

    return result;
}


int main()
{
    vector<string> s = {"a(1)", 
 "a(6)", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a", 
 "a"};
    for (auto ss : fileNaming(s))
        cout << ss << " ";
    return 0;
}