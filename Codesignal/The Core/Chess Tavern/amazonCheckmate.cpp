/**
 * Một amazon (sự kết hợp của hậu + mã) là một quân cờ tưởng tượng có thể
 * di chuyển như một hậu hoặc mã (hoặc tương đương như một xe, tượng và mã).
 * Biểu đồ (amazonCheckmate_amazon.png) cho thấy tất cả các ô vuông mà amazon
 * có thể tấn công từ e4 (các vòng tròn biểu thị các bước di chuyển giống như
 * mã trong khi các đường chéo tương ứng với các bước di chuyển giống như hậu).
 *
 * Gần đây, bạn bắt gặp một sơ đồ bàn cờ chỉ còn lại ba quân trên bàn: một amazon
 * trắng, vua trắng và vua đen. Giờ là lượt của quân đen. Bạn không có thời gian
 * để xác định xem trò chơi đã kết thúc hay chưa, nhưng bạn muốn tìm hiểu nó
 * trong đầu. Thật không may, sơ đồ bị nhoè và bạn không thể thấy vị trí của
 * vua đen, vì vậy bạn sẽ cần xem xét tất cả các vị trí có thể.
 *
 * Cho vị trí của các quân cờ trắng trên bàn cờ tiêu chuẩn (sử dụng ký hiệu),
 * nhiệm vụ của bạn là xác định số lượng vị trí của vua đen có thể sao cho:
 *     - Đó là checkmate (tức là vua đen đang bị tấn công bởi amazon và nó không
 * thể thực hiện một động thái hợp lệ);
 *     - Đó là check (tức là vua đen đang bị tấn công bởi amazon nhưng nó có thể
 * đạt đến một hình vuông an toàn trong một lần di chuyển);
 *     - Đó là stalemate (tức là vua đen đang an toàn nhưng nó không thể thực
 * hiện một động thái hợp lệ);
 *     - Vua đen đang ở trên một quảng trường an toàn và nó có thể tạo ra \
 * một bước đi hợp lệ.
 * Case 1: amazonCheckmate_case1.png
*/
#include <iostream>
#include <vector>
using namespace std;

// Output Operator Overloading
template <typename T>
ostream &operator<<(ostream &os, vector<T> vt)
{
    os << "(" << vt.size() << ") { ";
    for (auto it = vt.begin(); it != vt.end(); it++)
        os << *it << (it + 1 != vt.end() ? ", " : "");
    os << " }";
    return os;
}

std::vector<int> amazonCheckmate(std::string king, std::string amazon)
{
}

int main()
{
    cout << amazonCheckmate("d3", "e4") << endl; // { 5, 21, 0, 29}
    return 0;
}
