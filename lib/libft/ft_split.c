/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yueli <yueli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:46:30 by yueli             #+#    #+#             */
/*   Updated: 2026/02/05 12:25:03 by yueli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//size_t is non-sign so it is better designed for malloc
//if we use static then we need to align the gnw and split
//so to get the if(i == 0) to make the 1st one an empty string
//update: have a reset in gnw - solve the multiple call issues;
//add condition in gnw to avoid another empty string

#include "libft.h"

void	free_splits(char **splits)
{
	int	i;

	if (!splits)
		return ;
	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		++i;
	}
	free(splits);
}

static size_t	count_words(const char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(const char *s, char c, int reset)
{
	static int	cursor;
	int			i;
	size_t		len;
	char		*next_word;

	if (reset)
	{
		cursor = 0;
		return (NULL);
	}
	while (s[cursor] == c)
		++cursor;
	if (s[cursor] == '\0')
		return (NULL);
	len = 0;
	while ((s[cursor + len]) && (s[cursor + len] != c))
		++len;
	next_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	i = 0;
	while (s[cursor] && (s[cursor] != c))
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		words_count;
	char	**res;

	get_next_word(s, c, 1);
	words_count = count_words(s, c);
	if (!words_count)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!res)
		return (NULL);
	res[words_count] = NULL;
	i = 0;
	res[i] = get_next_word(s, c, 0);
	while (res[i])
		res[++i] = get_next_word(s, c, 0);
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*str = " eat pray love";
// 	char	charset = ' ';
// 	char	**op;
// 	int	i = 0; 

// 	op = split(str, charset);
// 	while (op[i])
// 	{
// 		printf("%s\n", op[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (op[i])
// 	{
// 		free(op[i]);
// 		i++;
// 	}
// 	free(op);
// 	return (0);
// }
