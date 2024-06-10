/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:57:03 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/10 11:30:15 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int pid;

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
			child_proc(fd, argv[3], argv[4], envp);
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
