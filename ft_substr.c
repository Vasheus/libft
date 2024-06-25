/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:20:35 by yosabir           #+#    #+#             */
/*   Updated: 2023/12/07 01:05:55 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || (size_t)start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s) - start)
		ptr = malloc(len + 1);
	else
		ptr = malloc(ft_strlen(s) - start + 1);
	if (!ptr)
		return (NULL);
	while ((size_t)i < len && s[start + i] != '\0')
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
