/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_clctb_and_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:28:28 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 17:34:39 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_clctb(t_ctx *ctx)
{
	int	x;
	int	y;

	x = ctx->player.x;
	y = ctx->player.y;
	if (ctx->map_data.map[y][x] == 'C')
	{
		ctx->map_data.map[y][x] = '0';
		--ctx->clctbs;
	}
}

void	handle_exit(t_ctx *ctx)
{
	int	x;
	int	y;

	x = ctx->player.x;
	y = ctx->player.y;
	if (ctx->map_data.map[y][x] == 'E' && ctx->clctbs == 0)
	{
		ft_printf("You won in %d steps!\nAnd now you are full of love <3\n",
			ctx->stps);
		clear_exit(ctx, NULL);
	}
}
