/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:17:23 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/02 17:32:03 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
int		quote_in_str(t_data *data, char c)
{
	int	i;

	i = 0;
	if (ft_check_endquote(data, c, 0, data->lexer_check) != 0)
	{
		i = ft_check_endquote(data, c, 0, data->lexer_check);
		return (i);
	}
	else
		return (0);
}
*/
int	ft_lexer_alpha(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = data->lexer_check;
	while (data->prompt[j + i])
	{
		if (data->lexer_char == '|' || data->lexer_char == '<'
			|| data->lexer_char == '>' || !ft_isspace(data->lexer_char)
			|| data->lexer_char == '\'' || data->lexer_char == '\"')
			break ;
		i++;
		lexer_advance(data);
	}
	implement_list(data, TOKEN_STRING, i, j);
	data->index_lexer++;
	return (0);
}
