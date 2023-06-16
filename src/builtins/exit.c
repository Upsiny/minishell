/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:37:02 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/16 18:11:26 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
void	exit_number_too_big(int i, char **cmd)
{
	write(2, "exit\nminishell: ", 16);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": ", 2);
	write(2, cmd[i], ft_strlen(cmd[i]));
	write(2, ": ", 2);
	write(2, "numeric argument required", 25);
	write(2, "\n", 1);
	exit(255);
}

void	exit_valid_number(t_data *data, int i, char **cmd)
{
	if (data->nb_cmds == 1)
		printf("exit\n");
	exit(ft_atoi(cmd[i]) % 256);
}

void	exit_not_numeric(int i, char **cmd)
{
	write(2, "exit\nminishell: exit: ", 22);
	write(2, cmd[i], ft_strlen(cmd[i]));
	write(2, ": ", 2);
	write(2, "numeric argument required", 25);
	write(2, "\n", 1);
	exit(255);
}

void	verif_arg_exit(t_data *data, int i, char **cmd)
{
	if (ft_str_is_digit(cmd[i]) == 1)
	{
		if (ft_check_len_exit(cmd[i]) == 1)
			exit_number_too_big(i, cmd);
		if (cmd[i + 1] == NULL)
			exit_valid_number(data, i, cmd);
		else
		{
			write(2, "exit\nminishell: exit: too many arguments\n", 41);
			data->ret_err = 1;
		}
	}
	else if (strdigit(cmd[i]) == 1)
		exit_not_numeric(i, cmd);
}
*/
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
		/*else
			verif_arg_exit(data, 1, cmd);*/
	}
}
