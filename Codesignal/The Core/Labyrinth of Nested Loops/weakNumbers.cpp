/**
 * Định nghĩa weakness của số x là số lượng số nguyên dương nhỏ hơn x có nhiều ước hơn x
 * Bạn cần trả lời hai câu hỏi:
 *    Weakness lớn nhất của các số trong phạm vi [1, n] là gì?
 *    Có bao nhiêu số trong phạm vi [1, n] có weakness này?
 * Trả về câu trả lời dưới dạng một mảng gồm hai phần tử, trong đó phần tử đầu
 * tiên là câu trả lời cho câu hỏi đầu tiên và phần tử thứ hai là câu trả lời
 * cho câu hỏi thứ hai.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> weakNumbers(int n) {
    vector<int> weakness, d(n+1, 0);

    // Tạo mảng số lượng ước
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= sqrt(i); j++)
            if (i%j == 0)
                if (i != j*j) 
                    d.at(i) += 2; 
                else 
                    d.at(i) += 1; 

    // Tạo mảng weakness
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j < i; j++)
            if (d.at(j) > d.at(i))
                count++;
        weakness.push_back(count);
    }

    int q1 = *max_element(weakness.begin(), weakness.end());
    int q2 = count(weakness.begin(), weakness.end(), q1);

    return {q1, q2};
}

int main() {
    for (auto i : weakNumbers(9)) // {2, 2}
        cout << i << ' ';
    cout << endl;
    return 0;
}