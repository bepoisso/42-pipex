/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:31:38 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 20:04:27 by bepoisso         ###   ########.fr       */
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
# include <sys/wait.h>


//________________STRUCT________________
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
}	t_pipex;


//________________FUINCTIONS________________
	//___________Handle_args___________
void	check_files(char *infile, char *outfile);
char	*get_env_value(char **envp, char *key);
char	**get_paths(char *big_paths, char *cmd);
char	*get_path_cmd(char *cmd, char **envp);
void	check_cmd(char **cmd1, char **envp);
void	check_args(int ac, char ***av, char **envp);

	//___________Redirect___________
int		open_file(char *file, int *fd, int	flag);
int		redirect_to_fd(int old_fd, int	new_fd);
int		handle_redirect(t_pipex *px);

	//___________Utils___________
void	ft_perror(char *s);
void	free_cmds(char *cmd1, char *cmd2);
t_pipex	init_pipex(char *infile, char *cmd1, char *cmd2, char *outfile);

#endif
