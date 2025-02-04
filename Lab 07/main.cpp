#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_palindrome(char word[])
{
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++)
    {
        if (tolower(word[i]) != tolower(word[len - 1 - i]))
        {
            return false;
        }
    }
    return true;
}

string reverse(string sentence)
{
    for (char &c : sentence)
    {
        if (isupper(c))
        {
            c = tolower(c);
        }
        else if (islower(c))
        {
            c = toupper(c);
        }
    }
    return sentence;
}

int main()
{
    char word[100];
    cout << "Please enter a word: ";
    cin >> word;

    if (is_palindrome(word))
    {
        cout << "This is a palindrome.\n" << endl;
    }
    else
    {
        cout << "This is not a palindrome.\n" << endl;
    }

    cin.ignore();

    string sentence;
    cout << "Please enter a string below:" << endl;
    getline(cin, sentence);

    string modified = reverse(sentence);
    cout << "Your modified string:" << endl;
    cout << modified << endl;

    return 0;
}
/*
Execution Code:
Please enter a word: Racecar
This is a palindrome.

Please enter a string below:
McGyver premiered in 1985
Your modified string:
mCgYVER PREMIERED IN 1985

Please enter a word: reverse
This is not a palindrome.

Please enter a string below:
Bedford–Stuyvesant, Brooklyn is called Bed-Stuy.
Your modified string:
bEDFORD–sTUYVESANT, Brooklyn is called Bed-Stuy.
 */