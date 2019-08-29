#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string paragraph;
    cout << "Please enter your paragraph: ";
    getline (cin,paragraph);
    cout << "The size of your paragraph = " << paragraph.size() << " characters.\n";

    if (paragraph.empty())
    {
        cout << "The paragraph is empty!" << endl;
        return 0;
    }

    while (true)
    {
        string word;
        cout << "\n * Please enter the word you are searching for: ";
        getline (cin,word);
        if (paragraph.find(word) == string::npos)
        {
            cout << word << " does not exist in the sentence" << endl;
        }
        else
        {
            cout << "   The word " << word << " is now found at location ";cout << paragraph.find(word) << endl;
        }
    }

    return 0;
}
