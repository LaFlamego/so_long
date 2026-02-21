/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:04:55 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 11:05:19 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_map(t_ctx *ctx);

static void get_map_height(t_ctx *ctx)
{
	size_t	height;
	char	*line;

	height = 0;
	line = get_next_line(ctx->map_data.fd, true);
	while (line)
	{
		++height;
		free(line);
		line = get_next_line(ctx->map_data.fd, false);
	}
	ctx->map_data.height = height;
	close(ctx->map_data.fd);
	open_map(ctx);
}

static char	*get_map_line(t_ctx *ctx, size_t line_len, char *new_line)
{
	size_t  i;
	char    *map_line;

	if (!new_line)
		return (NULL);
	if (line_len > 0 && new_line[line_len - 1] == '\n')
		--line_len;
	map_line = ft_calloc(line_len + 1, sizeof(char));
	if (!map_line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		map_line[i] = new_line[i];
		++i;
	}
	map_line[i] = '\0';
	ctx->map_data.width = ft_strlen(map_line);
	return (map_line);
}

static void	prep_read_map(t_ctx *ctx)
{
	get_map_height(ctx);
	if (ctx->map_data.height == 0)
		close_free_error_exit(ctx->map_data.fd,
			NULL, NULL, "An empty map :/");
	ctx->map_data.map = (char **)ft_calloc(ctx->map_data.height + 1, sizeof(char *));
	if (!ctx->map_data.map)
		return ;
}

static void	store_map(t_ctx *ctx, char *map_line, size_t line_len)
{
	size_t		i;
	char	*new_line;

	i = 0;
	while (i < ctx->map_data.height)
	{
		ctx->map_data.map[i] = map_line;
		new_line = get_next_line(ctx->map_data.fd, false);
		if (i == 0 && (!new_line || ft_strlen(new_line) != line_len))
			close_free_error_exit(ctx->map_data.fd,
				ctx->map_data.map, NULL, "Map is not a rectangular!");
		map_line = get_map_line(ctx, line_len, new_line);
		free(new_line);
		++i;
	}
	ctx->map_data.map[i] = NULL;
}

void	read_map(t_ctx *ctx)
{
	char	*new_line;
	char	*map_line;
	size_t	line_len;

	prep_read_map(ctx);
	new_line = get_next_line(ctx->map_data.fd, true);
	if (!new_line)
		close_free_error_exit(ctx->map_data.fd, ctx->map_data.map, NULL, "Failed to read map");
	line_len = ft_strlen(new_line);
	map_line = get_map_line(ctx, line_len, new_line);
	free(new_line);
	store_map(ctx, map_line, line_len);
	close(ctx->map_data.fd);
}
