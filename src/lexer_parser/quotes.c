#include "../../includes/minishell.h"

void	ft_double_quotes(t_data *data, int index)
{
	// travail avec les token : init du token d_quotes
}

void	ft_simple_quotes(t_data *data, int index)
{
	// travail avec les token : init du token s_quote
	// atttention a la signification du simple quote
}

void	verif_cmdquotes(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(data->prompt);
	while (i <= j)
	{
		if (str[i] == '"')
			ft_double_quotes(data, i);
		else if (str[i] == ''')
			ft_simple_quotes(data, i);
		i++;
	}
}
