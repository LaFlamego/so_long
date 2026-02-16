/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:44:02 by yueli             #+#    #+#             */
/*   Updated: 2025/11/25 16:57:57 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <unistd.h>

int	ft_print_char(char c);
/*{
	write (1, &c, 1);
}*/

int	to_hexa(unsigned long adrs)
{
	unsigned long	digit;
	int				count;

	count = 0;
	if (adrs == 0)
	{
		ft_print_char('0');
		return (1);
	}
	else
	{
		if (adrs >= 16)
			count += to_hexa(adrs / 16);
		digit = adrs % 16;
		if (digit < 10)
			ft_print_char((char)('0' + digit));
		if (9 < digit && digit < 16)
			ft_print_char((char)('a' + (digit - 10)));
		return (count + 1);
	}
}

int	ft_print_pointer(void *ptr)
{
	void			*null;
	unsigned long	adrs;

	null = (void *)0;
	if (ptr == null)
	{
		ft_print_char('(');
		ft_print_char('n');
		ft_print_char('i');
		ft_print_char('l');
		ft_print_char(')');
		return (5);
	}
	else
	{
		adrs = (unsigned long)ptr;
		ft_print_char('0');
		ft_print_char('x');
		return (to_hexa(adrs) + 2);
	}
}

/*int	main(void)
{
	void	*ptr = ((void *)15);

	ft_print_pointer(ptr);
}*/

/*int	main(void)
{
	to_hexa(15);
	return (0);
}*/
