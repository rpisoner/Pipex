/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:40:28 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/16 12:02:07 by rpisoner         ###   ########.fr       */
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

// void	free_t_pipe(t_pipe *v_pipe)
// {
// 	if (v_pipe->path != NULL && v_pipe->commands_paths[0][0] != '\0')
// 		free_stuff(v_pipe->commands_paths);
// 	if (v_pipe->path != NULL)
// 		free_stuff(v_pipe->path);
// 	free_stuff(v_pipe->commands_paths);
// 	free(v_pipe);
// 	v_pipe = NULL;
// }
