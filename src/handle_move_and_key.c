/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move_and_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:04:13 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 17:31:40 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_clctb(t_ctx *ctx);
void	handle_exit(t_ctx *ctx);
void	check_if_enemy(t_ctx *ctx);

t_move	trans_key_to_move(int key)
{
	t_move	move;

	move.dx = 0;
	move.dy = 0;
	if (key == KEY_A || key == KEY_LEFT)
		move.dx = -1;
	else if (key == KEY_D || key == KEY_RIGHT)
		move.dx = 1;
	else if (key == KEY_W || key == KEY_UP)
		move.dy = -1;
	else if (key == KEY_S || key == KEY_DOWN)
		move.dy = 1;
	return (move);
}

bool	is_movable(t_move move, t_ctx *ctx, bool is_player)
{
	int	new_x;
	int	new_y;

	if (is_player)
	{
		new_x = ctx->player.x + move.dx;
		new_y = ctx->player.y + move.dy;
		if (ctx->map_data.map[new_y][new_x] == '1')
			return (false);
	}
	else
	{
		new_x = ctx->enemy.x + move.dx;
		new_y = ctx->enemy.y + move.dy;
		if (ctx->map_data.map[new_y][new_x] != '0')
			return (false);
	}
	return (true);
}

void	to_move(t_move move, t_ctx *ctx)
{
	// if (is_player)
	// {
	ctx->player.x += move.dx;
	ctx->player.y += move.dy;
	update_clctb(ctx);
	++ctx->stps;
	// }
	// else
	// {
	// 	ctx->enemy.x += move.dx;
	// 	ctx->enemy.y += move.dy;
	// }
}


int	handle_key(int keycode, void *prm)
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
	print_steps(ctx, false);
	handle_exit(ctx);
	render_map(ctx);
	draw_player(ctx);
	return (0);
}
