/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:32 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 00:03:59 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx, argc, argv);
	load_map(&ctx);
	if (!is_valid_map(&ctx))
		return (1);
	init_mlx(&ctx);
	init_hook(&ctx);
	load_sprites(&ctx);
	draw_map_by_tile(&ctx);
	mlx_loop(ctx.grc_data.mlx);
	return (0);
}
