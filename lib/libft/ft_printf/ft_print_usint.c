/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:59:38 by yueli             #+#    #+#             */
/*   Updated: 2025/11/25 16:57:40 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_usint(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_usint(n / 10);
	ft_print_char((char)('0' + (n % 10)));
	return (count + 1);
}
