/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuevas <acuevas@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:51:55 by acuevas           #+#    #+#             */
/*   Updated: 2026/10/23 13:47:15 by acuevas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = "abcfgh";
	printf("%d\n", find_newline(str));
	return(0);
}