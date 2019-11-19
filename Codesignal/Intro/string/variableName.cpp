/*
Tên biến chính xác chỉ bao gồm các chữ cái tiếng Anh,
chữ số và dấu gạch dưới và chúng không thể bắt đầu bằng một chữ số.
Kiểm tra xem chuỗi đã cho có phải là một tên biến chính xác không.
 */
#include <iostream>
#include <regex>
using namespace std;

bool variableName(string name)
{
    if(isdigit(name[0]))
        return false;

    for(char ch : name)
        if(!isalpha(ch) && !isdigit(ch) && ch != '_')
            return false;
    return true;
}

bool variableName2(std::string name) {
    regex r("[_a-zA-Z][_a-zA-Z0-9]*");
    return regex_match(name, r);
}


int main()
{
    string s1 = "abc_123";
    string s2 = "1 :v =))";

    cout << boolalpha << variableName(s1) << endl;
    cout << variableName(s2) << endl;

    cout << boolalpha << variableName2(s1) << endl;
    cout << variableName2(s2);

    return 0;
}