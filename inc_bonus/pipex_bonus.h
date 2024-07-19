/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:20:17 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 20:51:47 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_pipe
{
	char	**path;
	char	**argv;
	int		argc;
	char	**envp;
	char	**commands_paths;
	char	***commands_and_flags;
	int		pipe_fd[2];
	int		aux_pipe_fd[2];
	int		here_doc;
	int		status;
}	t_pipe;

//PATH_UTILS
char	**search_path(char **envp);
void	command_path(t_pipe *v_pipe, char *command, int j);
//INIT T_PIPE
void	init_t_pipe(t_pipe **v_pipe, int argc, char **argv, char **envp);
void	multi_pipe(t_pipe *v_pipe);
//LIBFT_UTILS
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_countwords(char const *s);
char	*ft_strdup(const char *s);
//HERE_DOC
void	here_doc(char *limiter);
//ERRORS
void	arg_checking(int argc, char *argv[]);
void	free_exit(t_pipe *v_pipe, int errcode);
void	open_error(t_pipe *v_pipe);
//FREE
void	free_stuff(char **stuff);
void	free_t_pipe(t_pipe *v_pipe);
//GET_NEXT_LINE
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif 