/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:57:45 by yueli             #+#    #+#             */
/*   Updated: 2026/02/27 17:53:55 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if valid path(at least one way to go)(done)

#include "../includes/so_long.h"

bool	is_valid_tile(t_ctx *ctx);

void	fill(char **dup_map, t_ctx *ctx, size_t y, size_t x)
{
	if (y >= ctx->map_data.height || x >= ctx->map_data.width)
		return ;
	if (dup_map[y][x] == '1' || dup_map[y][x] == 'O')
		return ;
	else if (dup_map[y][x] == '0' || dup_map[y][x] == 'E'
		|| dup_map[y][x] == 'C' || dup_map[y][x] == 'P')
		dup_map[y][x] = '1';
	fill(dup_map, ctx, y - 1, x);
	fill(dup_map, ctx, y + 1, x);
	fill(dup_map, ctx, y, x - 1);
	fill(dup_map, ctx, y, x + 1);
}

bool	is_valid_path(t_ctx *ctx)
{
	char	**dup_map;
	char	**tpr;
	int		i;

	dup_map = ft_strsdup(ctx->map_data.map);
	tpr = dup_map;
	fill(dup_map, ctx, ctx->player.y, ctx->player.x);
	while (*dup_map)
	{
		i = 0;
		while ((*dup_map)[i])
		{
			if ((*dup_map)[i] != '1' && (*dup_map)[i] != 'O')
			{
				free_strs(tpr, NULL);
				return (false);
			}
			++i;
		}
		++dup_map;
	}
	free_strs(tpr, NULL);
	return (true);
}

bool	is_valid_map(t_ctx *ctx)
{
	if (!is_rectangular(ctx->map_data.map))
		error_free_exit("Map is not a rectangular :c", ctx);
	else if (!is_valid_tile(ctx))
		error_free_exit("Tiles are not valid :c", ctx);
	else if (!is_enclosed(ctx->map_data.map, ctx))
		error_free_exit("Oops! We need right walls!", ctx);
	else if (!is_valid_path(ctx))
		error_free_exit("0 path is good to go :/", ctx);
	return (true);
}
