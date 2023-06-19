/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:37:58 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/04 14:23:47 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_lexer_pipe(t_data *data)
{
	int	j;

	j = data->lexer_check;
	if (data->prompt[j + 1] == data->lexer_char)
	{
		error_lexer("syntax error near unexpected token `||'");
		return (1);
	}
	else
	{
		implement_list(data, TOKEN_PIPE, 1, j);
		data->index_lexer++;
		lexer_advance(data);
		return (0);
	}
}
