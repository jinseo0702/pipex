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

static void ft_init_struct(t_struct *a, char **argv, char **envp, int *fd)
{
	a = (t_struct *)malloc(sizeof(t_struct));
	if (!a)
	{
		perror("Faild allocate struct a");
		exit(1);
	}
	a->fd = fd;
	a->file1 = argv[1];
	a->file2 = argv[4];
	a->cmd1 = argv[2];
	a->cmd2 = argv[3];
	a->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;
	t_struct *a;

	pipe(fd);
	pid = 0;
	if (argc == 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("faild fork try again!");
			exit(1);
		}
		
		else if (pid == 0)
			// child_proc(fd, argv[3], argv[4], envp);
			child_proc(a);
		else
			parents_proc(fd, argv[2], argv[1], envp, pid);
	}
	else
	{
		ft_putendl_fd("NOT form plz modify", 2);
		exit(1);
	}
	return (0);
}
