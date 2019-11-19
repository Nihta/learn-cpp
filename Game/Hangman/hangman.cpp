#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

string randomWord(string fileAddress)
{
    // Mở file và chọn một từ ngẫu nhiên
    ifstream fin(fileAddress);
    string word = "";
    int numberOfWords;
    fin >> numberOfWords;
    srand(time(NULL));
    for (int i = rand() % numberOfWords; i >= 0; i--)
        fin >> word;
    fin.close();
    return word;
}

void status(int miscounter)
{
    if (miscounter == 0)
    {
        cout << " _____" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 1)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 2)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << " |   I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 3)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << "/|   I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 4)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << "/|\\  I" << endl;
        cout << "     I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 5)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << "/|\\  I" << endl;
        cout << "/    I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
    else if (miscounter == 6)
    {
        cout << " _____" << endl;
        cout << " O   I" << endl;
        cout << "/|\\  I" << endl;
        cout << "/ \\  I" << endl;
        cout << "     I" << endl;
        cout << "======" << endl;
    }
}

// Khi answer là đúng
bool rightAnswer(const string &word, const char &answer, string &secret, string &wordUsed)
{
    wordUsed = wordUsed + answer + ' ';
    bool res = false;
    for (int i = 0; i < word.length(); i++)
        if (word[i] == answer)
            secret[i] = answer, res = true;
    return res;
}

void render(const string &secret, const int &miscounter, const string &wordUsed)
{
    system("cls");
    cout << "[ ";
    for (char c : secret)
        cout << c << " ";
    cout << ']' << endl;

    status(miscounter);

    cout << "[ " << wordUsed << "]" << endl;
}

void game(string word)
{
    // Khởi tạo
    int wrongAnswer = 0, replacecounter = 0;
    string secret = string(word.length(), '_');
    string wordUsed = "";

    while (word != secret)
    {
        render(secret, wrongAnswer, wordUsed);
        cout << "Du doan ki tu: ";
        char answer;
        cin >> answer;
        if (wordUsed.find(answer) != string::npos)
            continue;

        if (!rightAnswer(word, answer, secret, wordUsed)) // Nếu như trả lời sai
        {
            wrongAnswer++;
            if (wrongAnswer == 6) // Thua cuộc
            {
                system("cls");
                cout << "You died!" << endl;
                status(6);
                cout << "Answer: [ " << word << " ]";
                break;
            }
        }

        if (word == secret)
        {
            system("cls");
            cout << "YOU WIN!" << endl;
        }
    }
}

int main()
{
    string word = randomWord("./Game/Hangman/cpp.txt");
    game(word);
    return 0;
}
