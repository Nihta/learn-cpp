/*
    Cho một ma trận hình chữ nhật gồm các ký tự
    Thêm một đường viền gồm các dấu (*) bao quanh nó
    Input:  {"abc",
             "123"}

    Output: {"*****",
             "*abc*",
             "*123*",
             "*****"}
 */
#include <iostream>
#include <vector>
using namespace std;

vector<string> addBorder(vector<string> v)
{
    // Thêm đấu '*' vào đầu và cuối mỗi string
    for(auto &s: v)
        s = "*" + s + "*";

    // Chèn vào đầu và cuối vector "*********"
    v.insert(v.begin(), string(v[0].size(),'*'));
    v.insert(v.end(), string(v[0].size(),'*'));
    return v;
}

int main()
{
    for (auto &&i : addBorder({"abc", "123"}))
    {
        cout << i << endl;
    }
    return 0;
}