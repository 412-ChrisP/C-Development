#include "LabProj3.h"
#include <cstring>
#include <iostream>
using namespace std;

int Functions::myFind(const char * targetStr, const char * subStr)
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

int Functions::myRemove(char * targetStr, const char * strToRemove)
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
