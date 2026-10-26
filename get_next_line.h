/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:40:12 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/26 21:48:28 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		find_newline(char *str);
char	*extract_line(char *stash);

#endif