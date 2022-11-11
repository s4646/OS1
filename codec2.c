#include "codec.h"

int encode(char* src, char* dst, int len)
{
    // char x;
    for (size_t i = 0; i < len; i++)
    {
        dst[i] = -src[i];
    }
    return 0;
}

int decode(char* src, char* dst, int len)
{
    int counter = 0;
    int index = 0;
    int j = 0;
    char x;
    char c[5];
    memset(c,'\0', 5);

    while(counter < len + 1)
    {
        if (counter == 0)
        {
            counter++;
            continue;
        }
        else if ((src[counter] != '-') && src[counter] != '\0')
        {
            c[index] = src[counter];
            index++;
        }
        else
        {
            x = -atoi(c);
            x = -x;
            dst[j++] = x;
            memset(c,'\0', 5);
            index = 0;
        }
        counter++;
    }
    return 0;
}