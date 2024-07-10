/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:14:22 by rpisoner          #+#    #+#             */
/*   Updated: 2024/07/10 18:20:29 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(str1 + i) > *(str2 + i))
			return ((int)*(str1 + i) - (int)*(str2 + i));
		else if (*(str1 + i) < *(str2 + i))
			return ((int)*(str1 + i) - (int)*(str2 + i));
		if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (0);
	if (s1)
	{
		while ((char)s1[i] != '\0')
		{
			new[i] = (char)s1[i];
			i++;
		}
	}
	while ((char)s2[j] != '\0')
	{
		new[i] = (char)s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != (char)c)
	{
		if (*(s + i) == '\0')
			return (0);
		i++;
	}
	return ((char *)(s + i));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i])
	{
		if (*(str1 + i) > *(str2 + i))
			return ((int)*(str1 + i) - (int)*(str2 + i));
		else if (*(str1 + i) < *(str2 + i))
			return ((int)*(str1 + i) - (int)*(str2 + i));
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] == '\0')
		return (-(int)s2[i]);
	else
		return ((int)s1[i] - (int)s2[i]);
}
