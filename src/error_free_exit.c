/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:50:51 by yueli             #+#    #+#             */
/*   Updated: 2026/02/24 14:50:26 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    free_strs(char **strs, char *str)
{
	char	**tmp;

	if (!strs && !str)
		return ;
	if (strs)
	{
		tmp = strs;
		while (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
			++tmp;
		}
		free(strs);
		strs = NULL;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void    error_exit(char *msg)
{
    ft_printf("Error\n%s\n", msg);
    exit(1);
}

void    error_free_exit(char *msg, t_ctx *ctx)
{
    ft_printf("Error\n%s\n", msg);
	free_strs(ctx->map_data.map, NULL);
    exit(1);
}

void	close_free_error_exit(int fd, char **strs, char *str, char *msg)
{
    close(fd);
	free_strs(strs, str);
	ft_printf("Error\n%s\n", msg);
    exit(1);
}

void	clear_exit(t_ctx *ctx, char *msg)
{
	ft_printf("Error\n%s\n", msg);
	if (ctx->map_data.map)
		free_strs(ctx->map_data.map, NULL);
	if (ctx->grc_data.img_wall)
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img_wall);
	if (ctx->grc_data.img_floor)
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img_floor);
	if (ctx->grc_data.img_player)
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img_player);
	if (ctx->grc_data.img_exit)
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img_exit);
	if (ctx->grc_data.img_clctb)
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img_clctb);
	if (ctx->grc_data.win)
		mlx_destroy_window(ctx->grc_data.mlx, ctx->grc_data.win);
	if (ctx->grc_data.mlx)
	{
		mlx_destroy_display(ctx->grc_data.mlx);
		free(ctx->grc_data.mlx);
	}
	exit(0);
}
