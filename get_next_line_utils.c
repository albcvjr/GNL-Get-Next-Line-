/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:51:55 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/28 02:22:15 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	result = malloc(sizeof(char) * (len_s1 + ft_strlen(s2)) + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[i - len_s1])
	{
		result[i] = s2[i - len_s1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	append_to_stash(char **stash, char *buffer)
{
	char	*new_stash;

	new_stash = ft_strjoin(*stash, buffer);
	if (new_stash == NULL)
		return (1);
	free(*stash);
	*stash = new_stash;
	return (0);
}

int	fill_stash(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (1);
	bytes_read = 1;
	while (!find_newline(*stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		if (append_to_stash(stash, buffer) == 1)
			bytes_read = -1;
	}
	free(buffer);
	if (bytes_read < 0)
		return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
