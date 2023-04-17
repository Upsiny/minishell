/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:19:35 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 16:07:47 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (i-- || i >= 0 || (char)c == '\0')
	{
		if (s[i] == (char)c)
		{
			str = (char *)&s[i];
			return (str);
		}
	}
	return (NULL);
}
