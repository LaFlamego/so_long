/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:48:02 by yueli             #+#    #+#             */
/*   Updated: 2026/01/23 17:12:53 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	if (*lit == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == lit[j] && (i + j) < len)
		{
			if (lit[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	big[] = "HOME=/user/bin/path";
// 	char	lit[] = "PATH";
// 	const char *b = (const char *)big;
// 	const char *l = (const char *)lit;

// 	printf("%s\n", ft_strnstr(b, l, 4));
// 	return 0;
// }
