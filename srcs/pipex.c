/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:57 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/23 17:12:20 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	px;

	if (ac != 5)
	{
		ft_putstr_fd("Error\nNeed 4 arguments\n", 1);
		exit(1);
	}
	ft_bzero(&px, sizeof(t_pipex));
	px = init_pipex(av[1], av[2], av[3], av[4]);
	px.envp = envp;
	check_args(&av, envp, &px);
	px.path_cmd1 = av[2];
	px.path_cmd2 = av[3];
	pipex(&px);
	free_2d(px.cmd1);
	free_2d(px.cmd2);
	free_px(&px);
	return (0);
}
