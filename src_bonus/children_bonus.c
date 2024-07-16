/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:00 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/16 12:02:24 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

// void	child_one(t_pipe *v_pipe, char *infile_name, int *pid)
// {
// 	int	infile_fd;

// 	pid[0] = fork();
// 	if (pid[0] < 0)
// 		free_exit(v_pipe, 5);
// 	if (pid[0] == 0)
// 	{
// 		infile_fd = open(infile_name, O_RDONLY);
// 		if (infile_fd < 0)
// 			open_error(v_pipe);
// 		dup2(infile_fd, STDIN_FILENO);
// 		close(infile_fd);
// 		dup2(v_pipe->pipe_fd[1], STDOUT_FILENO);
// 		close(v_pipe->pipe_fd[0]);
// 		close(v_pipe->pipe_fd[1]);
// 		execve(v_pipe->command_path, v_pipe->command_and_flags, v_pipe->envp);
// 		perror("Error");
// 		free_exit(v_pipe, 2);
// 	}
// }

// void	middle_child(t_pipe *v_pipe, int *pid, int i)
// {
// 	int	middle_child_fd;

// 	pid[i] = fork();
// 	if (pid[i] < 0)
// 		free_exit(v_pipe, 6);
// 	if (pid[i] == 0)
// 	{
// 		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
// 		close(v_pipe->pipe_fd[0]);
// 		close(v_pipe->pipe_fd[1]);
// 		dup2(outfile_fd, STDOUT_FILENO);
// 		close(outfile_fd);
// 		execve(v_pipe->command_path2, v_pipe->command_and_flags2, v_pipe->envp);
// 		perror("Error");
// 		free_exit(v_pipe, 3);
// 	}
// }

// void	child_two(t_pipe *v_pipe, char *outfile_name, int *pid)
// {
// 	int	outfile_fd;

// 	pid[1] = fork();
// 	if (pid[1] < 0)
// 		free_exit(v_pipe, 5);
// 	if (pid[1] == 0)
// 	{
// 		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
// 		close(v_pipe->pipe_fd[0]);
// 		close(v_pipe->pipe_fd[1]);
// 		outfile_fd = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (outfile_fd < 0)
// 			free_exit(v_pipe, 7);
// 		dup2(outfile_fd, STDOUT_FILENO);
// 		close(outfile_fd);
// 		execve(v_pipe->command_path2, v_pipe->command_and_flags2, v_pipe->envp);
// 		perror("Error");
// 		free_exit(v_pipe, 3);
// 	}
// }
