#include "../../includes/minishell.h"

int	count_redir(t_data *data, char c)
{
	int i;
	int	j;

	i = 0;
	j = data->lexer_check;
	if (data->prompt[j + 1] == c)
	{
		while (data->prompt[j] == c)
		{
			i++;
			j++;
		}
		return (i);
	}
	else
	{
		return (1);
	}
}

void	ft_lexer_redir(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->lexer_check;
	if (count_redir(data, data->lexer_char) <= 2)
		i = count_redir(data, data->lexer_char);
	else
		error_lexer(data, "too many redir");
	implement_list(data, TOKEN_REDIR, i, j);
	data->index_lexer++;
	while (i--)
		lexer_advance(data);
}
