/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:11:50 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 17:24:23 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest;
	char			*source;
	unsigned int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	source = (char *)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return ((char *)dest);
}
