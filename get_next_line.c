/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:01:39 by ryozuno           #+#    #+#             */
/*   Updated: 2024/04/16 05:37:32 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *line)
{
	char	*buff;
	ssize_t	byte;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	byte = 1;
	while (!find_char(line, '\n') && byte > 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buff);
			free(line);
			return (NULL);
		}
		buff[byte] = '\0';
		line = reallocate(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_first_line(char *buff)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save(char *buff)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(buff) - i));
	if (!line)
		return (free(buff), NULL);
	i++;
	while (buff[i])
	{
		line[j++] = buff[i++];
	}
	line[j] = '\0';
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*all_text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_text = read_all(fd, all_text);
	if (!all_text)
		return (NULL);
	line = get_first_line(all_text);
	all_text = save(all_text);
	return (line);
}
