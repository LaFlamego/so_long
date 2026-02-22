/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 18:39:07 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 15:57:12 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
}