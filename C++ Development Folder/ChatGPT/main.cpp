#include <iostream>
#include <cstring>

using namespace std;

int myFind(const char * targetStr, const char * subStr)
{
    int count = 0;
    int targetLen = strlen(targetStr);
    int subLen = strlen(subStr);

    for (int i = 0; i <= targetLen - subLen; i++)
    {
        if (strncmp(targetStr + i, subStr, subLen) == 0)
        {
            count++;
        }
    }

    return count;
}

int myRemove(char * targetStr, const char * strToRemove)
{
    int targetLen = strlen(targetStr);
    int removeLen = strlen(strToRemove);
    int pos = -1;

    for (int i = 0; i <= targetLen - removeLen; i++)
    {
        if (strncmp(targetStr + i, strToRemove, removeLen) == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        return -1;
    }

    int newLen = targetLen - removeLen;
    for (int i = pos; i < newLen; i++)
    {
        targetStr[i] = targetStr[i + removeLen];
    }

    targetStr[newLen] = '\0';

    return pos;
}

using namespace std;
// functions to test your program, DO NOT modify
void testFind(const char* b, const char* s)
{
    int res = myFind(b, s);
    if (res <= 0) {
        cout << "String " << "\"" << s << "\"" << " does not appear in string " << "\"" << b << "\"" << endl;
    }
    else {
        cout << "String " << "\"" << s << "\"" << " found in string " << "\"" << b << "\"" << " at " << res << " locations" << endl;
    }
}
// functions to test your program, DO NOT modify
void testRemove(char* str, const char* find)
{
    cout << "The string before removing: " << str << endl;
    int res = myRemove(str, find);
    cout << "The string before removing: " << str << endl;
    if (res <= 0) {
        cout << "String " << "\"" << find << "\"" << " does not appear in string " << "\"" << str << "\"" << endl;
    }
    else {
        cout << "The removal happens at location " << res << endl;
    }
}
int main()
{
    testFind("abbbfd", "abc");
    testFind("Begining", "in");
    testFind("MyComputer", "put");
    testFind("Download", "load");
    testFind("friendship", "friend");
    char test1[15] = "Begining";
    testRemove(test1, "gin");
    char test2[15] = "Computer";
    testRemove(test2, "put");
    char test3[15] = "Download";
    testRemove(test3, "load");
}