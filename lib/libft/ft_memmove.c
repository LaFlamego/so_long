/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:59:02 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 21:37:36 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dst < s)
	{
		while (i < size)
		{
			dst[i] = s[i];
			i++;
		}
	}
	else
	{
		while (size--)
			dst[size] = s[size];
	}
	return (dst);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s[] = "123456";
	
	memmove(s, s + 2, 3);
	printf("%s\n", s);
	return 0;
}*/
