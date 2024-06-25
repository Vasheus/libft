/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:34:16 by yosabir           #+#    #+#             */
/*   Updated: 2023/12/12 09:03:08 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			word++;
		while (*s != c && *s)
			s++;
	}
	return (word);
}

static void	free_strings(char **strings, int i)
{
	while (i >= 0)
	{
		free(strings[i]);
		i--;
	}
	free(strings);
}

static void	copy(char *s1, char *s2, int j, int index)
{
	int	i;

	i = 0;
	while (index < j)
	{
		s1[i] = s2[index];
		i++;
		index++;
	}
	s1[i] = '\0';
}

static char	*allocword(char **str, char sep)
{
	int		i;
	int		wordindex;
	char	*s;
	char	*ptr;

	i = 0;
	s = *str;
	while (*s && s[i] == sep)
		i++;
	wordindex = i;
	while (s[i] != '\0' && s[i] != sep)
		i++;
	ptr = malloc((i - wordindex) + 1);
	if (!ptr)
		return (NULL);
	copy(ptr, s, i, wordindex);
	*str = *str + i;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	*s1;
	int		wordnmbr;
	int		i;

	if (s == NULL)
		return (NULL);
	s1 = (char *)s;
	wordnmbr = count(s, c);
	p = malloc((wordnmbr + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = -1;
	while (i++ < wordnmbr - 1)
	{
		p[i] = allocword(&s1, c);
		if (!p[i])
		{
			i--;
			free_strings(p, i);
			return (NULL);
		}
	}
	p[wordnmbr] = NULL;
	return (p);
}
