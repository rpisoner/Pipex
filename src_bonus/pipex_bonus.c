/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:42:48 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 20:27:46 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*v_pipe;
	int		status;

	v_pipe = NULL;
	arg_checking(argc, argv);
	init_t_pipe(&v_pipe, argc, argv, envp);
	if (v_pipe->here_doc == 1)
		here_doc(argv[2]);
	multi_pipe(v_pipe);
	if (v_pipe->here_doc == 1)
		unlink("here_doc");
	status = v_pipe->status;
	free_t_pipe(v_pipe);
	exit(status);
}
