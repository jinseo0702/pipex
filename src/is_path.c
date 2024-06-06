#include "../include/pipex.h"

char *ft_re_path(char **envp)
{
    char *path;
    int index;

    index = 0;
    while(envp[index])
    {
        if(!ft_memcmp(envp[index], "PATH", 4))
        {
            
        }
        index++;
    }
}