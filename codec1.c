#include "codec.h"

int encode(char* src, char* dst, int len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(src[i]))
        {
            if (islower(src[i]))
            {
                dst[i] = toupper(src[i]);
            }
            else if (isupper(src[i]))
            {
                dst[i] = tolower(src[i]);
            }
            else
            {
                dst[i] = src[i];
            }
        }
        else
        {
            dst[i] = src[i];
        }
    }
    return 0;
}

int decode(char* src, char* dst, int len)
{
    return encode(src, dst, len);
}