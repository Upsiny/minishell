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
