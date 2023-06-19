/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:37:02 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/19 16:42:05 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_str_is_digit(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		if (str[0] == '-' || str[0] == '+')
		i++;
		while (str[i] && ft_isdigit(str[i]) == 1)
			i++;
	}
	if (str && i == ft_strlen(str))
		return (1);
	else
		return (0);
}

int	ft_check_len_exit(char *str)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (str)
	{
		if (str[0] == '-' || str[0] == '+')
			sign = 1;
		while (str[i])
			i++;
	}
	i = i - sign;
	if (str && i <= 19)
			return (1);
	else
		return (0);
}

void	exit_not_numeric(int i, char **cmd)
{
	write(2, "exit\nminishell: exit: ", 22);
	write(2, cmd[i], ft_strlen(cmd[i]));
	write(2, ": numeric argument required\n", 28);
	exit(255);
}

void	verif_arg_exit(t_data *data, int i, char **cmd)
{
	if (ft_str_is_digit(cmd[i]) == 1)
	{
		if (ft_check_len_exit(cmd[i]) == 0)// a faire
		{
			write(2, "exit\nminishell: ", 16);
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, ": ", 2);
			write(2, cmd[i], ft_strlen(cmd[i]));
			write(2, ": numeric argument required\n", 28);
			exit(255);
		}
		if (cmd[i + 1] == NULL && data->nb_cmds == 1)
		{
			printf("exit\n");
			exit(ft_atoi(cmd[i]) % 256);
		}
		else
		{
			write(2, "exit\nminishell: exit: too many arguments\n", 41);
			data->ret_err = 1;
		}
	}
	else if (ft_str_is_digit(cmd[i]) == 0)
		exit_not_numeric(i, cmd);
}

void	exit_builtin(t_data *data, char **cmd)
{
	int	j;

	j = ft_count_list(data->s_lex);
	if (ft_strncmp(cmd[0], "exit", 4) == 0 && ft_strlen(cmd[0]))
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
