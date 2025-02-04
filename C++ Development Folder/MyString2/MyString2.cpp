#include "mystring2.h"

String::String()
{
    len = 0;
    contents = new char[1];
    contents[0] = '\0';
}

String::String(const char s[])
{
    len = strlen(s);
    contents = new char[len+1];
    strcpy(contents, s);
}

String::String(const String& str)
{
    len = str.len;
    contents = new char[len+1];
    strcpy(contents, str.contents);
}

String::~String()
{
    delete[] contents;
}

void String::append(const String &str)
{
    int newLen = len + str.len;
    char* newContents = new char[newLen+1];
    strcpy(newContents, contents);
    strcat(newContents, str.contents);
    delete[] contents;
    contents = newContents;
    len = newLen;
}

bool String::operator ==(const String &str) const
{
    return strcmp(contents, str.contents) == 0;
}

bool String::operator !=(const String &str) const
{
    return strcmp(contents, str.contents) != 0;
}

bool String::operator >(const String &str) const
{
    return strcmp(contents, str.contents) > 0;
}

bool String::operator <(const String &str) const
{
    return strcmp(contents, str.contents) < 0;
}

bool String::operator >=(const String &str) const
{
    return strcmp(contents, str.contents) >= 0;
}

String String::operator +=(const String &str)
{
    append(str);
    return *this;
}

void String::print(ostream &out) const
{
    out << contents;
}

int String::length() const
{
    return len;
}

char String::operator [](int i) const
{
    return contents[i];
}

ostream & operator<<(ostream &out, const String & r)
{
    r.print(out);
    return out;
}