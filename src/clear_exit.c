/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 23:30:22 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 23:35:41 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    distroy_img(void *mlx, void *img)
{
    if (img)
        mlx_destroy_image(mlx, img);
}

void	clear_exit(t_ctx *ctx, char *msg)
{
	if (msg)
		ft_printf("Error\n%s\n", msg);
	if (ctx->map_data.map)
		free_strs(ctx->map_data.map, NULL);
    distroy_img(ctx->grc_data.mlx, ctx->grc_data.img_wall);
    distroy_img(ctx->grc_data.mlx, ctx->grc_data.img_floor);
    distroy_img(ctx->grc_data.mlx, ctx->ply_anm.frms[0]);
    distroy_img(ctx->grc_data.mlx, ctx->ply_anm.frms[1]);
    distroy_img(ctx->grc_data.mlx, ctx->grc_data.img_exit);
    distroy_img(ctx->grc_data.mlx, ctx->grc_data.img_clctb);
    distroy_img(ctx->grc_data.mlx, ctx->grc_data.img_enemy);
	if (ctx->grc_data.win)
		mlx_destroy_window(ctx->grc_data.mlx, ctx->grc_data.win);
	if (ctx->grc_data.mlx)
	{
		mlx_destroy_display(ctx->grc_data.mlx);
		free(ctx->grc_data.mlx);
	}
	exit(0);
}
