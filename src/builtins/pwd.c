/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:43:16 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 18:44:03 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_builtin(t_data *data, char **cmd)
{
	int	i;

	i = 0;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
		{
			while (data->cp_env[i])
			{
				data->ret_err = 0;
				printf("%s\n", data->cp_env[i] + 4);
				return ;
			}
		}
		i++;
	}
	if (i == ft_tab_len(data->cp_env))
	{
		data->ret_err = 127;
		ft_print_error_msg3("minishell: ", cmd[0],
			": No such file or directory\n");
		return ;
	}
	data->ret_err = 0;
}
