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
    int (*decode) (char*, char*, int);
    decode = dlsym(hdl, "decode");

    // decode input
    char decoded[length];
    memset(decoded,'\0', length);
    int check = decode(argv[2], decoded, length);
    
    // print decoded input
    for (size_t i = 0; i < length; i++)
    {
        printf("%c", decoded[i]);
    }
    printf("\n");
    
    dlclose(hdl);
    return check;
}