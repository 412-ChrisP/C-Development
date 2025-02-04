/*
 * MyString.cpp
 *
 * Program executes functions to return a string as indicated in the examples above from the word it gets as an argument
 *
 * @author_ChrisPham
 */


#include <iostream>
#include <string>

using namespace std;

string lower(string word)
{

    string _word;

    for (int i = 0; i < word.length(); i++)

    {

        char ch = word[i];

        if ('A' <= ch && ch <= 'Z')

        {

            ch = ch - 'A' + 'a';

            _word.push_back(ch);

        }

        return _word;

    }

}

string upper(string word)

{
    string _word;

    for (int i = 0; i < word.length(); i++)

    {

        char ch = word[i];

        if ('a' <= ch && ch <= 'z')

        {

            ch = ch - 'a' + 'A';

            _word.push_back(ch);

        }

        return _word;

    }

}

string capitalize(string word)

{

    string _word = lower(word);

    if ('a' <= _word[0] && _word[0] <= 'z')

    {

        _word[0] = _word[0] - 'a' + 'A';



    }

    return _word;

}

string reverse(string word)

{
    string _word;

    for (int i = word.length() - 1;

         i >= 0; i--);

    _word.push_back(word[i]);

    return _word;
}

int main()
{

    string word;

    cout << "Please enter a word: ";

    cin >> word;

    while (word != "quit") {

        cout << "Lower case: " << lower(word) << endl;

        cout << "Captalize case: " << capitalize(word) << endl;

        cout << "Reverse: " << reverse(word) << endl;

        cout << "Please enter a word: ";

        cin >> word;

    }

    return 0;
}
/*
EXECUTION CODE:
Please enter a word: Hello-World
Lower case: hello-world
Upper case: HELLO-WORLD
Capitalize: Hello-world
Reverse: dlroW-olleH
Please enter a word: String-Character
Lower case: string-character
Upper case: STRING-CHARACTER
Capitalize: String-character
Reverse: retcarahC-gnirtS
Please enter a word: quit
*/