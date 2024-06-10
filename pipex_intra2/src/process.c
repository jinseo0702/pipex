/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:30:25 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/10 11:43:23 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void ft_perror_msg(char *str, t_struct *a)
{
	perror(str);
	free(a);
	a = NULL;
	exit(1);
}

static void dup_and_close(int pipe, int file_fd, int flag)
{
	if (flag == 0)
	{
		dup2(file_fd, 1);
		dup2(pipe, 0);
	}
	else
	{
		dup2(file_fd, 0);
		dup2(pipe, 1);
	}
	close(pipe);
	close(file_fd);
}

static void free_2_1_struct(t_struct *a, char **cmd, char *path)
{
	free(a);
	a = NULL;
	ft_free_split(cmd);
	ft_is_free(path);
}

void	child_proc(t_struct *a)
{
	static char	**cmd_child;
	char	*path;
	int		file2_fd;
	int fd;

	file2_fd = open(a->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd = open(a->file1, O_RDONLY);
	if (file2_fd == -1 || fd == -1)
		ft_perror_msg("faild open file2", a);
	close(fd);
	close(a->fd[1]);
	dup_and_close(a->fd[0], file2_fd, 0);
	cmd_child = ft_split(a->cmd2, ' ');
	if (ft_memcmp(a->cmd2, "", 1))
		path = ft_re_path(a->envp, a->cmd2);
	else
		path = ft_strdup("");
	if ((execve(path, cmd_child, a->envp)) == -1)
	{
		if (ft_memcmp(a->cmd1, "", 1) != 0)
		{
			free_2_1_struct(NULL, cmd_child, path);
			cmd_child = ft_split(a->cmd1, ' ');
			path = ft_re_path(a->envp, a->cmd1);
			if ((execve(path, cmd_child, a->envp)) == -1)
				free_2_1_struct(a, cmd_child, path);
		}
		free_2_1_struct(a, cmd_child, path);
	}
}

void	parents_proc(t_struct *a, int pid)
{
	char	**cmd_parents;
	char	*path;
	int		file1_fd;

	file1_fd = open(a->file1, O_RDONLY);
	if (file1_fd == -1)
		ft_perror_msg("faild open file1", a);
	waitpid(pid, 0, WNOHANG);
	close(a->fd[0]);
	dup_and_close(a->fd[1], file1_fd, 1);
	cmd_parents = ft_split(a->cmd1, ' ');
	if (ft_memcmp(a->cmd1, "", 1))
		path = ft_re_path(a->envp, a->cmd1);
	else
		path = ft_strdup("");
	if ((execve(path, cmd_parents, a->envp)) == -1)
	{
		ft_free_split(cmd_parents);
		ft_is_free(path);
		free(a);
	}
}
