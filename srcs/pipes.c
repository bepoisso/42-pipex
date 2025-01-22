/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:55 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/22 14:35:47 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	creat_fork2(pid_t *pid2, int *pipe_fd, t_pipex *px)
{
	*pid2 = fork();
	if (*pid2 == -1)
		ft_perror("Error\nforking for cmd2\n", px);
	if (*pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(px->path_cmd2, px->cmd2, px->envp);
		ft_perror("Error\nexecuting cmd2\n", px);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

void	creat_fork(pid_t *pid1, pid_t *pid2, int *pipe_fd, t_pipex *px)
{
	*pid1 = fork();
	if (*pid1 == -1)
		ft_perror("Error\nforking for cmd1\n", px);
	if (*pid1 == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(px->path_cmd1, px->cmd1, px->envp);
		ft_perror("Error\nexecuting cmd1\n", px);
	}
	creat_fork2(pid2, pipe_fd, px);
}

void	creat_pipe(t_pipex *px)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		free_cmds(px->cmd1, px->cmd2);
		ft_perror("Error\nCreating pipe\n", px);
	}
	creat_fork(&pid1, &pid2, pipe_fd, px);
}

void	pipex(t_pipex *px)
{
	if (handle_redirect(px))
	{
		free_2d(px->cmd1);
		free_2d(px->cmd2);
		exit(EXIT_FAILURE);
	}
	creat_pipe(px);
}
