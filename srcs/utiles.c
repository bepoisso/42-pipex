/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:26:00 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 19:49:40 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Print a error and exit if this command is call.
// this command is made to exit properly
void	ft_perror(char *s)
{
	ft_putstr_fd(s, 1);
	exit(EXIT_FAILURE);
}

void	free_cmds(char *cmd1, char *cmd2)
{
	free(cmd1);
	free(cmd2);
}

t_pipex	init_pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	t_pipex	px;

	px.cmd1 = cmd1;
	px.cmd2 = cmd2;
	px.infile = infile;
	px.outfile = outfile;
	px.envp = NULL;
	return (px);
}
