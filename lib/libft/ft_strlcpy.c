/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:54:33 by yueli             #+#    #+#             */
/*   Updated: 2025/11/15 18:42:33 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *s1, const char *s2, size_t dsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s2);
	if (dsize > 0)
	{
		i = 0;
		while (i + 1 < dsize && s2[i])
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (slen);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	s1[] = "1111111111";
	char	s0[] = "1111111111";
	const char	s2[] = "bonjour";
	

	printf("%zu ", strlcpy(s1, s2, 5));
	printf("%s\n", s1); 
	printf("%zu ", ft_strlcpy(s0, s2, 5));
	printf("%s\n", s0);
	return 0;
}*/