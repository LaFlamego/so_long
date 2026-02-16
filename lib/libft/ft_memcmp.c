/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:50:16 by yueli             #+#    #+#             */
/*   Updated: 2025/11/15 17:15:53 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	char p1[] = "asd";
	char p2[] = "asd";
	
	printf("%d\n", ft_memcmp(p1, p2, 9));
	return 0;
}*/
