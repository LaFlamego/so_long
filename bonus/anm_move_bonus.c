/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anm_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:10:09 by yueli             #+#    #+#             */
/*   Updated: 2026/02/28 11:27:24 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	update_enemy(t_ctx *ctx, t_move *move)
{
	ctx->map_data.map[ctx->enemy.y][ctx->enemy.x] = '0';
	ctx->enemy.x += move->dx;
	ctx->map_data.map[ctx->enemy.y][ctx->enemy.x] = 'O';
}

static void	enemy_move(t_ctx *ctx)
{
	t_move		move;
	static int	to_left = 0;

	move.dy = 0;
	move.dx = 1;
	if (is_movable(move, ctx, false) && to_left == 0)
	{
		update_enemy(ctx, &move);
		return ;
	}
	if (!is_movable(move, ctx, false) || to_left == 1)
	{
		to_left = 1;
		move.dx = -1;
		if (is_movable(move, ctx, false))
			update_enemy(ctx, &move);
		else
		{
			to_left = 0;
			move.dx = 1;
			if (is_movable(move, ctx, false))
				update_enemy(ctx, &move);
		}
	}
}

int	handle_key_bonus(int keycode, void *prm)
{
	t_move	move;
	t_ctx	*ctx;

	ctx = (t_ctx *)prm;
	if (keycode == KEY_ESC)
		clear_exit(ctx, NULL);
	move = trans_key_to_move(keycode);
	if (move.dx == 0 && move.dy == 0)
		return (0);
	if (!is_movable(move, ctx, true))
		return (0);
	to_move(move, ctx);
	check_if_enemy(ctx);
	handle_exit(ctx);
	render_map(ctx);
	draw_player(ctx);
	print_steps(ctx, true);
	return (0);
}

int	anm_loop_bonus(t_ctx *ctx)
{
	static long		last_ms;
	struct timeval	tv;
	long			cur_ms;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	cur_ms = tv.tv_sec * 1000L + tv.tv_usec / 1000L;
	if (cur_ms - last_ms < 500)
		return (0);
	last_ms = cur_ms;
	++ctx->ply_anm.cur;
	if (ctx->ply_anm.cur >= 4)
		ctx->ply_anm.cur = 0;
	enemy_move(ctx);
	render_map(ctx);
	draw_player(ctx);
	print_steps(ctx, true);
	return (0);
}

void	init_hook_bonus(t_ctx *ctx)
{
	mlx_hook(ctx->grc_data.win, 17, 0, close_window, ctx);
	mlx_key_hook(ctx->grc_data.win, handle_key_bonus, ctx);
	mlx_loop_hook(ctx->grc_data.mlx, anm_loop_bonus, ctx);
}
