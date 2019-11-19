/*
    Cho string s: 0 ≤ inputString.length ≤ 50
    Đảo ngược các kí tự trong cặp dấu ngoặc '(' & ')' và xóa bỏ chúng
    Các đấu ngặc có thể lồng nhau
    Input:       "foo(bar(baz))blim"
    Output:      "foobazrabblim"
 */
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string reverseInParentheses(string s)
{
    // Tìm vị trí cặp đấu ngoặc
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ')')
        {
            for(int j=i-1; j>=0; j--)
            {
                if(s[j] == '(')
                {
                    /*
                        i là vị trí ')' đầu tiên
                        j là vị trí '(' gần vị trí i nhất tạo thành cặp ngoặc ()
                    */

                    // Đảo ngược string trong cặp dấu ngoặc
                    reverse(s.begin() + j + 1, s.begin() + i);

                    // Xóa đấu ngoặc phía sau trước rồi đến dấu phía trước
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + j);

                    // Đệ quy dừng khi không tìm được dấu ')' nữa
                    return reverseInParentheses(s);
                }
            }
        }
    }
    return s;
}

string reverseInParentheses2(string s)
{
    // Lưu vị trí '(' xuất hiện trong s
    stack <int> st;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
            st.push(i);
        if (s[i] == ')')
        {
            // Vị trí '(' xuất hiện sau cùng hay vị trí gần ')' nhất
            int start = st.top();
            // Xóa vị trí '(' đó ra khỏi stack
            st.pop();
            // Đảo ngược string trong cặp ngoặc trên
            reverse(s.begin() + start + 1, s.begin() + i);
        }
    }

    // Xóa các dấu ngoặc ra khỏi string 
    string ans;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] !=  '(' && s[i] != ')')
            ans = ans + s[i];
    return ans;
}

int main()
{
    string s = "foo(bar(baz))blim";
    cout << reverseInParentheses(s) << endl;
    cout << reverseInParentheses2(s) << endl;
    return 0;
}