/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 01:57:29 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/13 01:57:30 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	make_input(const char *content)
{
	char	path[32];
	int		fd;
	size_t	len;

	strcpy(path, "/tmp/gnl_normal_XXXXXX");
	fd = mkstemp(path);
	if (fd < 0)
		return (-1);
	unlink(path);
	len = strlen(content);
	if (write(fd, content, len) != (ssize_t)len || lseek(fd, 0, SEEK_SET) < 0)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

static int	check_line(int fd, const char *expected)
{
	char	*line;
	int		ok;

	line = get_next_line(fd);
	if (expected == NULL)
		ok = (line == NULL);
	else
		ok = (line != NULL && strcmp(line, expected) == 0);
	free(line);
	return (ok);
}

static int	test_lines(void)
{
	int	fd;
	int	ok;

	fd = make_input("\nfirst line\n\nlast line");
	if (fd < 0)
		return (1);
	ok = check_line(fd, "\n");
	ok &= check_line(fd, "first line\n");
	ok &= check_line(fd, "\n");
	ok &= check_line(fd, "last line");
	ok &= check_line(fd, NULL);
	ok &= check_line(fd, NULL);
	close(fd);
	return (ok);
}

static int	test_empty(void)
{
	int	fd;

	fd = make_input("");
	if (fd < 0)
		return (0);
	if (!check_line(fd, NULL))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(void)
{
	if (!test_lines() || !test_empty() || !check_line(-1, NULL))
	{
		fprintf(stderr, "GNL normal: FAIL\n");
		return (1);
	}
	printf("GNL normal: PASS\n");
	return (0);
}
