/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pipe_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:40:10 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/22 13:58:21 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	n_params_cmd(t_pipe *v_pipe)
{
	int	i;
	int	n;

	if (v_pipe->here_doc == 1)
		i = 3;
	else
		i = 2;
	n = 0;
	while (v_pipe->argv[i + 1] != NULL)
	{
		n += ft_countwords(v_pipe->argv[i]);
		i++;
	}
	return (n);
}

void	set_paths_and_flags(t_pipe **v_pipe)
{
	int	i;
	int	j;

	if ((*v_pipe)->here_doc == 1)
		i = 3;
	else
		i = 2;
	j = 0;
	while ((*v_pipe)->argv[i + 1] != NULL)
	{
		if ((*v_pipe)->path == NULL || ((*v_pipe)->argv[i][0] == '\0'))
		{
			(*v_pipe)->commands_paths[j] = ft_strdup((*v_pipe)->argv[i]);
			(*v_pipe)->commands_and_flags[j]
				= ft_split((*v_pipe)->argv[i], ' ');
		}
		else
			command_path(*v_pipe, (*v_pipe)->argv[i], j);
		i++;
		j++;
	}
	(*v_pipe)->commands_paths[j] = NULL;
	(*v_pipe)->commands_and_flags[j] = NULL;
}

void	init_t_pipe(t_pipe **v_pipe, int argc, char **argv, char **envp)
{
	*v_pipe = (t_pipe *)malloc(sizeof(t_pipe));
	(*v_pipe)->argv = argv;
	(*v_pipe)->argc = argc;
	(*v_pipe)->envp = envp;
	(*v_pipe)->path = search_path(envp);
	if (ft_strcmp("here_doc", argv[1]) == 0)
		(*v_pipe)->here_doc = 1;
	else
		(*v_pipe)->here_doc = 0;
	(*v_pipe)->commands_paths = (char **)malloc(sizeof(char *) * (argc - 2));
	(*v_pipe)->commands_and_flags = (char ***)malloc(sizeof(char **)
			* (n_params_cmd(*v_pipe) + 1));
	if (!(*v_pipe) || !(*v_pipe)->commands_paths
		|| !(*v_pipe)->commands_and_flags)
		exit(1);
	set_paths_and_flags(v_pipe);
}
