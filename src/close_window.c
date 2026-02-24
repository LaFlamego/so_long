/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:20 by yueli             #+#    #+#             */
/*   Updated: 2026/02/24 14:51:10 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *prm)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)prm;
	clear_exit(ctx, NULL);
	return (0);
}

int	esc_close(int keycode, void *prm)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)prm;
	if (keycode == 65307)
		clear_exit(ctx, NULL);
	return (0);
}
