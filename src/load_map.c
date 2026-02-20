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

static void	parse_map(t_ctx *ctx)
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
}

static char	*get_map_line(size_t line_len, char *new_line)
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
	return (map_line);
}

static void	read_map(t_ctx *ctx)
{
	char	*new_line;
	char	*map_line;
	char	**map;
	size_t	line_len;
	size_t	i;

	get_map_height(ctx);
	if (ctx->map_data.height == 0)
		close_free_error_exit(ctx->map_data.fd,
			NULL, NULL, "An empty map :/");
	ctx->map_data.map = (char **)ft_calloc(ctx->map_data.height + 1, sizeof(char *));
	if (!ctx->map_data.map)
		return ;
	map = ctx->map_data.map;
	/* rewind the file descriptor so we can reread from the start */
	if (lseek(ctx->map_data.fd, 0, SEEK_SET) < 0)
		close_free_error_exit(ctx->map_data.fd, map, NULL, "Failed to rewind map file");
	new_line = get_next_line(ctx->map_data.fd, true);
	if (!new_line)
		close_free_error_exit(ctx->map_data.fd, map, NULL, "Failed to read map");
	line_len = ft_strlen(new_line);
	map_line = get_map_line(line_len, new_line);
	free(new_line);
	i = 0;
	while (i < ctx->map_data.height)
	{
		map[i] = map_line;
		new_line = get_next_line(ctx->map_data.fd, false);
		if (i == 0 && (!new_line || ft_strlen(new_line) != line_len))
			close_free_error_exit(ctx->map_data.fd,
				map, NULL, "Map is not a rectangular!");
		map_line = get_map_line(line_len, new_line);
		free(new_line);
		++i;
	}
	map[i] = NULL;
	close(ctx->map_data.fd);
}

void	load_map(t_ctx *ctx)
{
	int	i;

	parse_map(ctx);
	read_map(ctx);
	i = 0;
	while (ctx->map_data.map[i])
	{
		ft_printf("%s\n", ctx->map_data.map[i]);
		++i;
	}
	free_strs(ctx->map_data.map, NULL);
}
