/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:23:58 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 20:50:24 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	here_doc(char *limiter)
{
	char	*text;
	char	*complete_limiter;
	int		here_doc_fd;

	here_doc_fd = open("here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (here_doc_fd < 0)
		exit (1);
	complete_limiter = ft_strjoin(limiter, "\n");
	while (1)
	{
		write (1, "here_doc>", 9);
		text = get_next_line(0);
		if (text == NULL || ft_strcmp(complete_limiter, text) == 0)
			break ;
		write(here_doc_fd, text, ft_strlen(text));
		free (text);
	}
	if (text != NULL)
		free (text);
	close(here_doc_fd);
	free(complete_limiter);
}
