/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:37:04 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/14 17:04:36 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tolower(char *c)
{
	int	i;

	i = 0;
	while (c)
	{
		if (c[i] >= 65 && c[i] <= 90)
			c[i] += 32;
		i++;
	}
	return (c);
}
