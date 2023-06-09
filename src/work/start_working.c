/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_working.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:09:10 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/11 19:53:49 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*int	ft_str(char *content, t_data *data)
{
	char	**cmd;

	cmd = ft_split(content, ' ');
	cmd = verif_cmd_struct(cmd);
	redir_builtins_or_execve(data, cmd);
}

int	start_work(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp2;
	
	tmp = data->s_lex;
	tmp2 = tmp;
	while (tmp->next)
	{
		if (tmp->token_type == TOKEN_PIPE)
		{
			data->in_pipe = 1;
			if (ft_piping(data))
				return 1;
			tmp2 = tmp;
			tmp2 = tmp2->next;
			tmp = data->s_lex;
			while (tmp->next)
			{
				if (tmp->token_type == TOKEN_STRING)
				{
					if (ft_str(tmp->content, data))
						return (1);
					tmp = tmp2;
				}
			}
		}
		if (tmp->next == NULL && data->in_pipe == 0)
			tmp = data->s_lex;
	}
	while (tmp->next)
	{
		if (tmp->token_type == TOKEN_STRING)
		{
			if (ft_str(tmp->content, data))
				return (1);
			break;
		}
	}
	return (0);
}

int	pre_start_work(t_data *data)
{
	int	ret;

	ret = 0;
	data->nb_cmds = ft_count_list(data->s_lex);
	ret = start_work(data);
	return (ret);
}
*/