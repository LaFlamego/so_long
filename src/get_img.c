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

#include "../includes/so_long.h"

void	init_mlx(t_ctx *ctx)
{
	void	*mlx_ptr;
	size_t	width;
	size_t	height;

	width = ctx->map_data.width;
	height = ctx->map_data.height;
	ctx->grc_data.mlx = mlx_init();
	if (!ctx->grc_data.mlx)
		return ;
	mlx_ptr = ctx->grc_data.mlx;
	ctx->grc_data.win = mlx_new_window(mlx_ptr, width * TILE_SIZE, height * TILE_SIZE, "so_long v.v");
	if (!ctx->grc_data.win)
		return ;
}

void	get_img(t_ctx *ctx)
{
	void	*img;
	void	*mlx_ptr;
	void	*window;
	size_t	width;
	size_t	height;

	mlx_ptr = ctx->grc_data.mlx;
	width = ctx->map_data.width;
	height = ctx->map_data.height;
	window = ctx->grc_data.win;
	img = mlx_new_image(mlx_ptr, width, height);
	mlx_put_image_to_window(mlx_ptr, window, img, 0, 0);
}
