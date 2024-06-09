#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../libft/libft.h"                                                                             
#include "../ft_printf/libftprintf.h"

char *ft_re_path(char **envp, char *cmd);
void ft_is_free(char *str);
void child_proc(int *fd, char *cmd, char *file2, char **envp);
void parents_proc(int *fd, char *cmd, char *file1, char **envp, int pid);

#endif