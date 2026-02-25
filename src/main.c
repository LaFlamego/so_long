/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:32 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 17:39:11 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	printf("111\n");
	init_ctx(&ctx, argc, argv);
	load_map(&ctx);
	printf("2222\n");
	if (!is_valid_map(&ctx))
		return (1);
	init_mlx(&ctx);
	init_hook(&ctx);
	printf("3333\n");
	load_sprites(&ctx);
	render_map(&ctx);
	draw_player(&ctx);
	printf("444\n");
	mlx_loop(ctx.grc_data.mlx);
	return (0);
}
