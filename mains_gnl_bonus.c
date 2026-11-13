/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains_gnl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 01:57:29 by acuevas           #+#    #+#             */
/*   Updated: 2026/11/13 01:57:30 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	make_input(const char *content)
{
	char	path[32];
	int		fd;
	size_t	len;

	strcpy(path, "/tmp/gnl_bonus_XXXXXX");
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

	line = get_next_line_bonus(fd);
	if (expected == NULL)
		ok = (line == NULL);
	else
		ok = (line != NULL && strcmp(line, expected) == 0);
	free(line);
	return (ok);
}

static int	test_interleaved(void)
{
	int	fd_a;
	int	fd_b;
	int	ok;

	fd_a = make_input("A1\nA2");
	fd_b = make_input("B1\n\nB3\n");
	if (fd_a < 0 || fd_b < 0)
	{
		if (fd_a >= 0)
			close(fd_a);
		if (fd_b >= 0)
			close(fd_b);
		return (0);
	}
	ok = check_line(fd_a, "A1\n");
	ok &= check_line(fd_b, "B1\n");
	ok &= check_line(fd_a, "A2");
	ok &= check_line(fd_b, "\n");
	ok &= check_line(fd_a, NULL);
	ok &= check_line(fd_b, "B3\n");
	ok &= check_line(fd_b, NULL);
	ok &= check_line(fd_b, NULL);
	close(fd_a);
	close(fd_b);
	return (ok);
}

static int	test_empty(void)
{
	int	fd;
	int	ok;

	fd = make_input("");
	if (fd < 0)
		return (0);
	ok = check_line(fd, NULL);
	close(fd);
	return (ok);
}

int	main(void)
{
	if (!test_interleaved() || !test_empty() || !check_line(-1, NULL))
	{
		fprintf(stderr, "GNL bonus: FAIL\n");
		return (1);
	}
	printf("GNL bonus: PASS\n");
	return (0);
}
