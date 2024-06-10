/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:57:03 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/10 11:38:35 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static t_struct *ft_init_struct(char **argv, char **envp, int *fd)
{
	t_struct *all;
	all = (t_struct *)malloc(sizeof(t_struct));
	if (!all)
	{
		perror("Faild allocate struct all");
		exit(1);
	}
	all->fd = fd;
	all->file1 = argv[1];
	all->file2 = argv[4];
	all->cmd1 = argv[2];
	all->cmd2 = argv[3];
	all->envp = envp;
	return (all);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	t_struct *a;

	pipe(fd);
	pid = 0;
	a = ft_init_struct(argv, envp, fd);
	if (argc == 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("faild fork try again!");
			exit(1);
		}
		if (pid == 0)
			child_proc(a);
		else
			parents_proc(a, pid);
	}
	else
	{
		free(a);
		ft_putendl_fd("NOT form plz modify", 2);
		exit(1);
	}
	return (0);
}
