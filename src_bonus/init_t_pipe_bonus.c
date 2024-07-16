/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_pipe_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:40:10 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/16 15:19:30 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	n_params_cmd(t_pipe *v_pipe)
{
	int	i;
	int	n;

	i = 2;
	n = 0;
	while (v_pipe->argv[i + 1] != NULL)
	{
		n += ft_countwords(v_pipe->argv[i]);
		i++;
	}
	return (n);
}

void	init_t_pipe(t_pipe **v_pipe, int argc, char **argv, char **envp)
{
	int	i;
	int j;

	i = 2;
	j = 0;
	*v_pipe = (t_pipe *)malloc(sizeof(t_pipe));
	(*v_pipe)->argv = argv;
	(*v_pipe)->argc = argc;
	(*v_pipe)->envp = envp;
	(*v_pipe)->path = search_path(envp);
	(*v_pipe)->commands_paths = (char **)malloc(sizeof(char *) * (argc - 3));
	(*v_pipe)->commands_and_flags = (char ***)malloc(sizeof(char **)
			* n_params_cmd(*v_pipe));
	if (!(*v_pipe) || !(*v_pipe)->commands_paths || !(*v_pipe)->commands_and_flags)
		exit(1);
	while (argv[i + 1] != NULL)
	{
		if ((*v_pipe)->path == NULL || (argv[i][0] == '\0'))
		{
			(*v_pipe)->commands_paths[j] = argv[i];
			(*v_pipe)->commands_and_flags[j] = ft_split(argv[i], ' ');
		}
		else
			command_path(*v_pipe, argv[i], j);
		i++;
		j++;
	}
	(*v_pipe)->commands_paths[j] = NULL;
	(*v_pipe)->commands_and_flags[j] = NULL;
}
