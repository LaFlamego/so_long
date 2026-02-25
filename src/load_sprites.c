/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:56:47 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 23:24:12 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_sprite_valid(void *img, t_ctx *ctx)
{
	if (!img)
		clear_exit(ctx, "Sprites not valid :c");
}

static void load_ply_anm(t_ctx *ctx)
{
    void	*mlx;

    mlx = ctx->grc_data.mlx;
    ctx->ply_anm.frms[0] = mlx_xpm_file_to_image(mlx, "src/sprites/player.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
    check_sprite_valid(ctx->ply_anm.frms[0], ctx);
    ctx->ply_anm.frms[1] = mlx_xpm_file_to_image(mlx, "src/sprites/player_anm.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
    check_sprite_valid(ctx->ply_anm.frms[1], ctx);
}

void	load_sprites(t_ctx *ctx)
{
	void	*mlx;

	mlx = ctx->grc_data.mlx;
    load_ply_anm(ctx);
	ctx->grc_data.img_wall = mlx_xpm_file_to_image(mlx, "src/sprites/wall.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_wall, ctx);
	ctx->grc_data.img_floor = mlx_xpm_file_to_image(mlx,"src/sprites/floor.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_floor, ctx);
	ctx->grc_data.img_exit = mlx_xpm_file_to_image(mlx, "src/sprites/exit.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_exit, ctx);
	ctx->grc_data.img_clctb = mlx_xpm_file_to_image(mlx, "src/sprites/clctb.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_clctb, ctx);
	ctx->grc_data.img_enemy = mlx_xpm_file_to_image(mlx, "src/sprites/enemy.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_enemy, ctx);
}
