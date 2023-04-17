/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:57:42 by tpaufert          #+#    #+#             */
/*   Updated: 2022/03/27 15:32:07 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = (count * size);
	str = malloc(j);
	if (!str)
		return (NULL);
	*str = 0;
	while (j > 0)
	{
		str[i] = '\0';
		i++;
		j--;
	}
	return (str);
}
