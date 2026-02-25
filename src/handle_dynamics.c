/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dynamics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:28:28 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 23:44:36 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	anm_loop(t_ctx *ctx)
{
	++ctx->ply_anm.tick;
	if (ctx->ply_anm.tick >= 40)
	{
		ctx->ply_anm.tick = 0;
		++ctx->ply_anm.cur;
		if (ctx->ply_anm.cur >= ctx->ply_anm.frms_count)
			ctx->ply_anm.cur = 0;
		render_map(ctx);
		draw_player(ctx);
		print_steps(ctx);
	}
	return (0);
}

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

void	print_steps(t_ctx *ctx)
{
	char	*count;
	char	*str;

	count = ft_itoa(ctx->stps);
	if (!count)
		return ;
	str = ft_strjoin(count, " steps");
	free(count);
	if (!str)
		return ;
	mlx_string_put(ctx->grc_data.mlx, ctx->grc_data.win,
		10, 20, 0xFFFFFF, str);
	free(str);
}

void	check_if_enemy(t_ctx *ctx)
{
	int	x;
	int	y;

	x = ctx->player.x;
	y = ctx->player.y;
	if (ctx->map_data.map[y][x] == 'O')
	{
		ft_printf("Oh no! Shark ate you in your %d steps :c Try again!\n",
	ctx->stps);
		clear_exit(ctx, NULL);
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
		ft_printf("Bravo! You won in %d steps. And now you are full of love <3\n",
			ctx->stps);
		clear_exit(ctx, NULL);
	}
}
