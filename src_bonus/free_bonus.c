/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 20:39:14 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	free_stuff(char **stuff)
{
	size_t	i;

	i = 0;
	while (stuff[i] != NULL)
	{
		free(stuff[i]);
		stuff[i] = NULL;
		i++;
	}
	free(stuff);
	stuff = NULL;
}

void	free_t_pipe(t_pipe *v_pipe)
{
	int	i;

	i = 0;
	while (v_pipe->commands_and_flags[i] != NULL)
	{
		free_stuff(v_pipe->commands_and_flags[i]);
		v_pipe->commands_and_flags[i] = NULL;
		i++;
	}
	free(v_pipe->commands_and_flags);
	i = 0;
	while (v_pipe->commands_paths[i] != NULL)
	{
		free(v_pipe->commands_paths[i]);
		v_pipe->commands_paths[i] = NULL;
		i++;
	}
	free(v_pipe->commands_paths);
	if (v_pipe->path != NULL)
		free_stuff(v_pipe->path);
	if (v_pipe)
		free(v_pipe);
	v_pipe = NULL;
}
