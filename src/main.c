/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:53:32 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 11:31:08 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	init_ctx(&ctx, argc, argv);
	load_map(&ctx);
	if (!is_valid_map(&ctx))
	{
		return (1);
	}
	free_strs(ctx.map_data.map, NULL);
	return (0);
}
