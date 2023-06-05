#include "../../includes/minishell.h"

int	ft_parse_pipe(t_data *data, int index)
{
	int	last;

	last = ft_lstsize(data->s_lex) - 1;
	if (index == 0 || index == last)
		return (1);
	return (0);
}

void	ft_check_lst(t_data *data)
{
	t_list	*tmp;

	tmp = data->s_lex;
	//tmp = tmp->next;
	while (tmp)
	{
		if (tmp->token_type == TOKEN_PIPE && tmp->content)
		{
			if (ft_parse_pipe(data, tmp->index))
			{
				ft_error_parsing("syntax error near unexpected token `|'");
				return ;
			}
		}
		tmp = tmp->next;
	}
}
