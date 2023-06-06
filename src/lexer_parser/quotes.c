/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:15:45 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/06 17:36:44 by tpaufert         ###   ########.fr       */
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

int	ft_simple_quotes(t_data *data)
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
		return (0);
	}
	else
	{
		error_lexer(data, "no ended quote");
		return (1);
	}
}

int	ft_double_quotes(t_data *data)
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
		return (0);
	}
	else
	{
		error_lexer(data, "no ended quote");
		return (1);
	}
}

int	ft_lexer_quotes(t_data *data)
{
	if (data->lexer_char == '\"')
	{
		if (ft_double_quotes(data))
			return (1);
	}
	else if (data->lexer_char == '\'')
	{
		if (ft_simple_quotes(data))
			return (1);
	}
	data->index_lexer++;
	return (0);
}
