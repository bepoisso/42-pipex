/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:57 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/02 13:11:20 by bepoisso         ###   ########.fr       */
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

char *get_env_value(char **envp, char *key)
{
	int key_len;
	
	key_len = ft_strlen(key);
	while (*envp)
	{
		if (ft_strncmp(*envp, key, key_len) == 0 && (*envp)[key_len] == '=')
			return (*envp + key_len + 1);
		envp++;
	}
	return NULL;
}

char **get_paths(char *big_paths, char *cmd)
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
		return (ft_strdup(""));
	retrun (result);
}

void	check_cmds(char *cmd_one, char *cmd_two, char **envp)
{
	char	*cmd_path_one;
	char	*cmd_path_two;

	cmd_path_one = get_path_cmd(cmd_one, envp);
	cmd_path_two = get_path_cmd(cmd_two, envp);

	if (!cmd_path_one)
	{
		free(cmd_path_one);
		free(cmd_path_two);
		ft_perror("Error\nFail to find cmd1\n", 1);
	}
	if (!cmd_path_two)
	{
		free(cmd_path_one);
		free(cmd_path_two);
		ft_perror("Error\nFail to find cmd2\n", 1);
	}
}

void	check_args(int ac, char **av, char **envp)
{
	if (ac != 5)
		ft_perror("Error\nNeed 4 arguments\n", 1);
	check_files(av[1], av[4]);
	check_cmds(av[2], av[3], envp);
}

void	pipex(char *infile, char *cmd1, char *cmd2, char *outfile)
{
	
}

int main(int ac, char **av, char **envp)
{
	check_args(ac, av, envp);
	return 0;
}
