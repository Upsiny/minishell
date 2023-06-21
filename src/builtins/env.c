/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:55:59 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/21 14:33:54 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	if_path_exist(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_tab_len(data->cp_env);
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (len != i)
		return (1);
	else
		return (0);
}

void	env_builtin(t_data *data, char **cmd)
{
	int	i;

	i = 0;
	if (!if_path_exist(data))
		{
			write(2, "minishell :", 11);
			write(2, &cmd[0], ft_strlen(cmd[0]));
			write(2, ": No such file or directory\n", 28);
			data->ret_err = 127;
			return ;
		}
	if (cmd[1])
		{
			write(2, "env :", 5);
			write(2, "'", 1);
			write(2, &cmd[1], ft_strlen(cmd[1]));
			write(2, "': No such file or directory\n", 29);
			data->ret_err = 127;
			return ;
		}
	while (data->cp_env[i])
		printf("%s\n", data->cp_env[i++]);
	data->ret_err = 0;
}
