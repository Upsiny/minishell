#include "../../includes/minishell.h"

int	ft_count_until_change(t_list s_lex, int start)
{
	t_list	*tmp;
	int		i;

	tmp = s_lex;
	i = 0;
	while (tmp->index < start)
		tmp->next;
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
	int		size_content;
	
	tmp = data->s_lex;
	j = 0;
	i = ft_count_until_change(s_lex, data->index_cmd);
	data->st_cmd->cmd = malloc(i + 1 * sizeof(char *));
	while (tmp->index < i)
	{
		data->st_cmd->cmd[j] = ft_strjoin(data->st_cmd->cmd, tmp->content);
		tmp->next;
		if (tmp->next->token_type == TOKEN_REDIR
			|| tmp->next->token_type == TOKEN_PIPE)
		{
			j++;
			data->st_cmd->cmd[j] == ft_strdup333(tmp->next->content);
			tmp->next;
			j++;
		}
		else if (tmp->next != NULL)
			data->st_cmd->cmd[j] = ft_strjoin(data->st_cmd->cmd, ' ');
	}
}
