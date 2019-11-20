/**
 * Bạn được cung cấp một loạt các tên tệp mong muốn theo thứ tự tạo của chúng:
 * 5 ≤ names.size ≤ 1000, 1 ≤ names[i].length ≤ 15
 * Vì hai tệp không thể có tên bằng nhau, nên tệp đến sau sẽ có dạng name(k),
 * trong đó k là số nguyên dương nhỏ nhất sao cho tên tệp thu được chưa được sử dụng.
 * Trả về một mảng các tên sẽ được đặt cho các tệp.
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

ostream &operator<<(ostream &os, vector<string> v)
{
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << endl;
    return os;
}

vector<string> fileNaming(vector<string> names)
{
    vector<string> res;
    // Danh sách các files name đã được sử dụng
    set<string> nameUsed;
    for (string fileName : names)
    {
        int k = 1;
        string name = fileName;
        // Nếu như tên file hiện tại (name) đã được sử dụng trước đó (trong nameUsed)
        // thì lặp cho đến khi tạo được tên mới không trùng
        while (nameUsed.find(name) != nameUsed.end())
            name = fileName + '(' + to_string(k++) + ')';
        nameUsed.insert(name);
        res.push_back(name);
    }

    return res;
}

int main()
{
    vector<string> names = {"a(1)", "a(6)", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"};
    cout << fileNaming(names) << endl;
    return 0;
}
