/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:30:25 by jinseo            #+#    #+#             */
/*   Updated: 2024/06/10 11:32:00 by jinseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void child_proc(int *fd, char *cmd, char *file2, char **envp)
{
	char **cmd_child;
	char *path;
	int file2_fd;

	file2_fd = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2_fd == -1)
	{
		perror("faild open file2");
		exit(1);
	} 
	close(fd[1]);
	dup2(file2_fd, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(file2_fd);
	cmd_child = ft_split(cmd, ' ');
	if(ft_memcmp(cmd, "", 1))
		path = ft_re_path(envp, cmd);
	else
		path = ft_strdup("");
	if((execve(path, cmd_child, envp)) == -1)
	{
		ft_free_split(cmd_child);
		ft_is_free(path);
	}
}

void parents_proc(int *fd, char *cmd, char *file1, char **envp, int pid)
{
	char **cmd_parents;
	char *path;
	int file1_fd;

	file1_fd = open(file1, O_RDONLY);
	if (file1_fd == -1)
	{
		perror("faild open file1");
		exit(1);
	}
	waitpid(pid, 0, WNOHANG);
	(void)pid;
	// wait(0);//waitpid를 사용 하는이유 wait를 쓰면 직렬처리가되서 10초간 멈춘다. 하지만 원래 쉘에서는 $> sleep 5 | sleep 5는 총 5초간만 잠을 자야한다.
	close(fd[0]);
	dup2(file1_fd, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(file1_fd);
	cmd_parents = ft_split(cmd, ' ');
	if(ft_memcmp(cmd, "", 1))
		path = ft_re_path(envp, cmd);
	else
		path = ft_strdup("");
	if((execve(path, cmd_parents, envp)) == -1)
	{
		ft_free_split(cmd_parents);
		ft_is_free(path);
	}
}
