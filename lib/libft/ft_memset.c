/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:41:32 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 19:59:40 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;	

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>

int	main(void)
{
	char	s[] = "cestlavie";
	void	*res = ft_memset(s, 63, 3);

	printf("%s\n", s);
	printf("%p %p\n", (void*)s, res);
	return 0;
}*/
