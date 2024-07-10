/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/10 18:32:03 by rpisoner         ###   ########.fr       */
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
	if (v_pipe->path != NULL)
	{
		free_stuff(v_pipe->path);
		if (v_pipe->p_command_eq_command == 0)
			free(v_pipe->command_path);
		if (v_pipe->p_command_eq_command2 == 0)
			free(v_pipe->command_path2);
	}
	free_stuff(v_pipe->command_and_flags);
	free_stuff(v_pipe->command_and_flags2);
	free(v_pipe);
	v_pipe = NULL;
}
