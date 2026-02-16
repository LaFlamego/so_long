/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:30:22 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 19:59:57 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i++] = 0;
	}
}

/*#include <strings.h>
#include <stdio.h>

int	main(void)
{
	char	s[] = "cestlavie";
	ft_bzero(s, 3);

	printf("%s\n", s);
}*/
