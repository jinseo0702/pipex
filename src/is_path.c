#include "../include/pipex.h"

char *ft_re_path(char **envp)
{
    char **path_split;
    // char *path_real;
    int index;

    index = 0;
    while(ft_strnstr(envp[index], "PATH", 4) == 0)
        index++;
    path_split = ft_split(ft_strchr(envp[index], '/'), ':');
    int index2 = 0;
    while (path_split[index2])
    {
        printf("%s\n", path_split[index2]);
        index2++;
    }
    ft_free_split(path_split);
    return (envp[index]);
}