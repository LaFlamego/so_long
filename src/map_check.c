/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:05 by yueli             #+#    #+#             */
/*   Updated: 2026/02/17 18:05:30 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/so_long.h"
#include <stdio.h>
#include <stdbool.h>

size_t	ft_strlen(const char *str);
size_t	ft_strnb(char **strs);

//if rectangular (done)
//if 01CEP(only) (done)
//if P=1, E=1, C>=1 (done)
//if enclosed by 1
//if valid path(at least one way to go)

bool    is_rectangular(char **map)
{
    int line_len;
    
    if (!map || !*map)
        return (false);
    line_len = ft_strlen(*map);
    while (*map)
    {
        if (ft_strlen(*map) != line_len)
            return (false);
        ++map;
    }
    return (true);
}

bool    is_valid_char(char **map)
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

bool    is_all_one(char *line)
{
    while (*line)
    {
        if (*line != '1')
            return (false);
        ++line;
    }
    return (true);
}

bool    is_enclosed(char **map)
{
    int     i;
    size_t  line_nb;
    size_t  line_len;

    i = 1;
    line_nb = ft_strnb(map);
    line_len = ft_strlen(*map);
    printf("1111\n");
    if (!is_all_one(map[0]) || !is_all_one(map[line_nb - 1]))
        return (false);
    printf("2222\n");
    while (i < line_nb - 1)
    {
        printf("%s\n", map[i]);
        if (map[i][0] != '1' || map[i][line_len - 1] != '1')
            return (false);
        ++i;
    }
    return (true);
}

// void    map_check()
// {

// }

int main(void)
{
    char *map[] = {"11111", "10001", "10001", "10001", "11111", NULL};

    printf("%d\n", is_enclosed(map));
    return 0;
}