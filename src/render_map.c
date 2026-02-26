/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:58:00 by yueli             #+#    #+#             */
/*   Updated: 2026/02/26 09:25:36 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mlx_new_img to get off-screen buffer, like a painting palette

#include "../includes/so_long.h"

static void	draw_stuff(char type, size_t x, size_t y, t_ctx *ctx)
{
	mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
		ctx->grc_data.img_floor, x * TILE_SIZE, y * TILE_SIZE);
	if (type == '1')
		mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
			ctx->grc_data.img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (type == 'E')
		mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
			ctx->grc_data.img_exit, x * TILE_SIZE, y * TILE_SIZE);
	else if (type == 'C')
		mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
			ctx->grc_data.img_clctb, x * TILE_SIZE, y * TILE_SIZE);
	else if (type == 'O')
		mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
			ctx->grc_data.img_enemy, x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_player(t_ctx *ctx)
{
	mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
		ctx->ply_anm.frms[ctx->ply_anm.cur], ctx->player.x * TILE_SIZE,
		ctx->player.y * TILE_SIZE);
}

void	render_map(t_ctx *ctx)
{
	char	**map;
	size_t	x;
	size_t	y;

	map = ctx->map_data.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_stuff(map[y][x], x, y, ctx);
			++x;
		}
		++y;
	}
}
