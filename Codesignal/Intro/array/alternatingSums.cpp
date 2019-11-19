/*
    Cho 1 mảng: 1 ≤ a.length ≤ 10^5, 1 ≤ a[i] ≤ 100
    Tính tổng các phần tử có chỉ số lẻ và tổng các phần tử có chỉ số chẵn
    Input: {4, 3, 4, 3, 4, 3, 4}
    Output: {16, 9}
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> alternatingSums(vector<int> a) {
    int team1 = 0, team2 = 0;
    for(int i = 0; i<a.size(); i++)
        (i%2 == 0) ? team1 += a[i] : team2 += a[i];
    return {team1, team2};
}

int main()
{
    vector<int> v = {4, 3, 4, 3, 4, 3, 4}, result;
    result = alternatingSums(v);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}