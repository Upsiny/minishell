/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:15:45 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/25 16:21:44 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// mettre dans le makefile et dans le .h

void	ft_double_quotes(t_data *data, int index)
{
	// travail avec les token : init du token d_quotes
}

void	ft_simple_quotes(t_data *data, int index)
{
	// travail avec les token : init du token s_quote
	// atttention a la signification du simple quote
}

void	verif_cmdquotes(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(data->prompt);
	while (i <= j)
	{
		if (data->prompt[i] == '\"')
			ft_double_quotes(data, i);
		else if (data->prompt[i] == '\'')
			ft_simple_quotes(data, i);
		i++;
	}
}
