/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:37:02 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/16 16:15:43 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	verif_arg_exit(t_data *data, int i, char **cmd)
{
	
}

void	exit_builtin(t_data *data, char **cmd)
{
	int	j;

	j = ft_count_list(data->s_lex);
	if (ft_strncmp(cmd[0], "exit", 4) == 0)
	{
		if (cmd[1] == NULL)
		{
			if (j == 1)
				printf("exit\n");
			exit(0);
		}
		else
			verif_arg_exit(data, 1, cmd);
	}
}
