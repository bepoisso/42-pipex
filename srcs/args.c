/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:49:06 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 17:51:07 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_files(char *infile, char *outfile)
{
	int	fd;

	if (access(infile, R_OK) == -1)
		ft_perror("Error\nFail access to infile\n", 1);
	fd = open(outfile, O_WRONLY);
	if (fd == -1)
		ft_perror("Error\nFail access to outfile\n", 1);
	close(fd);
}

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

char	*get_path_cmd(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*result;

	i = 0;
	paths = get_paths(get_env_value(envp, "PATH"), cmd);
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
	if (!result)
		return (NULL);
	return (result);
}

void	check_cmd(char **cmd1, char **envp)
{
	char	*cmd_path;

	cmd_path = get_path_cmd(*cmd1, envp);
	if (cmd_path == NULL)
		ft_perror("Error\nFail to find cmd1\n", 1);
	*cmd1 = cmd_path;
}

void	check_args(int ac, char ***av, char **envp)
{
	char	*temp;

	if (ac != 5)
		ft_perror("Error\nNeed 4 arguments\n", 1);
	check_files((*av)[1], (*av)[4]);
	if (access((*av)[2], X_OK) != 0)
		check_cmd(&(*av)[2], envp);
	else
	{
		temp = (*av)[2];
		(*av)[2] = ft_strdup(temp);
	}
	if (access((*av)[3], X_OK) != 0)
		check_cmd(&(*av)[3], envp);
	else
	{
		temp = (*av)[3];
		(*av)[3] = ft_strdup(temp);
	}
}
