/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:31:12 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 21:22:55 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	res = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "123456";
	//char	src[] = "dddc";

	memcpy(dest + 2, dest, 4);
	printf("%s\n", dest);
	return 0;
}*/
