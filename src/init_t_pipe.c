/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:40:10 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/22 14:03:49 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_t_pipe(t_pipe **v_pipe, char **argv, char **envp)
{
	*v_pipe = (t_pipe *)malloc(sizeof(t_pipe));
	(*v_pipe)->argv = argv;
	(*v_pipe)->envp = envp;
	(*v_pipe)->path = search_path(envp);
	if ((*v_pipe)->path == NULL || (argv[2][0] == '\0'))
	{
		(*v_pipe)->command_path = ft_strdup(argv[2]);
		(*v_pipe)->command_and_flags = ft_split(argv[2], ' ');
	}
	else
		command_path(*v_pipe, argv[2]);
	if ((*v_pipe)->path == NULL || argv[3][0] == '\0')
	{
		(*v_pipe)->command_path2 = ft_strdup(argv[3]);
		(*v_pipe)->command_and_flags2 = ft_split(argv[3], ' ');
	}
	else
		command_path2(*v_pipe, argv[3]);
}
