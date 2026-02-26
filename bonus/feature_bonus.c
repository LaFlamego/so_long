/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feature_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:56:21 by yueli             #+#    #+#             */
/*   Updated: 2026/02/26 11:49:36 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

bool	is_valid_tile_bonus(t_ctx *ctx)
{
	int		i;
	int		j;
	char	**map;
	int		lookup[4];

	ft_bzero(lookup, sizeof(int) * 4);
	map = ctx->map_data.map;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
				&& map[j][i] != 'E' && map[j][i] != 'P' && map[j][i] != 'O')
				return (false);
			tile_check_and_mark(ctx, lookup, i, j);
			++i;
		}
		++j;
	}
	if (lookup[0] != 1 || lookup[1] != 1 || lookup[2] < 1 || lookup[3] > 1)
		return (false);
	return (true);
}

bool	is_valid_map_bonus(t_ctx *ctx)
{
	if (!is_rectangular(ctx->map_data.map))
		error_free_exit("Map is not a rectangular :c", ctx);
	else if (!is_valid_tile_bonus(ctx))
		error_free_exit("Tiles are not valid :c", ctx);
	else if (!is_enclosed(ctx->map_data.map, ctx))
		error_free_exit("Oops! We need right walls!", ctx);
	else if (!is_valid_path(ctx))
		error_free_exit("0 path is good to go :/", ctx);
	return (true);
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
	if (!is_movable(move, ctx))
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
	++ctx->ply_anm.tick;
	if (ctx->ply_anm.tick >= 40)
	{
		ctx->ply_anm.tick = 0;
		++ctx->ply_anm.cur;
		if (ctx->ply_anm.cur >= ctx->ply_anm.frms_count)
			ctx->ply_anm.cur = 0;
		render_map(ctx);
		draw_player(ctx);
		print_steps(ctx, true);
	}
	return (0);
}

void	init_hook_bonus(t_ctx *ctx)
{
	mlx_hook(ctx->grc_data.win, 17, 0, close_window, ctx);
	mlx_key_hook(ctx->grc_data.win, handle_key_bonus, ctx);
	mlx_loop_hook(ctx->grc_data.mlx, anm_loop_bonus, ctx);
}
