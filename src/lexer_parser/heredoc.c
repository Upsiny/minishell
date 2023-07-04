/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:17:27 by hguillau          #+#    #+#             */
/*   Updated: 2023/07/04 13:29:45 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_heredoc(t_list *tmp, t_data *data)
{
	t_list	*tmp2;
	char	*heredoc;

	tmp2 = tmp;
	if (tmp2->next->token_type != TOKEN_STRING
		&& tmp2->next->token_type != TOKEN_SQUOTE
		&& tmp2->next->token_type != TOKEN_DQUOTE)
	{
		printf("parse error near `%s'", tmp->next->content);
		ft_error_parsing("");
	}
	else
	{
		while (1)
		{
			heredoc = readline(">");
			if (!ft_strcmp(heredoc, tmp2->next->content))
				break ;
			if (!data->content_here)
				data->content_here = ft_strdup3(heredoc);
			else
				data->content_here = ft_strjoin(data->content_here, heredoc);
			data->content_here = ft_strjoin(data->content_here, "\n");
			free(heredoc);
		}
	}
	//printf("%s", data->content_here);
}
