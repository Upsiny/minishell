/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:38:10 by hguillau          #+#    #+#             */
/*   Updated: 2023/07/03 16:24:53 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_until_change(t_list *s_lex, int start)
{
	t_list	*tmp;
	int		i;

	tmp = s_lex;
	i = 0;
	while (tmp->index < start)
		tmp = tmp->next;
	while (tmp->next)
	{
		if (tmp->token_type == TOKEN_REDIR || tmp->token_type == TOKEN_PIPE)
			return (i);
		i++;
	}
	return (i);
}

void	start_expend(t_data *data)//fait une liste de char** pour aider thomas a l'execution
{
	t_list	*tmp;
	int		i;
	int		j;
	
	tmp = data->s_lex;
	j = 0;
	i = ft_count_until_change(data->s_lex, data->index_cmd);
	data->st_cmd->cmd = malloc(i + 1 * sizeof(char *));
	while (tmp->index < i)
	{
		data->st_cmd->cmd[j] = ft_strjoin(*data->st_cmd->cmd, tmp->content);
		tmp = tmp->next;
		if (tmp->next->token_type == TOKEN_REDIR
			|| tmp->next->token_type == TOKEN_PIPE)
		{
			j++;
			if (tmp->next->token_type == TOKEN_PIPE)
				data->in_pipe++;
			data->st_cmd->cmd[j] = ft_strdup3(tmp->next->content);
			tmp = tmp->next;
			j++;
		}
		else if (tmp->next != NULL)
			data->st_cmd->cmd[j] = ft_strjoin(*data->st_cmd->cmd, " ");
	}
}
