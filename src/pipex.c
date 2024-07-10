/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:17:55 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/10 12:00:11 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipe	*v_pipe;
	int		pid[2];

	v_pipe = NULL;
	arg_checking(argc, argv, envp);
	init_t_pipe(&v_pipe, argv, envp);
	pipe(v_pipe->pipe_fd);
	child_one(v_pipe, argv[1], pid);
	child_two(v_pipe, argv[4], pid);
	close(v_pipe->pipe_fd[0]);
	close(v_pipe->pipe_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	free_t_pipe(v_pipe);
	return (0);
}
