/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpytab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:33:17 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/28 16:40:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cpytab(char **tab)
{
	int		size;
	int		i;
	char	**cpy;

	size = 0;
	i = 0;
	while (tab[size] != NULL)
		size++;
	cpy = malloc(sizeof(char *) * (size + 1));
	if (tab == NULL || !cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = ft_strdup3(tab[i]);
		i++;
	}
	cpy[size] = NULL;
	return (cpy);
}
