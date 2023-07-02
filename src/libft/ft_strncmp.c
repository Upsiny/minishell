/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:26:01 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/02 17:15:58 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				comp;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	comp = 0;
	i = 0;
	if (!c1 || !c2)
		return (c1[i] - c2[i]);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i] || c1[i] == 0 || c2[i] == 0)
		{
			comp = c1[i] - c2[i];
			return (comp);
		}
		i++;
	}
	return (0);
}
