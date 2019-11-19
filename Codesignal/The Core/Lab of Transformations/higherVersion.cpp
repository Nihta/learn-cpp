/**
 * Trả về true nếu phiên bản đầu tiên cao hơn phiên bản thứ hai.
 * 1.0.5 < 1.1.0 < 1.1.5 < 1.1.10 < 1.2.0 < 1.2.2 < 1.2.10 < 1.10.2 < 2.0.0
 */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool higherVersion(string ver1, string ver2) 
{
    vector<int> v1, v2;
    stringstream ss1(ver1), ss2(ver2);

    string tmp;
    while(getline(ss1, tmp, '.'))
        v1.push_back(stoi(tmp));
    while(getline(ss2, tmp, '.'))
        v2.push_back(stoi(tmp));
    return v1 > v2;
}


int main() {
    cout << boolalpha << higherVersion("1.1.0", "1.1.5");
    return 0;
}