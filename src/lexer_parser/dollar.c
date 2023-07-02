/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:18:37 by hguillau          #+#    #+#             */
/*   Updated: 2023/07/02 18:21:27 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isinside(char c)
{
	int	i;

	i = 0;
	while (DOLLAR_STOP[i])
	{
		if (DOLLAR_STOP[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	get_dollar(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*dol_value;

	i = data->lexer_check;
	j = 0;
	k = 1;
	while (data->prompt[i + j])
	{
		j++;
		if (!ft_isspace(data->prompt[i + j]) || !ft_isinside(data->prompt[i+j]))
			break ;
		lexer_advance(data);
	}
	dol_value = malloc(j * sizeof(char *));
	while (k < j)
	{
		dol_value[k - 1] = data->prompt[i + 1];
		k++;
		i++;
	}
	printf("%s", getenv(dol_value)); //remplacer par un autre getenv
	free(dol_value);
}
