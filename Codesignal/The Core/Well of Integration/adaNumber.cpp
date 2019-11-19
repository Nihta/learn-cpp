/**
 * Nhiệm vụ của bạn là xác định xem chuỗi đã cho có phải là biểu diễn số nguyên
 * hợp lệ hay không.
 * Xem như các đấu '_' không tồn tại.
 * Lưu ý: đây là cách số nguyên được biểu diễn trong ngôn ngữ lập trình Ada.
 *     cơSố#Số#
 */
#include <iostream>
#include <vector>
using namespace std;

bool adaNumber(string line) {
    bool result = false;
    if (line.back() == '#') {
        // Tìm cơ số
        int i, base;
        for (i = 0, base = 0; line[i] != '#' && base <= 16; i++)
            if (line[i] != '_')
                if ('0' <= line[i] && line[i] <= '9')
                    base = base * 10 + (line[i] - '0');
                else
                    return false;
        if (base < 2 || base > 16)
            return false;

        // Kiểm tra số
        for (i++ ;i < line.length() - 1; i++)
            if (line[i] != '_') {
                int digit = -1;
                if ('a' <= line[i] && line[i] <= 'f')
                    digit = line[i] - 'a' + 10;
                if ('A' <= line[i] && line[i] <= 'F')
                    digit = line[i] - 'A' + 10;
                if ('0' <= line[i] && line[i] <= '9')
                    digit = line[i] - '0';

                if (0 <= digit && digit < base)
                    result = true;
                else
                    return false;
            }
    }
    else
        for (char i : line)
        if (i != '_')
            if ('0' <= i && i <= '9')
                result = true;
            else
                return false;

    return result;
}

int main() {
    cout << boolalpha << adaNumber("16#123Abc#");
    return 0;
}
