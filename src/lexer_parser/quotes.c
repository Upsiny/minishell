/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:15:45 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/27 15:50:31 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// mettre dans le makefile et dans le .h

int	ft_check_endquote(t_data *data, char c)
{
	int	i;
	int	j;

	i = 1;
	j = data->lexer_check;
	while (data->prompt[j])
	{
		i++;
		j++;
		if (data->prompt[j] == c)
			return (i);
	}
	return (0);
}

void	ft_simple_quotes(t_data *data)
{
	int	i;

	i = 0;
	if (ft_check_endquote(data, '\'') != 0)
	{
		i = ft_check_endquote(data, '\'');
		implement_list(data, TOKEN_SQUOTE, i, data->lexer_check);
		while (i)
		{
			lexer_advance(data);
			i--;
		}
	}
	else
		error_lexer(data, "no ended quote");
}

void	ft_double_quotes(t_data *data)
{
	int	i;

	i = 0;
	if (ft_check_endquote(data, '\"') != 0)
	{
		i = ft_check_endquote(data, '\"');
		implement_list(data, TOKEN_DQUOTE, i, data->lexer_check);
		while (i)
		{
			lexer_advance(data);
			i--;
		}
	}
	else
		error_lexer(data, "no ended quote");
}

void	ft_lexer_quotes(t_data *data)
{
	if (data->lexer_char == '\"')
		ft_double_quotes(data);
	else if (data->lexer_char == '\'')
		ft_simple_quotes(data);
	data->index_lexer++;
}
