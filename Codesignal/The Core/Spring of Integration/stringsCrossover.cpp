/**
 * Định nghĩa hoạt động crossover trên hai string A và B có độ dài bằng nhau
 * như sau:
 *     Kết quả của hoạt động đó là một string có cùng độ dài với string đầu vào.
 *     result[i] là A [i] hoặc B [i], được chọn ngẫu nhiên.
 * Cho string inputArray và string result, tìm xem có bao nhiêu cặp string từ
 * inputArray có kết quả của hoạt động crossover có thể bằng result.
 * Lưu ý rằng (A, B) và (B, A) là một cặp giống nhau. Cũng lưu ý rằng cặp không
 * thể bao gồm cùng một phần tử của hai lần (tuy nhiên nếu có hai phần tử bằng
 * nhau trong mảng, chúng có thể tạo thành
 * một cặp).
 */
#include <iostream>
#include <vector>
using namespace std;

bool ok(string a, string b, string r) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != r[i] && b[i] != r[i])
            return false;
    return true;
}

int stringsCrossover(vector<string> inputArray, string result) {
    int count = 0;
    for (int i = 0; i < inputArray.size()-1; i++)
        for (int j = i+1; j < inputArray.size(); j++)
            if (ok(inputArray[i], inputArray[j], result))
                count++;
    return count;
}

int main() {
    vector<string> v = {"abc", "aaa", "aba", "bab"};
    string result = "bbb";
    cout << stringsCrossover(v, result); // 2
    return 0;
}