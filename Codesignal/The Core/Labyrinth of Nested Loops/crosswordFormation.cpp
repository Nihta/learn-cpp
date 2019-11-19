/**
 * Bạn là một người thích chơi ô chữ, và cuối cùng đã quyết định thử và tạo ra một ô chữ của riêng bạn.
 * Bạn đưa ra một bộ quy tắc:
 *    Ô chữ chứa chính xác bốn từ
 *    Bốn từ này sẽ tạo thành bốn cặp giao điểm
 *    Tất cả các từ phải được viết từ trái sang phải hoặc từ trên xuống dưới
 *    Diện tích của hình chữ nhật được hình thành bởi các ô trống bên trong các giao điểm không bằng 0. (*)
 * Cho 4 từ, tìm số cách tạo ô chữ theo các quy tắc được mô tả ở trên.

  f                         f                             f
  o                     c r o s s w o r d     c r o s s w o r d
c r o s s w o r d           r   o                   q     r
  m   q                     m   m                   u     m
  a   u            ;  s q u a r e          ;        a     a
  t   a                     t   t                   r     t
  i   r                     i   h             s o m e t h i n g
s o m e t h i n g           o   i                         o
  n                         n   n                         n
                                g

    c         s               s
f o r m a t i o n       c     q               c         s
    o         m         r     u               r         o
    s q u a r e       f o r m a t i o n       o         m
    s         t    ;    s     r            ;  s q u a r e
    w         h         s o m e t h i n g     s         t
    o         i         w                     w         h
    r         n         o                   f o r m a t i o n
    d         g         r                     r         n
                        d                     d         g

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    B        D
    |        |
    | b1     | d1
 A -a1-------a2------
    |        |
    |        | 
    | b2     | d2
 C -c1-------c2------
    |        |
    |        |
*/
int check(string a, string b, string c, string d) {
    int count = 0;
    for (int a1 = 0; a1 < a.length(); a1++)
        for (int a2 = a1+2; a2 < a.length(); a2++) // a2 = a1+2 để thỏa mãn (*)
            for (int b1 = 0; b1 < b.length(); b1++)
                for (int b2 = b1+2; b2 < b.length(); b2++)
                    for (int c1 = 0; c1 < c.length(); c1++)
                        for (int d1 = 0; d1 < d.length(); d1++) {
                            int c2 = c1 + (a2-a1),
                                d2 = d1 + (b2-b1);
                            if (c2 < c.length() && d2 < d.length())
                                if (a[a1] == b[b1] && a[a2] == d[d1]
                                    && c[c1] == b[b2] && c[c2] == d[d2])
                                    count++;
                        }
    return count;
}
int crosswordFormation(vector<string> vs) {
    int result = 0;
    // Đặt 4 từ vào 4 vị trí và tìm số cách xếp tạo ra ô chữ thỏa mãn quy tắc
    for (int i = 0; i < vs.size(); i++)
        for (int j = 0; j < vs.size(); j++)
            for (int x = 0; x < vs.size(); x++)
                for (int y = 0; y < vs.size(); y++)
                    if (i!=j && i!=x && i!=y && j!=x && j!=y && x!=y)
                        result += check(vs[i], vs[j], vs[x], vs[y]);
    return result;
}

int crosswordFormation2(vector<string> vs) { 
    int result = 0;
    sort(vs.begin(), vs.end()); 
    do 
        result += check(vs[0], vs[1], vs[2], vs[3]); 
    while (next_permutation(vs.begin(), vs.end()));
    return result;
}

int main() {
    vector<string> vs = {
        "crossword",
        "square",
        "formation",
        "something"
    };
    cout << crosswordFormation(vs);
    return 0;
}
