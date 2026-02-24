/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:58:00 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 20:11:28 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//mlx_new_img to get off-screen buffer, like a painting palette

#include "../includes/so_long.h"

void	load_sprites(t_ctx *ctx)
{
	void	*mlx;
	int		img_w;
	int		img_h;

	mlx = ctx->grc_data.mlx;
	img_w = ctx->grc_data.img_w;
	img_h = ctx->grc_data.img_h;
	ctx->grc_data.img_wall = mlx_xpm_file_to_image(mlx, "src/sprites/wall.xpm", &img_w, &img_h);
	if (!ctx->grc_data.img_wall || img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_floor = mlx_xpm_file_to_image(mlx, "src/sprites/floor.xpm", &img_w, &img_h);
	if (!ctx->grc_data.img_floor || img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_player = mlx_xpm_file_to_image(mlx, "src/sprites/player.xpm", &img_w, &img_h);
	if (!ctx->grc_data.img_player || img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_exit = mlx_xpm_file_to_image(mlx, "src/sprites/exit.xpm", &img_w, &img_h);
	if (!ctx->grc_data.img_exit || img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
	ctx->grc_data.img_clctb = mlx_xpm_file_to_image(mlx, "src/sprites/clctb.xpm", &img_w, &img_h);
	if (!ctx->grc_data.img_clctb || img_w != TILE_SIZE)
		clear_exit(ctx, "Sprites not valid :c");
}

void	get_img(t_ctx *ctx)
{
	//void	*img;
	void	*mlx_ptr;
	void	*window;
	char	**map;
	size_t	width;
	size_t	height;
	size_t	x;
	size_t	y;

	mlx_ptr = ctx->grc_data.mlx;
	width = ctx->map_data.width;
	height = ctx->map_data.height;
	window = ctx->grc_data.win;
	map = ctx->map_data.map;
	//img = mlx_new_image(mlx_ptr, width, height);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, window, ctx->grc_data.img_wall, x, y);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(mlx_ptr, window, ctx->grc_data.img_floor, x, y);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, window, ctx->grc_data.img_player, x, y);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, window, ctx->grc_data.img_exit, x, y);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, window, ctx->grc_data.img_clctb, x, y);
			++x;
		}
		++y;
	}
}
