/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:24 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 17:40:54 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	arg_checking(int argc, char *argv[])
{
	if ((argc < 5 || !argv)
		|| (ft_strcmp("here_doc", argv[1]) == 0 && argc < 6))
		exit(1);
}

void	free_exit(t_pipe *v_pipe, int errcode)
{
	free_t_pipe(v_pipe);
	v_pipe = NULL;
	exit(errcode);
}

void	open_error(t_pipe *v_pipe)
{
	perror("Error");
	close(v_pipe->pipe_fd[0]);
	close(v_pipe->pipe_fd[1]);
	free_exit(v_pipe, 6);
}
