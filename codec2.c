#include "codec.h"

int encode(char* src, char* dst, int len)
{
    for (size_t i = 0; i < len; i++)
    {
            dst[i] = -src[i];
    }
    return 0;
}

int decode(char* src, char* dst, int len)
{
    return encode(src, dst, len);
}