#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

void init_library(void** hdl_ptr, char* lib_name)
{
    // get library's .so file
    char dynamic_lib[strlen(lib_name)+5];
    memset(dynamic_lib, '\0', strlen(lib_name)+5);
    strcat(dynamic_lib, "./");
    strcat(dynamic_lib, lib_name);
    strcat(dynamic_lib, ".so");
    
    // open library for usage
    *hdl_ptr = dlopen(dynamic_lib, RTLD_LAZY);
    if (*hdl_ptr == NULL)
    {
        printf("Could not load library\n");
        exit(-1);
    }
}

int main(int argc, char** argv)
{
    // validate input
    void* hdl = NULL;
    if (argc != 3)
    {
        printf("Invalid input\n");
        exit(-1);
    }
    const int length = strlen(argv[2]);
    if (length < 0)
    {
        printf("Invalid input\n");
        exit(-1);
    }

    // load library
    init_library(&hdl, argv[1]);
    int (*encode) (char*, char*, int);
    encode = dlsym(hdl, "encode");

    // encode input
    char encoded[length];
    memset(encoded,'\0', length);
    int check = encode(argv[2], encoded, length);
    
    // print encoded input
    if (strcmp(argv[1],"codec1") == 0)
    {
        for (size_t i = 0; i < length; i++)
        {
            printf("%c", encoded[i]);
        }
    }
    else
    {
        for (size_t i = 0; i < length; i++)
        {
            printf("%d", encoded[i]);
        }
    }
    
    printf("\n");
    
    dlclose(hdl);
    return check;
}