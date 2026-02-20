/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:58:08 by yueli             #+#    #+#             */
/*   Updated: 2026/02/19 14:07:52 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// size_t	ft_strlen(const char *str);
// size_t	ft_strnb(char **strs);

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_strsdup(char **strs)
{
	char	**res;
	size_t	len;
	size_t	i;

	len = ft_strnb(strs);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = NULL;
	i = 0;
	while (i < len)
	{
		res[i] = strs[i];
		++i;
	}
	return (res);
}

// int	main(void)
// {
// 	char *strs[4] = {"eat", "pray", "love", NULL};
// 	char	**res;

// 	res = ft_strsdup(strs);
// 	while (*res)
// 	{	
// 		printf("%s\n", *res);
// 		++res;
// 	}
// 	return 0;
// }
