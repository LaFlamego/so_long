/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:59:08 by yueli             #+#    #+#             */
/*   Updated: 2025/11/16 17:13:00 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc (size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	size_t n = 5;
	int	*arr = (int *)calloc(n, sizeof(int));
	size_t i = 0;

	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	return 0;
}*/
