#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
    // input validation
    if (argc != 3 && argc !=4)
    {
        printf("Usage: ./copy <file1> <file2>\n");
        exit(-1);
    }
    
    // open files
    int fd1, fd2;
    int opt = getopt(argc, argv, "l");
    struct stat buf;
    char linked[2048] = {'\0'};
    if (opt != -1) // copy link contents
    {
        if(readlink(argv[2], linked, 2048) == -1) // get symlink contents
        {
            perror("Error");
            exit(-1);
        }
        fd2 = open(argv[3], O_WRONLY);
        if (fd2 == -1)
        {
            perror("Error");
            exit(-1);
        }
        if (write(fd2, linked, strlen(linked)) == -1)
        {
            perror("Error");
            exit(-1);
        }
        else
        {
            printf("file is copied\n");
            if (close(fd2) == -1)
            {
                perror("Error");
                exit(-1);
            } 
        }
        return 0;
    }
    else
    {
        if (lstat(argv[2], &buf) == -1) // get file's stats
        {
            perror("Error");
            exit(-1);
        }
        if (S_ISLNK(buf.st_mode)) // if file is a symbolic link
        {
            if(readlink(argv[2], linked, 2048) == -1) // get symlink contents
            {
                perror("Error");
                exit(-1);
            }
            fd1 = open(linked, O_RDONLY);
            fd2 = open(argv[2], O_WRONLY);
        }
        else // file is original
        {
            fd1 = open(argv[1], O_RDONLY);
            fd2 = open(argv[2], O_WRONLY);
        }
    }

    if (fd1 == -1 || fd2 == -1)
    {
        perror("Error");
        exit(-1);
    }
    char c;
    size_t check1, check2;
    
    // copy files
    while(1)
    {
        check1 = read(fd1,&c,1);
        if (check1 <= 0)
        {
            if (check1 == -1)
            {
                perror("Error");
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
            perror("Error");
            exit(-1);
        }
        
    }
    
    printf("file is copied\n");
    if (close(fd1) == -1 || close(fd2) == -1)
    {
        perror("Error");
        exit(-1);
    }

    return 0;
}