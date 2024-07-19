/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:06:47 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/19 09:09:24 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/pipex_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dst;
	s = (const char *)src;
	if (n == 0 || d == s)
		return (dst);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*mem;
	int		length;

	length = ft_strlen(s);
	mem = malloc(length + 1);
	if (mem == 0)
		return (mem);
	ft_memcpy(mem, s, length);
	mem[length] = '\0';
	return (mem);
}
