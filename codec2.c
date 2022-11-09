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

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    const int length = strlen(argv[1]);
    if (length < 0)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    
    char encoded[length];
    memset(encoded,'\0', length);
    int check = encode(argv[1], encoded, length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%c", encoded[i]);
    }
    printf("\n");
    
    return check;
}