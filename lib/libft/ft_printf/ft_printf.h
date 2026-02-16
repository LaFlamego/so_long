/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftft_printf.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:46:44 by yueli             #+#    #+#             */
/*   Updated: 2025/11/25 16:49:00 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_int(int n);
int	ft_print_string(char *s);
int	ft_print_usint(unsigned int n);
int	ft_print_pointer(void *ptr);
int	ft_print_hexa_low(unsigned int n);
int	ft_print_hexa_upper(unsigned int n);

#endif