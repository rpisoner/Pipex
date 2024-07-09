/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:04:22 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/09 10:54:42 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:04:26 by rpisoner          #+#    #+#             */
/*   Updated: 2023/09/25 15:40:57 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;

	i = 0;
	if (len > ((unsigned int)ft_strlen(s)) - start)
		len = ((unsigned int)ft_strlen(s)) - start;
	if (start > ft_strlen(s))
		return ("");
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (i < len && *(s + i) != '\0')
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return (substr);
}

static int	ft_wc(char const *s, char c)
{
	int		contador;
	size_t	i;

	i = 0;
	contador = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			contador++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (contador);
}

static char	*n_word(char const *s, char c, int i)
{
	char	*new;
	int		st;
	int		l;
	int		j;

	st = 0;
	l = 0;
	j = 0;
	while (s[l])
	{
		while (s[st] == c)
			st++;
		l = st;
		while (s[l] && s[l] != c)
			l++;
		if (i == j)
		{
			new = ft_substr(s, st, l - st);
			return (new);
		}
		j++;
		st = l;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	strs = malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (ft_wc(s, c) > i)
	{
		strs[i] = n_word(s, c, i);
		if (strs[i] == NULL)
		{
			while (i-- > 0)
				free(strs[i]);
			free(strs);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
