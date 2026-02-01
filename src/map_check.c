/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:05 by yueli             #+#    #+#             */
/*   Updated: 2026/02/01 16:27:34 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


//if rectangular
//if 01CEP(only)
//if P=1, E=1, C>=1
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
    
}

void    map_check()
{

}
