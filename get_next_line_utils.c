/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:51:55 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/26 21:59:18 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

int	find_newline(char *str)
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

/*
int	main(void)
{
	char	*str;

	str = ft_strjoin("", "42");
	printf("%s\n", str);
	free(str);

	str = ft_strjoin("GNL", "");
	printf("%s\n", str);
	free(str);
	return (0);
}
	
int	main(void)
{
	char	*str;

	str = "\n";
	printf("%zu\n", ft_strlen(str));
	return (0);
}
int	main(void)
{
	char	*str;

	str = "abcfgh";
	printf("%d\n", find_newline(str));
	return(0);
}
*/