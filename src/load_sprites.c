/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:56:47 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 10:56:13 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_sprite_valid(void *img, t_ctx *ctx)
{
	if (!img)
		clear_exit(ctx, "Sprites not valid :c");
}

static void	load_ply_anm(t_ctx *ctx)
{
	ctx->ply_anm.frms[1] = mlx_xpm_file_to_image(ctx->grc_data.mlx,
			"src/sprites/player_1.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->ply_anm.frms[1], ctx);
	ctx->ply_anm.frms[2] = mlx_xpm_file_to_image(ctx->grc_data.mlx,
			"src/sprites/player_2.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->ply_anm.frms[2], ctx);
	ctx->ply_anm.frms[3] = mlx_xpm_file_to_image(ctx->grc_data.mlx,
			"src/sprites/player_3.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->ply_anm.frms[3], ctx);
}

static void	load_ply_sprites(t_ctx *ctx, bool is_bonus)
{
	void	*mlx;
	int		i;

	mlx = ctx->grc_data.mlx;
	ctx->ply_anm.frms[0] = mlx_xpm_file_to_image(mlx, "src/sprites/player_0.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->ply_anm.frms[0], ctx);
	if (!is_bonus)
	{
		i = 1;
		while (i < 4)
		{
			ctx->ply_anm.frms[i] = mlx_xpm_file_to_image(mlx,
					"src/sprites/player_0.xpm",
					&ctx->grc_data.img_w, &ctx->grc_data.img_h);
			++i;
		}
	}
	else
		load_ply_anm(ctx);
}

void	load_sprites(t_ctx *ctx, bool is_bonus)
{
	void	*mlx;

	mlx = ctx->grc_data.mlx;
	load_ply_sprites(ctx, is_bonus);
	ctx->grc_data.img_wall = mlx_xpm_file_to_image(mlx, "src/sprites/wall.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_wall, ctx);
	ctx->grc_data.img_floor = mlx_xpm_file_to_image(mlx,
			"src/sprites/floor.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_floor, ctx);
	ctx->grc_data.img_exit = mlx_xpm_file_to_image(mlx, "src/sprites/exit.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_exit, ctx);
	ctx->grc_data.img_clctb = mlx_xpm_file_to_image(mlx,
			"src/sprites/clctb.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_clctb, ctx);
	ctx->grc_data.img_enemy = mlx_xpm_file_to_image(mlx,
			"src/sprites/enemy.xpm",
			&ctx->grc_data.img_w, &ctx->grc_data.img_h);
	check_sprite_valid(ctx->grc_data.img_enemy, ctx);
}
