/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:00 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/09 12:06:03 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_one(t_pipe *v_pipe, char *infile_name, int *pid)
{
	int	infile_fd;

	pid[0] = fork();
	if (pid[0] < 0)
		free_exit(v_pipe, 5);
	if (pid[0] == 0)
	{
		infile_fd = open(infile_name, O_RDONLY);
		if (infile_fd < 0)
			free_exit(v_pipe, 6);
		dup2(infile_fd, STDIN_FILENO);
		dup2(v_pipe->pipe_fd[1], STDOUT_FILENO);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		if (execve(v_pipe->command_path, v_pipe->command_and_flags,
				v_pipe->envp) == -1)
		{
			perror("FATAL");
			exit(2);
		}
	}
}

void	child_two(t_pipe *v_pipe, char *outfile_name, int *pid)
{
	int	outfile_fd;

	pid[1] = fork();
	if (pid[1] < 0)
		free_exit(v_pipe, 5);
	if (pid[1] == 0)
	{
		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		outfile_fd = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd < 0)
			free_exit(v_pipe, 7);
		dup2(outfile_fd, STDOUT_FILENO);
		if (execve(v_pipe->command_path2, v_pipe->command_and_flags2,
				v_pipe->envp) == -1)
		{
			perror("MAL");
			exit(3);
		}
		close(outfile_fd);
	}
}
