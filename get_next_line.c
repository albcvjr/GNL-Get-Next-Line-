/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:12:28 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/23 20:26:07 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (stash == NULL)
	{
		stash = malloc(1);
		if (stash == NULL)
			return (NULL);
		stash[0] = '\0';
	}
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
