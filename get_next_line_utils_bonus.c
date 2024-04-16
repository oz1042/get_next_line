/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:03:02 by ryozuno           #+#    #+#             */
/*   Updated: 2024/04/16 08:57:07 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*find_char(char *s, int c)
{
	c = (char)c;
	while (1)
	{
		if (!s)
			return (0);
		if (*s == c)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_str1;
	size_t	len_str2;
	size_t	i;
	char	*result;

	i = 0;
	len_str1 = ft_strlen(s1);
	len_str2 = ft_strlen(s2);
	result = malloc(len_str1 + len_str2 + 1);
	if (result == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		result[len_str1 + i] = s2[i];
		i++;
	}
	result[len_str1 + i] = '\0';
	return (result);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	size_t	size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*reallocate(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		str = ft_strdup(s2);
	else
		str = ft_strjoin(s1, s2);
	free(s1);
	s1 = str;
	return (s1);
}
