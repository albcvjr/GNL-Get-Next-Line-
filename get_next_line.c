/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:12:28 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/26 21:49:01 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(1);
		if (stash == NULL)
			return (NULL);
		stash[0] = '\0';
	}
	if (read_to_stash(fd, &stash) != 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}

static int	read_to_stash(int fd, char **stash)
{
	char	*buffer;
	char	*new_stash;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (1);
	bytes_read = 1;
	while (!find_newline(*stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (1);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(*stash, buffer);
		if (new_stash == NULL)
		{
			free(buffer);
			return (1);
		}
		free(*stash);
		*stash = new_stash;
	}
	free(buffer);
	return (0);
}

char	*update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*result;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	len = ft_strlen(stash) - i;
	if (len == 0)
	{
		free(stash);
		return (NULL);
	}
	result = malloc(len + 1);
	if (result == NULL)
	{
		free(stash);
		return (NULL);
	}
	j = 0;
	while (j < len)
	{
		result[j] = stash[i];
		j++;
		i++;
	}
	result[j] = '\0';
	free(stash);
	return (result);
}
