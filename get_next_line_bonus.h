/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:02:31 by ryozuno           #+#    #+#             */
/*   Updated: 2024/04/16 04:14:18 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

size_t	ft_strlen(char *a);
char	*get_next_line(int fd);
char	*find_char(char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*reallocate(char *s1, char *s2);

#endif
