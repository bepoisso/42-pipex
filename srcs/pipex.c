/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:57 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 11:51:31 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_files(char *infile, char *outfile)
{
	int	fd;

	if (access(infile, R_OK) == -1)
		ft_perror("Error\nFail access to infile", 1);
	fd = open(outfile, O_WRONLY);
	if (!fd)
		ft_perror("Error\nFail access to outfile", 1);
	close(fd);
}

void	check_cmds(char *cmd1, char *cmd2, char **envp)
{
	// Check si les commandes existe.
		// si on renvois un message d'error
	
}

void	check_args(int ac, char **av, char **envp)
{
	// Essayer d'ouvrir les fichier
	if (ac != 5)
		ft_perror("Error\nNeed 4 arguments\n", 1);
	check_files(av[1], av[4]);
	check_cmds(av[2], av[3], envp);
}

int main(int ac, char **av, char **envp)
{
	check_args(ac, av, envp);
	return 0;
}
