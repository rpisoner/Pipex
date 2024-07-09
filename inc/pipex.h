/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:20:17 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/09 11:59:34 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipe
{
	char	**path;
	char	**argv;
	char	**envp;
	char	*command_path;
	char	**command_and_flags;
	char	*command_path2;
	char	**command_and_flags2;
	pid_t	pipe_fd[2];
}	t_pipe;

//PATH_UTILS
char	**search_path(char **envp);
void	command_path(t_pipe *v_pipe, char *command);
void	command_path2(t_pipe *v_pipe, char *command);
//INIT T_PIPE
void	init_t_pipe(t_pipe **v_pipe, char **argv, char **envp);
//COMMANDS
void	child_one(t_pipe *v_pipe, char *infile_name, int *pid);
void	child_two(t_pipe *v_pipe, char *outfile_name, int *pid);
//LIBFT_UTILS
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
//ERRORS
void	arg_checking(int argc, char *argv[]);
void	free_exit(t_pipe *v_pipe, int errcode);
//FREE
void	free_stuff(char **stuff);
void	free_t_pipe(t_pipe *v_pipe);

#endif 