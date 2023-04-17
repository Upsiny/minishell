/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:01:29 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/05 16:41:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tot;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tot = ft_calloc (sizeof (char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tot)
		return (NULL);
	while (s1[i])
	{
		tot[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tot[i] = s2[j];
		i++;
		j++;
	}
	tot[i] = '\0';
	return (tot);
}
