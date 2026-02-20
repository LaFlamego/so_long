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

//if rectangular (done)
//if 01CEP(only) (done)
//if P=1, E=1, C>=1 (done)
//if enclosed by 1 (done)

// #include <stdio.h>
// #include <stdbool.h>

// size_t	ft_strlen(const char *str);
// size_t	ft_strnb(char **strs);

#include "../includes/so_long.h"

// void    init_map(t_map *map)
// {
//     map->width = ft_strlen(map->map);
//     map->height = ft_strnb(map->map[0]);
// }

bool    is_rectangular(char **map)
{
    size_t width;
    
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

bool    is_valid_tile(char **map)
{
    int i;
    int lookup[3] = {};

    while (*map)
    {
        i = 0;
        while ((*map)[i])
        {
            if ((*map)[i] != '0' && (*map)[i] != '1' && (*map)[i] != 'C'
                && (*map)[i]!= 'E' && (*map)[i] != 'P')
                return (false);
            if ((*map)[i] == 'P')
                lookup[0] += 1;
            else if ((*map)[i] == 'E')
                lookup[1] += 1;
            else if ((*map)[i] == 'C')
                lookup[2] += 1;
            ++i;
        }
        ++map;
    }
    if (lookup[0] != 1 || lookup[1] != 1 || lookup[2] < 1)
        return (false);
    return (true);
}

bool    is_all_one(char *row)
{
    while (*row)
    {
        if (*row != '1')
            return (false);
        ++row;
    }
    return (true);
}

bool    is_enclosed(char **map)
{
    size_t  i;
    size_t  height;
    size_t  width;

    i = 1;
    height = ft_strnb(map);
    width = ft_strlen(*map);
    if (!is_all_one(map[0]) || !is_all_one(map[height - 1]))
        return (false);
    while (i < height - 1)
    {
        printf("%s\n", map[i]);
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
//     return 0;
// }