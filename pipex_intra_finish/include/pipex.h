/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:44:09 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/17 13:46:31 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"

typedef struct s_struct
{
	int		*fd;
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}	t_struct;

char	*ft_re_path(char **envp, char *cmd);
void	ft_is_free(char *str);
void	child_proc(t_struct *a);
void	parents_proc(t_struct *a, int pid);

#endif
