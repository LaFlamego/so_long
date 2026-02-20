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

static char	*get_map_line(size_t line_len, char *new_line)
{
	size_t	i;
	char	*map_line;

	i = 0;
	map_line = (char *)malloc(sizeof(char) * line_len);
	if (!map_line)
		return (NULL);
	while (i < line_len - 1)
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
	size_t	line_len;
	size_t	i;

	new_line = get_next_line(ctx->map_data.fd);
	if (!new_line)
		close_free_error_exit(ctx->map_data.fd,
			NULL, NULL, "An empty map :/");
	line_len = ft_strlen(new_line);
	map_line = get_map_line(line_len, new_line);
	i = 0;
	while (new_line)
	{
		ctx->map_data.map[i] = map_line;
		new_line = get_next_line(ctx->map_data.fd);
		if (i == 0 && ft_strlen(new_line) != line_len)
			close_free_error_exit(ctx->map_data.fd,
				NULL, map_line, "Map is not a rectangular!");
		map_line = get_map_line(line_len, new_line);
		++i;
	}
	close(ctx->map_data.fd);
}

void	load_map(t_ctx *ctx)
{
	parse_map(ctx);
	read_map(ctx);
}
