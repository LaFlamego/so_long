/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:47:37 by yueli             #+#    #+#             */
/*   Updated: 2026/02/19 18:28:51 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//argc != 2 error(done)
//varify if .ber(done)
//open .ber(need to be closed - DO NOT FORGET)(done)
//read file(GNL) and store map(done)

#include "../includes/so_long.h"

void	read_map(t_ctx *ctx);

void	open_map(t_ctx *ctx)
{
	int	fd;

	fd = -1;
	if (ctx->argc != 2)
		error_exit("We need a map argument!");
	else if (ft_ends_with(ctx->argv[1], ".ber") == 1)
		error_exit("Not a valid .ber file :/");
	else
	{
		fd = open(ctx->argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error\nFailed to open map");
			exit(EXIT_FAILURE);
		}
	}
	ctx->map_data.fd = fd;
}

void	load_map(t_ctx *ctx)
{
	open_map(ctx);
	read_map(ctx);
}
