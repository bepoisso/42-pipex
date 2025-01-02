/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:57 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 20:15:42 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	creat_fork(pid_t *pid1, pid_t *pid2, int *pipe_fd, t_pipex *px)
{
	char	**args;

	*pid1 = fork();
	if (*pid1 == -1)
		ft_perror("Error\nforking for cmd1\n");
	if (*pid1 == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		args = ft_split(px->cmd1, ' ');
		execve(args[0], args, px->envp);
		ft_perror("Error\nexecuting cmd1\n");
	}
	*pid2 = fork();
	if (*pid2 == -1)
		ft_perror("Error\nforking for cmd2\n");
	if (*pid2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		args = ft_split(px->cmd2, ' ');
		execve(args[0], args, px->envp);
		ft_perror("Error\nexecuting cmd2\n");
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}

void	creat_pipe(t_pipex *px)
{
	pid_t	pid1;
	pid_t	pid2;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		free_cmds(px->cmd1, px->cmd2);
		ft_perror("Error\nCreating pipe\n");
	}
	creat_fork(&pid1, &pid2, pipe_fd, px);
}

void	pipex(t_pipex *px)
{
	if (handle_redirect(px))
	{
		free(px->cmd1);
		free(px->cmd2);
		exit(EXIT_FAILURE);
	}
	creat_pipe(px);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	check_args(ac, &av, envp);
	px = init_pipex(av[1], av[2], av[3], av[4]);
	px.envp = envp;
	pipex(&px);
	free(av[2]);
	free(av[3]);
	return (0);
}
