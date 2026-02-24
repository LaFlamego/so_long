/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:32 by yueli             #+#    #+#             */
/*   Updated: 2026/02/24 15:57:54 by yueli            ###   ########.fr       */
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
	get_img(&ctx);
	mlx_loop(ctx.grc_data.mlx);
	// free_strs(ctx.map_data.map, ctx.grc_data.mlx);
	// free_strs(NULL, ctx.grc_data.win);
	// free_strs(NULL, ctx.grc_data.img);
	return (0);
}
