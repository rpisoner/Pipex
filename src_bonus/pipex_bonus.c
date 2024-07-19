/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:42:48 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/18 18:24:43 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*v_pipe;

	v_pipe = NULL;
	arg_checking(argc, argv);
	init_t_pipe(&v_pipe, argc, argv, envp);
	if (ft_strcmp("here_doc", argv[1]) == 0)
	{
		//here_doc();
	}
	else
	{
		multi_pipe(v_pipe);
	}
	free_t_pipe(v_pipe);
}
