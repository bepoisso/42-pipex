/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:26:00 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/23 16:36:53 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Check if files exist with right access
void	check_files(char *infile, char *outfile, t_pipex *px)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		ft_perror("Error\nFail access to infile\n", px);
	close(fd);
	fd = open(outfile, O_WRONLY);
	if (fd == -1)
		ft_perror("Error\nFail access to outfile\n", px);
	close(fd);
}

// Print a error and exit if this command is call.
// this command is made to exit properly
void	ft_perror(char *s, t_pipex *px)
{
	ft_putstr_fd(s, 1);
	free_px(px);
	exit(EXIT_FAILURE);
}

void	free_cmds(char **cmd1, char **cmd2)
{
	if (cmd1 || *cmd1)
		free_2d(cmd1);
	if (cmd2 || *cmd2)
		free_2d(cmd2);
}

t_pipex	init_pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	t_pipex	px;

	px.cmd1 = ft_split(cmd1, ' ');
	px.cmd2 = ft_split(cmd2, ' ');
	px.infile = infile;
	px.outfile = outfile;
	return (px);
}

void	free_px(t_pipex *px)
{
	if (px->path_cmd1)
		free(px->path_cmd1);
	if (px->path_cmd2)
		free(px->path_cmd2);
}
