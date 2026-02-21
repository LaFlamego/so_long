/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:50:51 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 11:30:42 by yueli            ###   ########.fr       */
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
