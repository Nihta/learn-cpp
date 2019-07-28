/**
 * Một toán tử step(x) hoạt động như sau: Nó thay đổi một số x thành x - s(x)
 * trong đó s(x) là tổng các chữ số của x. Bạn quyết định xây dựng một dãy số giảm dần: n, step(n), step(step(n)), ...  với 0 là phần tử sau cùng.
 * Xây dựng một dãy không đủ cho bạn, vì vậy bạn thay thế tất cả các phần tử
 * của dãy trên bằng tổng các chữ số của chúng s(x).
 * Bây giờ bạn tò mò về số nào xuất hiện trong dãy mới thường xuyên nhất.
 * Nếu có một vài câu trả lời, hãy trả về câu trả lời tối đa.
 * 1 ≤ n ≤ 10e5
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int mostFrequentDigitSum(int n) {
    vector<int> vS;
    set<int> setE;
    while (n != 0)
    {
        int sumn = 0;
        for (int t = n; t != 0; t/=10)
            sumn += t%10;
        vS.push_back(sumn);
        setE.insert(sumn);
        int sumN = 0;
        for (int t = n; t != 0; t/=10)
            sumN += t%10;
        n -= sumN;
    }

    // Tần suất hiện
    vector<int> countE;
    for (int i : setE)
        countE.push_back(count(vS.begin(), vS.end(), i));
    int countMAx = *max_element(countE.begin(), countE.end());

    int i = countE.size() - 1;
    for (auto it = setE.rbegin(); setE.rend() != it; it++)
        if (countE[i--] == countMAx)
            return *it;

    return 0;
}

int mostFrequentDigitSum2(int n) {
    return n >= 999 ? 18 : n >= 9 ? 9 : n;
}

int main() {
    cout << mostFrequentDigitSum(88) << endl; // 9
    cout << mostFrequentDigitSum2(88) << endl;
    return 0;
}