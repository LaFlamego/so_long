/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 08:57:45 by yueli             #+#    #+#             */
/*   Updated: 2026/02/18 15:38:25 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if valid path(at least one way to go)(done)

#include "../includes/so_long.h"

bool    is_rectangular(char **map);
bool    is_valid_tile(char **map);
bool    is_enclosed(char **map);

static void	fill(char **dup_map, t_ctx *ctx, size_t row, size_t col)
{
	if (row < 0 || col < 0 || row >= ctx->map_data.height
		|| col >= ctx->map_data.width)
		return ;
	if (dup_map[row][col] == '1')
		return ;
	else if (dup_map[row][col] == '0' || dup_map[row][col] == 'E'
		|| dup_map[row][col] == 'C' || dup_map[row][col] == 'P')
		dup_map[row][col] = '1';
	fill(dup_map, ctx, row - 1, col);
	fill(dup_map, ctx, row + 1, col);
    fill(dup_map, ctx, row, col - 1);
    fill(dup_map, ctx, row, col + 1);
}

bool	is_valid_path(t_ctx *ctx)
{
	char	target;
	char	**dup_map;
	int		i;

	dup_map = ft_strsdup(ctx->map_data.map);
	target = ctx->map_data.map[ctx->map_data.begin.y][ctx->map_data.begin.x];
	fill(dup_map, ctx, ctx->map_data.begin.y, ctx->map_data.begin.x);
	while (*dup_map)
	{
		i = 0;
		while ((*dup_map)[i])
		{	
			if ((*dup_map)[i] != '1')
				return (false);
			++i;
		}
		++dup_map;
	}
	free_strs(dup_map, NULL);
	return (true);
}

bool	is_valid_map(t_ctx *ctx)
{
	if (!is_rectangular(ctx->map_data.map))
		error_exit("Map is not a rectangular :c");
	else if (!is_valid_tile(ctx->map_data.map))
		error_exit("Tiles are not valid :c");
	else if (!is_enclosed(ctx->map_data.map))
		error_exit("Oops! We need more walls!");
	else if (!is_valid_path(ctx))
		error_exit("0 path is good to go :/");
	return (true);
}


