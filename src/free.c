/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/09 10:33:45 by rpisoner         ###   ########.fr       */
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
	free(stuff);
}

void	free_t_pipe(t_pipe *v_pipe)
{
	free_stuff(v_pipe->path);
	free(v_pipe->command_path);
	free(v_pipe->command_path2);
	free_stuff(v_pipe->command_and_flags);
	free_stuff(v_pipe->command_and_flags2);
	free(v_pipe);
	v_pipe = NULL;
}
