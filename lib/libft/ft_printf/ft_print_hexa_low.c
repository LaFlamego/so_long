/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:04:50 by yueli             #+#    #+#             */
/*   Updated: 2025/11/25 16:58:18 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_low(unsigned int n)
{
	unsigned long	digit;
	int				count;

	count = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	else
	{
		if (n >= 16)
			count += ft_print_hexa_low(n / 16);
		digit = n % 16;
		if (digit < 10)
			ft_print_char((char)('0' + digit));
		if (9 < digit && digit < 16)
			ft_print_char((char)('a' + (digit - 10)));
		return (count + 1);
	}
}
