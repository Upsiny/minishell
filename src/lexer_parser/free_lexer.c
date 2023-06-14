/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:40 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:41 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_lst(t_data *data)
{
	t_list	*next;

	next = data->s_lex;
	while(next)
	{
		next = data->s_lex->next;
		free(data->s_lex->content);
		free(data->s_lex);
		data->s_lex = next;
	}
}
