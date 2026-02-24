/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:39:07 by yueli             #+#    #+#             */
/*   Updated: 2026/02/24 14:37:42 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		close_window(void *prm);
int		esc_close(int keycode, void *prm);

void	init_ctx(t_ctx *ctx, int argc, char **argv)
{
	ft_bzero(ctx, sizeof(t_ctx));
	ctx->argc = argc;
	ctx->argv = argv;
	ctx->map_data.begin.x = 0;
	ctx->map_data.begin.y = 0;
	ctx->map_data.fd = -1;
	ctx->map_data.height = 0;
	ctx->map_data.width = 0;
	ctx->map_data.map = NULL;
	ctx->grc_data.mlx = NULL;
	ctx->grc_data.win = NULL;
	ctx->grc_data.img_wall = NULL;
	ctx->grc_data.img_floor = NULL;
	ctx->grc_data.img_player = NULL;
	ctx->grc_data.img_exit = NULL;
	ctx->grc_data.img_clctb = NULL;
	ctx->grc_data.img_w = 0;
	ctx->grc_data.img_h = 0;
}

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

void	init_hook(t_ctx *ctx)
{
	mlx_hook(ctx->grc_data.win, 17, 0, close_window, ctx);
	mlx_key_hook(ctx->grc_data.win, esc_close, ctx);
}
