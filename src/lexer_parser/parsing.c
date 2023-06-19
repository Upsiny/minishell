/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:59 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/14 17:24:00 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_parse_pipe(t_data *data, int index)
{
	int	last;

	last = ft_lstsize(data->s_lex) - 1;
	if (index == 0 || index == last)
		return (ft_error_parsing("syntax error near unexpected token `|'"));
	return (0);
}

int	ft_parse_redir(t_data *data, int index, t_list *tmp)
{
	int	last;

	last = ft_lstsize(data->s_lex) - 1;
	if (index == last)
		return (ft_error_parsing("syntax error near unexpected token `newline'"
				));
	else if (tmp->next->token_type == TOKEN_REDIR)
	{
		printf("syntax error near unexpected token `%s'", tmp->next->content);
		return (ft_error_parsing(""));
	}
	return (0);
}

int	ft_check_lst(t_data *data)
{
	t_list	*tmp;

	tmp = data->s_lex;
	while (tmp)
	{
		if (tmp->token_type == TOKEN_PIPE && tmp->content)
		{
			if (ft_parse_pipe(data, tmp->index))
				return (1);
		}
		if (tmp->token_type == TOKEN_REDIR)
		{
			if (ft_parse_redir(data, tmp->index, tmp))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
