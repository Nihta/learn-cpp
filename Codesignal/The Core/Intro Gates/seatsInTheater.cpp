/*
 ... Cho tổng số hàng và cột trong rạp chiếu phim (lần lượt là nRows và nCols),
 và hàng và cột bạn đang ngồi (col và row).
 Tính số lượng người ngồi trong hình hình chữ nhật xanh   /seatsInTheater.png
*/
#include <iostream>
using namespace std;

int seatsInTheater(int nCols, int nRows, int col, int row) {
    return (nRows - row) * (nCols - col + 1);
}

int main() {
    cout << seatsInTheater(16, 11, 5, 3); // 96
    return 0;
}