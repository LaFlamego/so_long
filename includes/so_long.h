/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:38 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 11:30:57 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct  s_tile
{
    int x;
    int y;
}   t_tile;

typedef struct  s_map
{
    char            **map;
    size_t          height;
    size_t          width;
    int             fd;
    struct s_tile   begin;
}   t_map;

typedef struct  s_ctx
{
    char            **argv;
    int             argc;
    struct s_map    map_data;
}   t_ctx;

void	init_ctx(t_ctx *ctx, int argc, char **argv);
void    error_exit(char *msg);
void    error_free_exit(char *msg, t_ctx *ctx);
void	close_free_error_exit(int fd, char **strs, char *str, char *msg);
void    free_strs(char **strs, char *str);
void	load_map(t_ctx *ctx);
bool	is_valid_map(t_ctx *ctx);

#endif