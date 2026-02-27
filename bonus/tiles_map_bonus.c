/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 09:56:21 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 12:11:15 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

bool	is_valid_tile_bonus(t_ctx *ctx)
{
	int		i;
	int		j;
	char	**map;
	int		lookup[4];

	ft_bzero(lookup, sizeof(int) * 4);
	map = ctx->map_data.map;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
				&& map[j][i] != 'E' && map[j][i] != 'P' && map[j][i] != 'O')
				return (false);
			tile_check_and_mark(ctx, lookup, i, j);
			++i;
		}
		++j;
	}
	if (lookup[0] != 1 || lookup[1] != 1 || lookup[2] < 1 || lookup[3] > 1)
		return (false);
	return (true);
}

bool	is_valid_map_bonus(t_ctx *ctx)
{
	if (!is_rectangular(ctx->map_data.map))
		error_free_exit("Map is not a rectangular :c", ctx);
	else if (!is_valid_tile_bonus(ctx))
		error_free_exit("Tiles are not valid :c", ctx);
	else if (!is_enclosed(ctx->map_data.map, ctx))
		error_free_exit("Oops! We need right walls!", ctx);
	else if (!is_valid_path(ctx))
		error_free_exit("0 path is good to go :/", ctx);
	return (true);
}
