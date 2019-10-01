#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;

class MyDate
{
private:
    int day;
    int month;
    int year;

public:
    // Hàm thiết lập
    MyDate(int d = 0, int m = 0, int y = 0)
    {
        this->day = d;
        this->month = m;
        this->year = y;
    }
    // Hàm nhập ngày tháng năm
    void cinData();
    // Hàm hiện thông tin
    void display()
    {
        cout << this->day << " " << this->month << " " << this->year;
    }

    friend bool operator>=(MyDate time1, MyDate time2);
};

void MyDate::cinData()
{
    int d, m, y;
    cout << "Nhap ngay: ";
    cin >> d;
    cout << "Nhap thang: ";
    cin >> m;
    cout << "Nhap nam: ";
    cin >> y;
    this->day = d;
    this->month = m;
    this->year = y;
}

bool operator>=(MyDate time1, MyDate time2)
{
    if (time1.year < time2.year)
        return false;
    else if (time1.month < time2.month)
        return false;
    else if (time1.day < time2.day)
        return false;
    return true;
}

int main()
{
    MyDate time[3], max;
    for (int i = 0; i < 3; i++)
    {
        cout << "Nhap du lieu time[" << i << "]:\n";
        time[i].cinData();
    }

    max = time[0] >= time[1] ? (time[0] >= time[2] ? time[0] : time[2])
                             : (time[1] >= time[2] ? time[1] : time[2]);
    cout << "Doi tuong co thoi gian lon nhat la: ";
    max.display();
    return 0;
}
