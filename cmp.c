#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    // input validation
    if (argc != 3)
    {
        printf("Usage: ./cmp <file1> <file2>\n");
        exit(-1);
    }

    // open files
    FILE* ptr1 = fopen(argv[1], "rb");
    FILE* ptr2 = fopen(argv[2], "rb");
    if (ptr1 == NULL || ptr2 == NULL)
    {
        printf("Error: could not open files\n");
        exit(-1);
    }

    // compare files
    size_t check1, check2;
    char c1, c2;
    while(1)
    {
        check1 = fread(&c1,sizeof(char),1,ptr1);
        check2 = fread(&c2,sizeof(char),1,ptr2);
        if (check1 == 0 || check2 == 0)
        {
            if ((feof(ptr1) && check2 !=0) || (feof(ptr2) && check1 !=0))
            {
                printf("Not identical\n");
                break;
            }
            else if (ferror(ptr1) || ferror(ptr2))
            {
                printf("Error: could not read from files\n");
                exit(-1);
            }
            else
            {
                printf("Identical\n");
                break;
            }
        }
        if (c1 != c2)
        {
            printf("Not identical\n");
            break;
        }
    }

    // close files
    fclose(ptr1);
    fclose(ptr2);
    
    return 0;
}