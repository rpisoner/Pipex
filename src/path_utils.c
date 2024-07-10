/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:21:27 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/10 18:28:57 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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

void	command_path(t_pipe *v_pipe, char *command)
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
		v_pipe->command_path = command;
	else
		v_pipe->command_path = command_path;
	v_pipe->p_command_eq_command = ft_strchr(command, '/') != 0;
	v_pipe->command_and_flags = command_and_flags;
}

void	command_path2(t_pipe *v_pipe, char *command)
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
		v_pipe->command_path2 = command;
	else
		v_pipe->command_path2 = command_path;
	v_pipe->p_command_eq_command2 = ft_strchr(command, '/') != 0;
	v_pipe->command_and_flags2 = command_and_flags;
}
