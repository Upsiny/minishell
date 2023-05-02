/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:17:23 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_alpha(t_data *data)
{
	int	i;
	int j;

	i = 0;
	j = data->lexer_check;
	while (data->prompt[j + i])
	{
		if (data->lexer_char == '\'' || data->lexer_char == '\"'
			|| data->lexer_char == '|' || data->lexer_char == '<'
			|| data->lexer_char == '>') //ajouter les whitespace
			break ;
		i++;
		lexer_advance(data);
	}
	implement_list(data, TOKEN_STRING, i, j);
	data->index_lexer++;
}
