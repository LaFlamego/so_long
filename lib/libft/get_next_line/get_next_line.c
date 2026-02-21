/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:02:33 by yueli             #+#    #+#             */
/*   Updated: 2026/02/21 09:24:10 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read returns how many characters it read

#include "get_next_line.h"

char	*join_free(char *stash, char *buff)
{
	char	*tpr;

	tpr = ft_strjoin(stash, buff);
	free(stash);
	return (tpr);
}

char	*read_file(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), free(stash), NULL);
		buff[bytes_read] = '\0';
		stash = join_free(stash, buff);
		if (!stash)
			return (free(buff), NULL);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (free(buff), stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char));
	else
		line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || (stash[i] == '\n' && !stash[i + 1]))
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc(ft_strlen(stash) - i, sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd, bool is_start)
{
	static char	*stash[1024];
	char		*line;

	if (is_start)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_next_stash(stash[fd]);
	return (line);
}

/* use a per-fd stash to avoid cross-fd interference */