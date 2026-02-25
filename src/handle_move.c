/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:04:13 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 17:47:53 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

bool	is_movable(t_move move, t_ctx *ctx)
{
	int	new_x;
	int	new_y;

	new_x = ctx->player.x + move.dx;
	new_y = ctx->player.y + move.dy;
	if (ctx->map_data.map[new_y][new_x] == '1')
		return (false);
	return (true);
}

void	to_move(t_move move, t_ctx *ctx)
{
	ctx->player.x += move.dx;
	ctx->player.y += move.dy;
	++ctx->stps;
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
	if (!is_movable(move, ctx))
		return (0);
	to_move(move, ctx);
	render_map(ctx);
	draw_player(ctx);
	return (0);
}
