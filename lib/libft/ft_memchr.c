/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:29:40 by yueli             #+#    #+#             */
/*   Updated: 2025/11/15 17:15:59 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "oucou";;
	char	*ptr = ft_memchr(str,'c',8);
	
	printf("%s\n", ptr);
	return 0;
}*/
