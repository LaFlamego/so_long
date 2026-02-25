/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:58:00 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 14:52:14 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// mlx_new_img to get off-screen buffer, like a painting palette

#include "../includes/so_long.h"

void	load_sprites(t_ctx *ctx)
{
	void	*mlx;

	mlx = ctx->grc_data.mlx;
	ctx->grc_data.img_wall = mlx_xpm_file_to_image(mlx, "src/sprites/wall.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	if (!ctx->grc_data.img_wall || ctx->grc_data.img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_floor = mlx_xpm_file_to_image(mlx,
			"src/sprites/floor.xpm", &ctx->grc_data.img_w,
			&ctx->grc_data.img_h);
	if (!ctx->grc_data.img_floor || ctx->grc_data.img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->player.img = mlx_xpm_file_to_image(mlx, "src/sprites/player.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	if (!ctx->player.img || ctx->grc_data.img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_exit = mlx_xpm_file_to_image(mlx, "src/sprites/exit.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	if (!ctx->grc_data.img_exit || ctx->grc_data.img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_clctb = mlx_xpm_file_to_image(mlx,
			"src/sprites/clctb.xpm", &ctx->grc_data.img_w,
			&ctx->grc_data.img_h);
	if (!ctx->grc_data.img_clctb || ctx->grc_data.img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
}

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
}

void	draw_player(t_ctx *ctx)
{
	mlx_put_image_to_window(ctx->grc_data.mlx, ctx->grc_data.win,
		ctx->player.img, ctx->player.x * TILE_SIZE, ctx->player.y * TILE_SIZE);
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
