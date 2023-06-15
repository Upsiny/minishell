#include "../../minishel.h"

int	ft_str(char *content, t_data *data)
{
	char	**cmd;

	cmd = ft_split(content, ' ');
	exec_builtins(data, cmd);
}

int	start_work(t_data *data)
{
	t_list	*tmp;

	tmp = data->s_lex;
	while (tmp->next)
	{
		if (tmp->token_type == TOKEN_STRING)
		{
			if (ft_str(tmp->contenti, data))
				return (1);
		}
		tmp->next;
	}
	return (0);
}
