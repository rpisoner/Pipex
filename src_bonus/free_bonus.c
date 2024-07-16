/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/16 16:01:07 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	free_stuff(char **stuff)
{
	size_t	i;

	i = 0;
	while (stuff[i])
	{
		free(stuff[i]);
		i++;
	}
	if (stuff)
		free(stuff);
}

void	free_t_pipe(t_pipe *v_pipe)
{
	int	i;

	i = 0;
	while (v_pipe->commands_and_flags[i] != NULL)
	{
		if (v_pipe->path != NULL && (v_pipe->argv[i][0] != '\0'))
			free_stuff(v_pipe->commands_and_flags[i]);
		i++;
	}
	free(v_pipe->commands_and_flags);
	i = 0;
	while (v_pipe->commands_paths[i] != NULL)
	{
		if (v_pipe->path != NULL && (v_pipe->argv[i][0] != '\0'))
			free(v_pipe->commands_paths[i]);
		i++;
	}
	free(v_pipe->commands_paths);
 	if (v_pipe->path != NULL)
 		free_stuff(v_pipe->path);
 	free(v_pipe);
 	v_pipe = NULL;
}
