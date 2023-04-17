/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:52:04 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 17:04:39 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		if (ft_strncmp((char *)&haystack[i],
				needle, ft_strlen(needle)) == '\0')
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *) &haystack[i]);
		}
		i++;
	}
	return (NULL);
}
