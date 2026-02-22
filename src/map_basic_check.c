/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_basic_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:05 by yueli             #+#    #+#             */
/*   Updated: 2026/02/17 18:21:25 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if rectangular (done)
// if 01CEP(only) (done)
// if P=1, E=1, C>=1 (done)
// if enclosed by 1 (done)

// #include <stdio.h>
// #include <stdbool.h>

// size_t	ft_strlen(const char *str);
// size_t	ft_strnb(char **strs);

#include "../includes/so_long.h"

bool	is_rectangular(char **map)
{
	size_t	width;

	if (!map || !*map)
		return (false);
	width = ft_strlen(*map);
	while (*map)
	{
		if (ft_strlen(*map) != width)
			return (false);
		++map;
	}
	return (true);
}

static void	tile_check_get_begin(t_ctx *ctx, int lookup[3], int i, int j)
{
	char	**map;

	map = ctx->map_data.map;
	if (map[j][i] == 'P')
	{
		lookup[0] += 1;
		ctx->map_data.begin.x = i;
		ctx->map_data.begin.y = j;
	}
	else if (map[j][i] == 'E')
		lookup[1] += 1;
	else if (map[j][i] == 'C')
		lookup[2] += 1;
}

bool	is_valid_tile(t_ctx *ctx)
{
	int		i;
	int		j;
	char	**map;
	int		lookup[3] = {};

	map = ctx->map_data.map;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
				&& map[j][i] != 'E' && map[j][i] != 'P')
				return (false);
			tile_check_get_begin(ctx, lookup, i, j);
			++i;
		}
		++j;
	}
	if (lookup[0] != 1 || lookup[1] != 1 || lookup[2] < 1)
		return (false);
	return (true);
}

bool	is_all_one(char *row)
{
	while (*row)
	{
		if (*row != '1')
			return (false);
		++row;
	}
	return (true);
}

bool	is_enclosed(char **map, t_ctx *ctx)
{
	size_t	i;
	size_t	height;
	size_t	width;

	i = 1;
	height = ctx->map_data.height;
	width = ctx->map_data.width;
	if (!is_all_one(map[0]) || !is_all_one(map[height - 1]))
		return (false);
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (false);
		++i;
	}
	return (true);
}

// int main(void)
// {
//     char *map[] = {"11111", "10001", "10001", "10001", "11111", NULL};

//     printf("%d\n", is_enclosed(map));
//     return (0);
// }