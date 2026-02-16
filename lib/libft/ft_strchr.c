/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:46:22 by yueli             #+#    #+#             */
/*   Updated: 2025/11/17 16:19:15 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	const char s[] = "ssshabcsss";

	printf("%s\n", ft_strchr(s, 'h'));
}*/
