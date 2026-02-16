/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:32:33 by yueli             #+#    #+#             */
/*   Updated: 2025/11/16 21:02:48 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	s_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start + len > s_len)
		len = s_len - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (start >= ft_strlen(s))
	{
		ptr = (char *)malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	len = s_len(s, start, len);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
