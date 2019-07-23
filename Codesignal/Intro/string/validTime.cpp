// Kiểm tra định dạng thời gian 24h
#include <iostream>
#include <regex>
using namespace std;

bool validTime(string time)
{
    string tmp = "";
    tmp += time[0], tmp += time[1];
    int h = stoi(tmp);
    tmp = "", tmp += time[3], tmp += time[4];
    int m = stoi(tmp);

    return h < 24 && m < 60;
}

bool validTime2(string time) {
    return stoi(time.substr(0,2)) < 24 && stoi(time.substr(3,2)) < 60;
}

bool validTime3(string time)
{
    return regex_match(time, regex("(?:[01]\\d|2[0-3]):[0-5]\\d"));
}


int main()
{
    cout << boolalpha << validTime("23:59");
    return 0;
}