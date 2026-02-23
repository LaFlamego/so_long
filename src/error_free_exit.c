/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:50:51 by yueli             #+#    #+#             */
/*   Updated: 2026/02/23 16:27:28 by yueli            ###   ########.fr       */
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

void	clear_exit(t_ctx *ctx)
{
	if (ctx->map_data.map)
		free_strs(ctx->map_data.map, NULL);
	if (ctx->grc_data.img) //and other imges added later
		mlx_destroy_image(ctx->grc_data.mlx, ctx->grc_data.img);
	if (ctx->grc_data.win)
		mlx_destroy_window(ctx->grc_data.mlx, ctx->grc_data.win);
	if (ctx->grc_data.mlx)
	{
		mlx_destroy_display(ctx->grc_data.mlx);
		free(ctx->grc_data.mlx);
	}
	exit(0);
}
