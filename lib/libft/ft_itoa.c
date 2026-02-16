/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:07:14 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 18:53:44 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*res;

	nb = n;
	len = get_len((long)n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
