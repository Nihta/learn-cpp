/**
 * Để chuẩn bị cho học sinh của mình cho một trận đấu sắp tới, 
 * huấn luyện viên thể thao quyết định thử một số bài tập huấn mới.
 * Để bắt đầu, anh xếp chúng lại và bắt đầu với bài tập khởi động sau: 
 * Khi huấn luyện viên nói 'L', anh ấy hướng dẫn các học sinh rẽ sang trái.
 * Ngoài ra, khi anh ta nói 'R', các học sinh rẽ sang phải.
 * Cuối cùng, khi huấn luyện viên nói 'A', các học sinh nên quay lại.
 * Thật không may, một số học sinh (không phải tất cả, nhưng ít nhất là một)
 * luôn rẽ phải khi nghe 'L' và trái khi họ nghe thấy 'R'.
 * Huấn luyện viên muốn biết số lần các học sinh quay mặt với cùng một hướng.
 * Đưa ra danh sách các lệnh mà huấn luyện viên đã đưa ra, tính số lần học sinh
 * quay mặt cùng một hướng.
 */
#include <iostream>
using namespace std;

int lineUp(string commands) {
    int same = 1, count = 0;
    for (char c : commands)
    {
        if(c != 'A')
            same = (same ? 0 : 1);
        if(same)
            count++;
    }
    return count;
}

int main() {
    cout << lineUp("LLARL"); // 3
    return 0;
}