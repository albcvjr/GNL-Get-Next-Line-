/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:51:55 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/23 15:30:51 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>



/*
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*str;

	str = "\n";
	printf("%zu\n", ft_strlen(str));
	return (0);
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

/*
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

int	main(void)
{
	char	*str;

	str = "abcfgh";
	printf("%d\n", find_newline(str));
	return(0);
}
*/