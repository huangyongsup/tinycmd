#include "mystring.h"
#include<assert.h>

MyString::MyString()
{

}

MyString::~MyString()
{

}

size_t MyString::stringCompara(const char *str1, const char *str2)
{
    int ret = 0;
    while(!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && *str2)
    {
        ++str1;
        ++str2;
    }
    if(ret < 0)
    {
        ret = -1;
    }
    else if(ret > 0)
    {
        ret =1;
    }
    return ret;
}

char *MyString::memoryCopy(char *dst, const char *src, int cnt)
{
    assert(dst != nullptr && src != nullptr);
    char *ret =dst;
    if(dst >= src && dst <= src + cnt -1)
    {
        dst = dst + cnt -1;
        src = src + cnt -1;
        while (cnt--)
        {
            *dst-- = *src--;
        }
    }
    else
    {
        while(cnt--)
        {
            *dst++ = *src++;
        }
    }
    return ret;
}

char *MyString::stringCopy(char *dst, const char *src)
{
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    MyString::memoryCopy(dst, src, MyString::stringLength(src) + 1);
    return ret;
}

size_t MyString::stringLength(const char *str)
{
    assert(str != NULL);
    const char *eos = str;
    while(*eos++);
    return (eos - str -1);
}
