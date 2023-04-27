/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:30:12 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/27 11:39:55 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	lexer_advance(t_data *data)
{
	if (data->prompt[data->lexer_check]
		&& data->lexer_check < ft_strlen(data->prompt))
	{
		data->lexer_check ++;
		data->lexer_char = data->prompt[data->lexer_check];
	}
}

void	lexer_work(t_data *data)
{
	while (data->lexer_check < ft_strlen(data->prompt))
	{
		if (ft_isalpha(data->lexer_char))
			ft_lexer_alpha(data);
		if (data->lexer_char == '\"' || data->lexer_char == '\'')
			ft_lexer_quotes(data);
		if (data->lexer_char == '<' || data->lexer_char == '>')
			ft_lexer_redir(data);
		if (data->lexer_char == '-')
			ft_lexer_option(data);
		if (data->lexer_char == '$')
			ft_lexer_dollar(data);
	}
}

void	init_lexer(t_data *data)
{
	data->lexer_check = 0;
	data->lexer_char = data->prompt[data->lexer_check];
}
