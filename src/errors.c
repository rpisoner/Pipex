/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:02:24 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/10 12:05:48 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	arg_checking(int argc, char *argv[], char *envp[])
{
	if (!envp[0] || argc != 5 || !argv)
		exit(1);
}

void	free_exit(t_pipe *v_pipe, int errcode)
{
	free_t_pipe(v_pipe);
	exit(errcode);
}
