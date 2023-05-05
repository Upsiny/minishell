/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:17:23 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/05 15:04:16 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer_alpha(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->lexer_check;
	while (data->prompt[j + i])
	{
		if (data->lexer_char == '|' || data->lexer_char == '<'
			|| data->lexer_char == '>' || !ft_isspace(data->lexer_char))
			break ;
		i++;
		lexer_advance(data);
	}
	implement_list(data, TOKEN_STRING, i, j);
	data->index_lexer++;
}
