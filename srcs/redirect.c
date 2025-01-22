/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:06:51 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/22 07:45:18 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file, int *fd, int flag)
{
	*fd = open(file, flag);
	if (*fd == -1)
	{
		ft_putstr_fd("Error\nOpen infile\n", 1);
		return (1);
	}
	return (0);
}

int	redirect_to_fd(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) < 0)
	{
		close(old_fd);
		ft_putstr_fd("Error\nFail to redirect\n", 1);
		return (1);
	}
	return (0);
}

int	handle_redirect(t_pipex *px)
{
	int	in_fd;
	int	out_fd;

	if (open_file(px->infile, &in_fd, O_RDONLY))
		return (1);
	if (open_file(px->outfile, &out_fd, O_WRONLY | O_TRUNC))
	{
		close(in_fd);
		return (1);
	}
	if (redirect_to_fd(in_fd, STDIN_FILENO))
	{
		close(out_fd);
		return (1);
	}
	if (redirect_to_fd(out_fd, STDOUT_FILENO))
	{
		close(in_fd);
		return (1);
	}
	close(in_fd);
	close(out_fd);
	return (0);
}
