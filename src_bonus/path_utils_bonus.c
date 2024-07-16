/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:40:10 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/15 18:04:34 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

char	**search_path(char **envp)
{
	char	**path;
	size_t	i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_split(envp[i] + 5, ':');
		i++;
	}
	return (path);
}

void	set_command_free(t_pipe *v_pipe, char *cmd, char *command_path, int j)
{
	v_pipe->commands_paths[j] = cmd;
	free(command_path);
}

void	command_path(t_pipe *v_pipe, char *command, int j)
{
	size_t	i;
	char	*slash_join;
	char	**command_and_flags;
	char	*command_path;

	i = 0;
	command_and_flags = ft_split(command, ' ');
	slash_join = ft_strjoin(v_pipe->path[i], "/");
	command_path = ft_strjoin(slash_join, command_and_flags[0]);
	free(slash_join);
	while (v_pipe->path[i] != NULL && access(command_path, X_OK) != 0)
	{
		i++;
		free(command_path);
		slash_join = ft_strjoin(v_pipe->path[i], "/");
		command_path = ft_strjoin(slash_join, command_and_flags[0]);
		free(slash_join);
	}
	if (ft_strchr(command, '/') != 0)
		set_command_free(v_pipe, command, command_path, j);
	else
		v_pipe->commands_paths[j] = command_path;
	v_pipe->commands_and_flags[j] = command_and_flags;
}
