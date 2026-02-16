/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:38:33 by yueli             #+#    #+#             */
/*   Updated: 2026/02/13 17:19:32 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *str)
// {
// 	int	len;

// 	if (!str)
// 		return (0);
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		ptr[i++] = 0;
// 	}
// }

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*res;
// 	size_t	len1;
// 	size_t	len2;
// 	size_t	i;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	res = malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (i < len1)
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	while (i < len1 + len2)
// 	{
// 		res[i] = s2[i - len1];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
