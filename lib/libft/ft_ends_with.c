/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:44:29 by yueli             #+#    #+#             */
/*   Updated: 2026/02/20 13:33:56 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if ends with it, return 0, else 1

//#include <stddef.h>

// int	ft_strncmp(const char *s1, const char *s2, size_t n);
// size_t	ft_strlen(const char *str);

//#include <stdio.h>
#include "libft.h"

int	ft_ends_with(char *str, char *ends)
{
	size_t	ends_len;
	char	*tpr;

	if (!str || !ends)
		return (1);
	ends_len = ft_strlen(ends);
	while (*str)
		++str;
	tpr = str - ends_len;
	if (ft_strncmp(tpr, ends, ends_len) != 0)
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     printf("%d\n", ft_ends_with("  sad", NULL));
//     return 0;
// }
