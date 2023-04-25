/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/24 16:49:52 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/*void norm()
{
}*/

char	**my_split(char *s)
{
	char	**str;
	int		i;
	int		j;

	str = ft_split(s, ' ');
	i = ft_count_tab(str);
	j = 0;
//	(norm(), str = ft_split(s, ' '));
	while (str[j] != NULL)
	{
		str[j] = *ft_split(str[j], '\t');
		j++;
	}
	j = 0;
	while (str[j] != NULL)
	{
		j++;
	}
	return (str);
}
