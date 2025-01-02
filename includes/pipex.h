/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:31:38 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 17:55:41 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//________________INCLUDES________________
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

//________________FUINCTIONS________________
	//___________Handle_args___________
void	check_files(char *infile, char *outfile);
char	*get_env_value(char **envp, char *key);
char	**get_paths(char *big_paths, char *cmd);
char	*get_path_cmd(char *cmd, char **envp);
void	check_cmd(char **cmd1, char **envp);
void	check_args(int ac, char ***av, char **envp);

	//___________Utils___________
void	ft_perror(char *s, int error_code);

#endif
