/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/22 14:06:43 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	if (v_pipe->command_path != NULL && v_pipe->command_path[0] != '\0')
		free(v_pipe->command_path);
	if (v_pipe->command_path != NULL && v_pipe->command_path2[0] != '\0')
		free(v_pipe->command_path2);
	if (v_pipe->path != NULL)
		free_stuff(v_pipe->path);
	free_stuff(v_pipe->command_and_flags);
	free_stuff(v_pipe->command_and_flags2);
	free(v_pipe);
	v_pipe = NULL;
}
