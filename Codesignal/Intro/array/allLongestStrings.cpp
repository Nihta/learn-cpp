/*
    Cho một mảng bao gồm các chuỗi,
    trả về một mảng khác chứa tất cả các chuỗi dài nhất của nó.
    Ví dụ:
        inputArray = {"aba", "aa", "ad", "vcd", "aba"}
        allLongestStrings(inputArray) =  {"aba", "vcd", "aba"}
*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> allLongestStrings(vector<string> inputArray)
{
    // Tìm độ dài xâu lớn nhất
    int maxLen = 0;
    for (auto &&s : inputArray)
        if (s.length() > maxLen) maxLen = s.length();
    
    // Thêm các string có độ dài lớn nhất vào vector result
    vector<string> result;
    for (auto &&i : inputArray)
        if(i.length() == maxLen) result.push_back(i);

    return result;
}

int main()
{
    vector<string> v = {"aba", "aa", "ad", "vcd", "aba"}, vResult;
    vResult = allLongestStrings(v);
    for (auto &&i : vResult)
    {
        cout << i << endl;
    }
    return 0;
}