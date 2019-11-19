/*
    Cho hai string, tìm số lượng ký tự chung giữa chúng.
    Ví dụ:
        s1 = "aabcc", s2 = "adcaa"
        commonCharacterCount(s1, s2) = 3 (chung 2 a và 1 c)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int commonCharacterCount(string s1, string s2)
{
    int commonCharacter = 0;
    // Kiểm tra từng kí tự trong s1 có trong s2 hay không
    for (int i = 0; i < s1.length(); i++)
    {
        int search_index = s2.find(s1[i]);
        if (search_index != -1)
        {
            commonCharacter++;
            // Đổi kí tự chung đó thành '!' - tránh lặp
            s2[search_index] = '!';
        }
    }
    return commonCharacter;
}

int commonCharacterCount2(string s1, string s2)
{
    // Tính tần suất xuất hiện các kí tự trong s1, s2
    int countS1[26] = { 0 };
    int countS2[26] = { 0 };
    for (auto &&ch : s1)
        ++countS1[ch - 'a'];
    for(auto &&ch : s2)
        ++countS2[ch - 'a'];
    
    // Tần suất xuất hiện nhỏ hơn = tần suất xuất hiện trên cả 2 xâu
    int commonCharacter = 0;
    for(int i = 0; i < 26; ++i)
        commonCharacter += min(countS1[i],countS2[i]);
    
    return commonCharacter;
}

int main()
{
    cout << commonCharacterCount("aabcc", "adcaa") << endl;
    cout << commonCharacterCount2("aabcc", "adcaa") << endl;
    return 0;
}