#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    // input validation
    if (argc != 3)
    {
        printf("Invalid input\n");
        exit(-1);
    }

    // open files
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_WRONLY);
    if (fd1== -1 || fd2 == -1)
    {
        printf("Error opening files\n");
        exit(-1);
    }
    char c;
    size_t check1, check2;
    while(1)
    {
        check1 = read(fd1,&c,1);
        if (check1 <= 0)
        {
            if (check1 == -1)
            {
                printf("Error reading from file.\n");
                exit(-1);
            }
            if (check1 == 0)
            {
                break;
            }
        }
        check2 = write(fd2,&c,1);
        if (check2 == -1)
        {
            printf("Error writing to file.\n");
            exit(-1);
        }
        
    }
    
    printf("file is copied\n");
    close(fd1);
    close(fd2);

    return 0;
}