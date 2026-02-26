/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:44:14 by yueli             #+#    #+#             */
/*   Updated: 2026/02/26 11:49:44 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx, argc, argv);
	load_map(&ctx);
	if (!is_valid_map_bonus(&ctx))
		return (1);
	init_mlx(&ctx);
	init_hook_bonus(&ctx);
	load_sprites(&ctx, true);
	render_map(&ctx);
	draw_player(&ctx);
	print_steps(&ctx, true);
	mlx_loop(ctx.grc_data.mlx);
	return (0);
}
