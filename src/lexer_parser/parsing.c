#include "../../includes/minishell.h"

int	ft_parse_pipe(t_data *data, int index)
{
	int	last;

	last = ft_lstsize(data->s_lex) - 1;
	if (index == 0 || index == last)
		return (ft_error_parsing("syntax error near unexpected token `|'"
					, data));
	return (0);
}

int	ft_parse_redir(t_data *data, int index)
{
	int	last;

	last = ft_lstsize(data->s_lex) - 1;
	if (index == last)
		return (ft_error_parsing("syntax error near unexpected token `newline'"
					, data));
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
			if (ft_parse_redir(data, tmp->index))
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
