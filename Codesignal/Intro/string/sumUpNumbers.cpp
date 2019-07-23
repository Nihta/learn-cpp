// Tính tổng các số xuất hiện trong string
#include <iostream>
#include <vector>
#include <regex>
using namespace std;

int sumUpNumbers(string inputString)
{
    int sum = 0;
    string tmp = "0";
    for (int i = 0; i <= inputString.length(); ++i)
        if(i < inputString.length() && isdigit(inputString[i]))
            tmp += inputString[i];
        else
        {
                sum += stoi(tmp);
            tmp = "0";
        }
    return sum;
}

int sumUpNumbers2(string s) {
    regex re("[0-9]+");
    auto numbersIt = sregex_iterator(s.begin(), s.end(), re);

    int sum = 0;

    for ( ; numbersIt != sregex_iterator(); numbersIt++)
        sum += stoi(numbersIt->str());

    return sum;
}




int main()
{
    string s = "1 2ab c3 w4ww5w 6yy7 x8x 9"; // 45
    cout << sumUpNumbers(s) << endl;
    cout << sumUpNumbers2(s) << endl;
    return 0;
}