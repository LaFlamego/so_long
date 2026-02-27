/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 16:28:28 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 11:40:03 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	anm_loop(t_ctx *ctx)
{
	static long	last_ms = 0;
	struct timeval	tv;
	long		cur_ms;
	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	cur_ms = tv.tv_sec * 1000L + tv.tv_usec / 1000L;
	if (cur_ms - last_ms < 100)
		return (0);
	last_ms = cur_ms;
	++ctx->ply_anm.cur;
	if (ctx->ply_anm.cur >= 4)
		ctx->ply_anm.cur = 0;
	render_map(ctx);
	draw_player(ctx);
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

void	print_steps(t_ctx *ctx, bool is_bonus)
{
	char	*count;
	char	*str;

	if (!is_bonus)
		ft_printf("steps: %d\n", ctx->stps);
	else
	{
		count = ft_itoa(ctx->stps);
		if (!count)
			return ;
		str = ft_strjoin(count, " steps");
		free(count);
		if (!str)
			return ;
		mlx_string_put(ctx->grc_data.mlx, ctx->grc_data.win,
			10, 33, 0xFFFFFF, str);
		free(str);
	}
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
		ft_printf("Bravo! You won in %d steps.", ctx->stps);
		ft_printf(" And now you are full of love <3\n");
		clear_exit(ctx, NULL);
	}
}
