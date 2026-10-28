/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:12:28 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/28 02:18:06 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_stash(int fd, char **stash)
{
	if (*stash == NULL)
	{
		*stash = malloc(1);
		if (*stash == NULL)
			return (1);
		(*stash)[0] = '\0';
	}
	if (fill_stash(fd, stash) == 1)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	if ((*stash)[0] == '\0')
	{
		free(*stash);
		*stash = NULL;
		return (2);
	}
	return (0);
}

static char	*copy_rest(char *stash, size_t i, size_t len)
{
	char	*result;
	size_t	j;

	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		result[j] = stash[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

static int	update_stash(char **stash)
{
	size_t	i;
	size_t	len;
	char	*result;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	len = ft_strlen(*stash) - i;
	result = copy_rest(*stash, i, len);
	if (result == NULL)
	{
		free(*stash);
		*stash = NULL;
		return (1);
	}
	free(*stash);
	*stash = result;
	return (0);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	result = malloc(i + 1);
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = stash[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (init_stash(fd, &stash) != 0)
		return (NULL);
	line = extract_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (update_stash(&stash) == 1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
