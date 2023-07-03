/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:30:12 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/03 16:11:13 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	implement_list(t_data *data, int type, int index, int start)
{
	t_list	*new;
	int		i;

//	if (!data->s_lex)
//		data->s_lex = ft_calloc(sizeof(t_list), 1);
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
	ft_lstadd_back(&data->s_lex, new);
	new->next = (NULL);
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
		else if (data->lexer_char == '$')
			get_dollar(data);
		if (data->lexer_char == '<' || data->lexer_char == '>')
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
		else if (data->lexer_char)
		{
			if (ft_lexer_alpha(data))
				return (1);
		}
	}
	return (0);
}

void	init_lexer(t_data *data)
{
	data->in_pipe = 0;
	data->index_cmd = 0;
	data->s_lex = NULL;
	data->index_lexer = 0;
	data->lexer_check = 0;
	data->lexer_char = data->prompt[data->lexer_check];
}
