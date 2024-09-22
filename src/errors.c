/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:24 by rpisoner          #+#    #+#             */
/*   Updated: 2024/09/22 16:33:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	arg_checking(int argc, char *argv[])
{
	if (argc != 5 || !argv)
		exit(1);
}

void	free_exit(t_pipe *v_pipe, int errcode)
{
	free_t_pipe(v_pipe);
	exit(errcode);
}

void	open_error(t_pipe *v_pipe)
{
	perror("Error");
	close(v_pipe->pipe_fd[0]);
	close(v_pipe->pipe_fd[1]);
	free_exit(v_pipe, 1);
}
