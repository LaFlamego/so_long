/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:28:51 by yueli             #+#    #+#             */
/*   Updated: 2026/02/17 17:40:11 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

size_t	ft_strnb(char **strs)
{
	size_t	nb;

	nb = 0;
	while (*strs)
	{
		++strs;
		++nb;
	}
	return (nb);
}

// int main(void)
// {
//     char *map[] = {"11111", "11111", "10000", "10000", "10000", NULL};

//     printf("%zu\n", ft_strnb(map));
//     return 0;
// }
