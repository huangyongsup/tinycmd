#ifndef MYSTRING_H
#define MYSTRING_H

#include<cstddef>

class MyString
{
public:
    MyString();
    ~MyString();
    size_t stringCompara(const char *str1, const char *str2);
    size_t stringLength(const char *str);
    char *memoryCopy(char *dst, const char *src, int cnt);
    char *stringCopy(char *dst, const char *src);
};

#endif // MYSTRING_H
