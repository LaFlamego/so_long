/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:18:32 by yueli             #+#    #+#             */
/*   Updated: 2026/01/20 20:35:25 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char((char)va_arg(args, int)));
	if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_usint(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_hexa_low(va_arg(args, int)));
	if (c == 'X')
		return (ft_print_hexa_upper(va_arg(args, int)));
	if (c == '%')
		return (ft_print_char('%'));
	else
	{
		ft_print_char('%');
		ft_print_char(c);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_print_char(format[i]);
			count++;
		}
		else
		{
			count += handle_format(format[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	int a;
// 	int b;
// 	char	*str = NULL;
// 	char	*p = 0;
// 	a = printf("%s", str);
// 	b = ft_printf("%s", str);

// 	printf("%d\n", a);
// 	ft_printf("%d\n", b);

// 	a = printf("%p", p);
// 	b = ft_printf("%p", p);

// 	printf("%d\n", a);
// 	ft_printf("%d\n", b);

// 	printf("hello %k world\n");
// 	ft_printf("hello %k world\n");
// 	return 0;
// }
