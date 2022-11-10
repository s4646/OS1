#include "codec.h"

int encode(char* src, char* dst, int len)
{
    char x;
    for (size_t i = 0; i < len; i++)
    {
        x = src[i];
        x = ~x;
        x = ((x & 1) << 1) ^ (x^1);
        dst[i] = x;
    }
    return 0;
}

int decode(char* src, char* dst, int len)
{
    char x;
    for (size_t i = 0; i < len; i++)
    {
        x = src[i];
        x = x = x^1;;
        x = ~x;
        dst[i] = x;
    }
    return 0;
}