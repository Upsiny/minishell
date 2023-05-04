/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:30:12 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/27 16:02:43 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	implement_list(t_data *data, int type, int index, int start)
{
	t_list	*new;
	int		i;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return ;
	i = 0;
	new->content = ft_calloc(sizeof(char), index + 1);
	if (!new->content)
		return ;
	while (i < index && data->prompt[start])
	{
		new->content[i] = data->prompt[start];
		i++;
		start++;
	}
	new->token_type = type;
	new->index = data->index_lexer;
	new->next = (NULL);
	ft_lstadd_back(&data->s_lex, new);
}

void	lexer_advance(t_data *data)
{
	if (data->prompt[data->lexer_check]
		&& data->lexer_check < (int)ft_strlen(data->prompt))
	{
		data->lexer_check ++;
		data->lexer_char = data->prompt[data->lexer_check];
	}
}

int	lexer_work(t_data *data)
{
	while (data->lexer_check < (int)ft_strlen(data->prompt))
	{
		if (data->lexer_char == '\"' || data->lexer_char == '\'')
		{
			if (ft_lexer_quotes(data))
				return (1);
		}
		else if (data->lexer_char == '<' || data->lexer_char == '>')
		{
			if (ft_lexer_redir(data))
				return (1);
		}
		else if (data->lexer_char == '|')
		{
			if (ft_lexer_pipe(data))
				return (1);
		}
		else if (!ft_isspace(data->lexer_char))
			lexer_advance(data);
		else
			ft_lexer_alpha(data);
	}
	return (0);
}

void	init_lexer(t_data *data)
{
	data->s_lex = ft_calloc(sizeof(t_list), 1);
	data->index_lexer = 0;
	data->lexer_check = 0;
	data->lexer_char = data->prompt[data->lexer_check];
}
