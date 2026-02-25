/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:35:38 by yueli             #+#    #+#             */
/*   Updated: 2026/02/25 17:40:01 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

#define KEY_ESC   65307
#define KEY_W     119
#define KEY_A     97
#define KEY_S     115
#define KEY_D     100
#define KEY_UP    65362
#define KEY_DOWN  65364
#define KEY_LEFT  65361
#define KEY_RIGHT 65363

typedef struct s_tile
{
	int				x;
	int				y;
	void			*img;
}					t_tile;

typedef struct s_move
{
	int				dx;
	int 			dy;
}					t_move;

typedef struct s_map
{
	char			**map;
	size_t			height;
	size_t			width;
	int				fd;
}					t_map;

typedef struct s_grc
{
	void			*mlx;
	void			*win;
	void			*img_wall;
	void			*img_floor;
	void			*img_exit;
	void			*img_clctb;
	int				img_w;
	int				img_h;

}					t_grc;

typedef struct s_ctx
{
	char			**argv;
	int				argc;
	int				stps;
	int				clctbs;
	struct s_map	map_data;
	struct s_grc	grc_data;
	struct s_tile	player;
}					t_ctx;

void	init_ctx(t_ctx *ctx, int argc, char **argv);
void	error_exit(char *msg);
void	error_free_exit(char *msg, t_ctx *ctx);
void	close_free_error_exit(int fd, char **strs, char *str, char *msg);
void	clear_exit(t_ctx *ctx, char *msg);
void	free_strs(char **strs, char *str);
void	load_map(t_ctx *ctx);
bool	is_valid_map(t_ctx *ctx);
void	init_mlx(t_ctx *ctx);
void	init_hook(t_ctx *ctx);
void	load_sprites(t_ctx *ctx);
void	render_map(t_ctx *ctx);
void	draw_player(t_ctx *ctx);

#endif