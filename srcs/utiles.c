/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:26:00 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 18:02:34 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Print a error and exit if this command is call.
// this command is made to exit properly
void	ft_perror(char *s, int error_code)
{
	ft_putstr_fd(s, 1);
	exit(error_code);
}
