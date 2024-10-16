/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:00 by rpisoner          #+#    #+#             */
/*   Updated: 2024/10/16 11:36:56 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	child_one(t_pipe *v_pipe, char *infile_name)
{
	int	infile_fd;
	int	pid;

	pid = fork();
	if (pid < 0)
		free_exit(v_pipe, 1);
	if (pid == 0)
	{
		if (v_pipe->here_doc == 1)
			infile_fd = open("here_doc", O_RDONLY);
		else
			infile_fd = open(infile_name, O_RDONLY);
		if (infile_fd < 0)
			open_error(v_pipe);
		dup2(v_pipe->pipe_fd[1], STDOUT_FILENO);
		dup2(infile_fd, STDIN_FILENO);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		close(infile_fd);
		execve(v_pipe->commands_paths[0], v_pipe->commands_and_flags[0],
			v_pipe->envp);
		perror("Error");
		free_exit(v_pipe, 127);
	}
}

void	middle_child(t_pipe *v_pipe, int i)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		free_exit(v_pipe, 1);
	if (pid == 0)
	{
		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
		dup2(v_pipe->aux_pipe_fd[1], STDOUT_FILENO);
		close (v_pipe->pipe_fd[0]);
		close(v_pipe->aux_pipe_fd[0]);
		close (v_pipe->aux_pipe_fd[1]);
		execve(v_pipe->commands_paths[i], v_pipe->commands_and_flags[i],
			v_pipe->envp);
		perror("Error");
		free_exit(v_pipe, 127);
	}
	waitpid(pid, NULL, 0);
	close(v_pipe->pipe_fd[0]);
	v_pipe->pipe_fd[0] = v_pipe->aux_pipe_fd[0];
	close(v_pipe->aux_pipe_fd[1]);
}

void	child_two(t_pipe *v_pipe, char *outfile_name, int arg_n, int *pid)
{
	int	outfile_fd;

	*pid = fork();
	if (*pid < 0)
		free_exit(v_pipe, 1);
	if (*pid == 0)
	{
		if (v_pipe->here_doc == 1)
			outfile_fd = open(outfile_name, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else
			outfile_fd = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd < 0)
			open_error(v_pipe);
		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
		dup2(outfile_fd, STDOUT_FILENO);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		close(outfile_fd);
		execve(v_pipe->commands_paths[arg_n],
			v_pipe->commands_and_flags[arg_n], v_pipe->envp);
		perror("Error");
		free_exit(v_pipe, 127);
	}
}

void	multi_pipe(t_pipe *v_pipe)
{
	int	i;
	int	arg_n;
	int	lc_pid;
	int	status;

	i = 2;
	arg_n = 0;
	status = 0;
	pipe(v_pipe->pipe_fd);
	child_one(v_pipe, v_pipe->argv[arg_n++]);
	close(v_pipe->pipe_fd[1]);
	while (i < v_pipe->argc - 3)
	{
		if (pipe(v_pipe->aux_pipe_fd) < 0)
			free_exit(v_pipe, 1);
		middle_child(v_pipe, arg_n);
		i++;
		arg_n++;
	}
	if (v_pipe->here_doc == 0)
		child_two(v_pipe, v_pipe->argv[v_pipe->argc - 1], arg_n, &lc_pid);
	else
		child_two(v_pipe, v_pipe->argv[v_pipe->argc - 1], arg_n - 1, &lc_pid);
	waitpid(lc_pid, &status, 0);
	v_pipe->status = WEXITSTATUS(status);
}
