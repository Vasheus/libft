/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:20:19 by yosabir           #+#    #+#             */
/*   Updated: 2023/12/07 01:05:39 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int value, size_t num)
{
	unsigned char	*p;
	size_t			i;

	p = b;
	i = 0;
	while (i < num)
	{
		p[i] = value;
		i++;
	}
	return (b);
}
