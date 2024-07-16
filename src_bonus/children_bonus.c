/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:32:00 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/16 19:35:45 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	print_shit(char **shit)
{
	size_t	i;

	i = 0;
	while (shit[i] != NULL)
	{
		fprintf(stderr, "%s\n", shit[i]);
		i++;
	}
}

void	child_one(t_pipe *v_pipe, char *infile_name)
{
	int	infile_fd;
	int pid;

	pid = fork();
	if (pid < 0)
		free_exit(v_pipe, 5);
	if (pid == 0)
	{
		infile_fd = open(infile_name, O_RDONLY);
		if (infile_fd < 0)
			open_error(v_pipe);
		dup2(infile_fd, STDIN_FILENO);
		dup2(v_pipe->pipe_fd[1], STDOUT_FILENO);
		close(infile_fd);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		execve(v_pipe->commands_paths[0], v_pipe->commands_and_flags[0], v_pipe->envp);
		perror("ERROR");
		free_exit(v_pipe, 2);
	}
}

void	middle_child(t_pipe *v_pipe, int pid, int i)
{
	if (pid < 0)
		free_exit(v_pipe, 6);
	if (pid == 0)
	{
		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
		dup2(v_pipe->aux_pipe_fd[1], STDOUT_FILENO);
		close(v_pipe->aux_pipe_fd[1]);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		//print_shit(v_pipe->commands_and_flags[i]);
		//fprintf(stderr, "%s\n", v_pipe->commands_paths[i]);
		execve(v_pipe->commands_paths[i], v_pipe->commands_and_flags[i], v_pipe->envp);
		perror("MIDDLE");
		free_exit(v_pipe, 3);
	}
}

void	child_two(t_pipe *v_pipe, char *outfile_name)
{
	int	outfile_fd;
	int	pid;

	pid = fork();
	if (pid < 0)
		free_exit(v_pipe, 5);
	if (pid == 0)
	{
		dup2(v_pipe->pipe_fd[0], STDIN_FILENO);
		close(v_pipe->pipe_fd[0]);
		close(v_pipe->pipe_fd[1]);
		outfile_fd = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd < 0)
			free_exit(v_pipe, 7);
		dup2(outfile_fd, STDOUT_FILENO);
		close(outfile_fd);
		print_shit(v_pipe->commands_and_flags[v_pipe->argc - 1]);
		fprintf(stderr, "%s\n", v_pipe->commands_paths[v_pipe->argc - 1]);
		execve(v_pipe->commands_paths[v_pipe->argc - 1], 
				v_pipe->commands_and_flags[v_pipe->argc - 1], v_pipe->envp);
		perror("TWO");
		free_exit(v_pipe, 3);
	}
}

void	multi_pipe(t_pipe *v_pipe)
{
	int	j;
	int pid;

	j = 1;
	pipe(v_pipe->pipe_fd);
	child_one(v_pipe, v_pipe->argv[j]);
	while (v_pipe->argv[j + 2] != NULL)
	{
		pid = fork();
		pipe(v_pipe->aux_pipe_fd);
		v_pipe->aux_pipe_fd[0] = v_pipe->pipe_fd[0];
		middle_child(v_pipe, pid, j);
		j++;
	}
	child_two(v_pipe, v_pipe->argv[v_pipe->argc - 1]);
}