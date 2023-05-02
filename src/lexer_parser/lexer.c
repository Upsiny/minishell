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
	new->content = malloc(sizeof(char) * index);
	if (!new->content)
		return ;
	while (i != index)
	{
		i++;
		new->content[i - 1] = data->prompt[start];
		start++;
	}
	new->token_type = type;
	new->index = data->index_lexer;
	new->next = (NULL);
	new->prev = ft_lstlast(data->s_lex);
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

void	lexer_work(t_data *data)
{
	while (data->lexer_check < (int)ft_strlen(data->prompt))
	{
		if (ft_isalpha(data->lexer_char))
			ft_lexer_alpha(data);
		if (data->lexer_char == '\"' || data->lexer_char == '\'')
			ft_lexer_quotes(data);
		if (data->lexer_char == '<' || data->lexer_char == '>')
			ft_lexer_redir(data);
	/*	if (data->lexer_char == '-')
			ft_lexer_option(data);
		if (data->lexer_char == '$')
			ft_lexer_dollar(data);*/
		if (data->lexer_char == ' ')
			lexer_advance(data);
	}
}

void	init_lexer(t_data *data)
{
	data->index_lexer = 0;
	data->lexer_check = 0;
	data->lexer_char = data->prompt[data->lexer_check];
}
