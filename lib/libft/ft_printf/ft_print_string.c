/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:02:24 by yueli             #+#    #+#             */
/*   Updated: 2026/01/26 18:55:23 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	count;

	if (!s)
	{
		ft_print_char('(');
		ft_print_char('n');
		ft_print_char('u');
		ft_print_char('l');
		ft_print_char('l');
		ft_print_char(')');
		return (6);
	}
	count = 0;
	while (s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
