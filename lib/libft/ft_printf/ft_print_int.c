/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:05:34 by yueli             #+#    #+#             */
/*   Updated: 2025/11/25 16:58:02 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <unistd.h>

int	ft_print_char(char c);

int	ft_print_int(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb == 0)
	{
		ft_print_char('0');
		return (1);
	}
	if (nb < 0)
	{
		ft_print_char('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += ft_print_int((int)(nb / 10));
	ft_print_char((char)('0' + (nb % 10)));
	return (count + 1);
}

/*int	main(void)
{
	ft_print_int(102);
	return (0);
}*/
