/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:57 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 17:51:39 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	
}

int	main(int ac, char **av, char **envp)
{
	check_args(ac, &av, envp);
	pipex(av[1], av[2], av[3], av[4]);
	free(av[2]);
	free(av[3]);
	return (0);
}
