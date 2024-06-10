/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:27:47 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/10 11:29:55 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void ft_is_free(char *str)
{
	free(str);
	str = NULL;
}

char *ft_re_path(char **envp, char *cmd)
{
	char **path_split;
	char *path_real;
	char *path_real2;
	char **split_cmd;
	int index;

	index = 0;
	split_cmd = ft_split(cmd, ' ');
	while(ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	path_split = ft_split(ft_strchr(envp[index], '/'), ':');
	index = 0;
	while (path_split[index])
	{
		path_real = ft_strjoin(path_split[index], "/");
		path_real2 = ft_strjoin(path_real, split_cmd[0]);
		if(access(path_real2, F_OK) == 0)
		{
			ft_free_split(split_cmd);
			ft_free_split(path_split);
			ft_is_free(path_real);
			return (path_real2);
		}
		ft_is_free(path_real);
		ft_is_free(path_real2);
		index++;
	}
	ft_free_split(path_split);
	return (envp[index]);
}
