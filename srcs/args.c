/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:49:06 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/23 17:08:38 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// Get the correct line of envp with the key_word (char *key)
char	*get_env_value(char **envp, char *key)
{
	int	key_len;

	key_len = ft_strlen(key);
	while (*envp)
	{
		if (ft_strncmp(*envp, key, key_len) == 0 && (*envp)[key_len] == '=')
			return (*envp + key_len + 1);
		envp++;
	}
	return (NULL);
}

// Split the paths into tab of char with all path and add '/' and the command
char	**get_paths(char *big_paths, char *cmd)
{
	char	**splited_path;
	char	*temp;
	int		i;

	splited_path = ft_split(big_paths, ':');
	i = 0;
	while (splited_path[i])
	{
		temp = ft_strjoin(splited_path[i], "/");
		free(splited_path[i]);
		splited_path[i] = ft_strjoin(temp, cmd);
		free(temp);
		i++;
	}
	return (splited_path);
}

// Check what paths is correct and have right access
char	*get_path_cmd(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*result;
	char	**temp;

	i = 0;
	temp = ft_split(cmd, ' ');
	paths = get_paths(get_env_value(envp, "PATH"), temp[0]);
	result = NULL;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			result = ft_strdup(paths[i]);
			break ;
		}
		else
			i++;
	}
	free_2d(paths);
	free_2d(temp);
	if (!result)
		return (NULL);
	return (result);
}

// Check if the path is good if not put error
void	check_cmd(char **cmd1, char **envp, t_pipex *px)
{
	char	*cmd_path;

	cmd_path = get_path_cmd(*cmd1, envp);
	if (cmd_path == NULL)
		ft_perror("Error\nFail to find cmd1\n", px);
	*cmd1 = cmd_path;
}

// Check if all arg are valide
void	check_args(int ac, char ***av, char **envp, t_pipex *px)
{
	if (ac != 5)
		ft_perror("Error\nNeed 4 arguments\n", px);
	check_files((*av)[1], (*av)[4], px);
	if (access((*av)[2], X_OK) != 0)
		check_cmd(&(*av)[2], envp, px);
	if (access((*av)[3], X_OK) != 0)
		check_cmd(&(*av)[3], envp, px);
}
