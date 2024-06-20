/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:27:47 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/17 13:32:17 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_is_free(char *str)
{
	free(str);
	str = NULL;
}

static void	ft_is_free_twice(char *path_real, char *path_real2)
{
	ft_is_free(path_real);
	ft_is_free(path_real2);
}

static void	free_2_1_demen(char **cmd2, char **path2, char *path1)
{
	ft_free_split(cmd2);
	ft_free_split(path2);
	ft_is_free(path1);
}

static int	ft_is_path_index(char **envp)
{
	int	index;

	index = 0;
	while (ft_strnstr(envp[index], "PATH", 4) == 0)
		index++;
	return (index);
}

char	*ft_re_path(char **envp, char *cmd)
{
	char	**path_split;
	char	*path_real;
	char	*path_real2;
	char	**split_cmd;
	int		index;

	index = ft_is_path_index(envp);
	split_cmd = ft_split(cmd, ' ');
	path_split = ft_split(ft_strchr(envp[index], '/'), ':');
	index = -1;
	while (path_split[++index])
	{
		path_real = ft_strjoin(path_split[index], "/");
		path_real2 = ft_strjoin(path_real, split_cmd[0]);
		if (access(path_real2, F_OK) == 0)
		{
			free_2_1_demen(split_cmd, path_split, path_real);
			return (path_real2);
		}
		ft_is_free_twice(path_real, path_real2);
	}
	ft_free_split(path_split);
	ft_free_split(split_cmd);
	return (ft_strdup(cmd));
}
