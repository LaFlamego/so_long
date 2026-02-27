/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anm_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:10:09 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 13:35:10 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	enemy_move(t_ctx *ctx)
{
	t_move		move;
	static int	change = 0;

	move.dx = 1;
	move.dy = 0;
	if (is_movable(move, ctx, false))
	{
		if (change == 0)
			to_move(move, ctx, false);
	}
	if (!is_movable(move, ctx, false) || change == 1)
	{
		change = 1;
		move.dx = -1;
		move.dy = 0;
		if (is_movable(move, ctx, false))
			to_move(move, ctx, false);
		else if (change == 1)
			change = 0; 
		else
			return ;
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
	to_move(move, ctx, true);
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
	if (cur_ms - last_ms < 300)
		return (0);
	last_ms = cur_ms;
	++ctx->ply_anm.cur;
	if (ctx->ply_anm.cur >= 4)
		ctx->ply_anm.cur = 0;
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
