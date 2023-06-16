/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:10:59 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/16 15:31:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*int		ft_pipes_create(t_data data)
{
	
}*/

void	piping(t_data *data)
{
	int		**pp;
	pid_t	pid;
	int		i;

	i = 0;
	/*pp = ft_pipes_create(data);
	while (data->s_lex->next)
	{
		if (pipe(pp[i]) == -1)
			perror("pipe: ");
		pid = fork();
		data->pid = pid;
		if (pid == -1)
			exit (127);
		if (pid == 0)
			ft_child(data, pp, i);
		else
			ft_parent(pp, i);
		i++;
	}
	ft_last_command(data, pp, i);
	ft_wait_all();
	free_tab((char **)pp);*/
}

void	pipes_redir(t_data *data)
{
	if (cmd[0]->cmd[0] == NULL && cmd[0]->stdin[0] == NULL
		&& cmd[0]->stdout[0] == NULL)
		return ;
	else
		piping(data);
}
