/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:38 by yueli             #+#    #+#             */
/*   Updated: 2026/02/16 11:39:45 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdbool.h>
#include "../lib/libft/libft.h"

typedef struct  s_map
{
    char    **map;
    char    tile_type;

}   t_map;

#endif