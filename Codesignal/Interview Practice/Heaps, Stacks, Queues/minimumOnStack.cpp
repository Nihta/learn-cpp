/**
 * Triển khai một stack được sửa đổi, ngoài việc sử dụng các thao tác push và
 *  pop, cho phép bạn tìm phần tử tối thiểu hiện tại trong ngăn xếp bằng cách sử dụng thao tác min.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}

std::vector<int> minimumOnStack(std::vector<std::string> operations)
{
    vector<int> stack;
    vector<int> res;
    for (string cmd : operations)
    {
        if (cmd.substr(0, 3) == "pus")
        {
            stringstream ss;
            ss << cmd;
            string str;
            int num;
            ss >> str >> num;
            stack.push_back(num);
        }
        else if (cmd.substr(0, 3) == "pop")
            stack.pop_back();
        else
            res.push_back(*min_element(stack.begin(), stack.end()));
    }
    return res;
}
int main()
{
    cout << minimumOnStack({"push 10",
                            "min",
                            "push 5",
                            "min",
                            "push 8",
                            "min",
                            "pop",
                            "min",
                            "pop",
                            "min"});  // { 10, 5, 5, 5, 10}
    return 0;
}
