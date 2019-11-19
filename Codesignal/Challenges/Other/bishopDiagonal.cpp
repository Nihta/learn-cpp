/**
 * Ở xứ sở cờ vua, các bishop (quân tượng) không thực sự thích nhau.
 * Trên thực tế, khi hai bishop tình cờ đứng trên cùng một đường chéo, họ lập
 * tức lao về phía hai đầu đối diện của cùng một đường chéo đó.
 * Cho các vị trí ban đầu (theo ký hiệu cờ vua) của hai bishop: bishop1 và
 * bishop2, hãy tính các vị trí tương lai của họ và trả về theo thứ tự xuất hiện
 * trong từ điển. Lưu ý rằng các bishop sẽ không di chuyển trừ khi họ nhìn thấy
 * nhau trên cùng một đường chéo.
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ostream &operator<<(ostream &os, vector<string> v)
{
    os << "(" << v.size() << ") { ";
    for (auto it = v.begin(); it != v.end(); it++)
        os << *it << (it + 1 != v.end() ? ", " : " ");
    os << "}";
    return os;
}
vector<string> bishopDiagonal(string bishop1, string bishop2)
{
    vector<string> res = {bishop1, bishop2};
    sort(res.begin(), res.end());

    // Nếu chúng đứng trên một đường chéo
    if (abs(res[0][1] - res[1][1]) == res[1][0] - res[0][0])
    {
        // Đường chéo song song a1h8 công thức x- thì y-, x+ thì y+
        if (res[0][1] < res[1][1])
        {
            // bishop1
            while ('a' < res[0][0] && '1' < res[0][1])
                res[0][0]--, res[0][1]--;
            // bishop2
            while (res[1][0] < 'h' && res[1][1] < '8')
                res[1][0]++, res[1][1]++;
        }
        // Đường chéo song song a8h1 công thức x+ thì y-, x- thì y
        if (res[0][1] > res[1][1])
        {
            // bishop1
            while ('a' < res[0][0] && res[0][1] < '8')
                res[0][0]--, res[0][1]++;
            // bishop2
            while (res[1][0] < 'h' && '1' < res[1][1])
                res[1][0]++, res[1][1]--;
        }
    }
    return res;
}

int main()
{
    cout << bishopDiagonal("g3", "e1") << endl; // {"e1", "h4"}
    cout << bishopDiagonal("d7", "f5") << endl; // {"c8", "h3"}
    cout << bishopDiagonal("d8", "b5");         // {"b5", "d8"}
    return 0;
}
