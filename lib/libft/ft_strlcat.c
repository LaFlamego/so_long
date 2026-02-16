/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:42:37 by yueli             #+#    #+#             */
/*   Updated: 2025/11/15 17:40:34 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(s1);
	slen = 0;
	while (s2[slen])
		slen++;
	if (dsize <= dlen)
		return (dsize + slen);
	i = 0;
	while (s2[i] && (i + dlen) < dsize - 1)
	{
		s1[i + dlen] = s2[i];
		i++;
	}
	s1[i + dlen] = '\0';
	return (dlen + slen);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "1111";
	const char s2[] = "222222";
	size_t res = ft_strlcat(s1, s2, 8);

	printf("%s\n", s1);
	printf("%zu\n", res);
	return (0);
}*/
