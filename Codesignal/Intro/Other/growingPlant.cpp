/*
Một giống cây ban ngày chiều cao tăng thêm upSpeed, ban đêm giảm xuống downSpeed
Hỏi sau bao lâu trồng cây (chiều cao bằng 0) thì nó cao bằng desiredHeight
 */
#include <iostream>
using namespace std;

int growingPlant(int upSpeed, int downSpeed, int desiredHeight)
{
    int height = 0, day = 0;
    while(++day)
    {
        height += upSpeed;
        if(height >= desiredHeight)
            return day;
        height -= downSpeed;
    }
}


int main()
{
    cout << growingPlant(100, 10, 910) << " day"; // 10
    return 0;
}