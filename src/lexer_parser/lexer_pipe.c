#include "../../includes/minishell.h"

void	ft_lexer_pipe(t_data *data)
{
	int	j;

	j = data->lexer_check;
	if (data->prompt[j + 1] == data->lexer_char)
		error_lexer(data, "Syntax Error");
	else
	{
		implement_list(data, TOKEN_PIPE, 1, j);
		data->index_lexer++;
		lexer_advance(data);
	}
}
