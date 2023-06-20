/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:22:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/20 16:23:06 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd_error(char *arg)
{
	write(2, "bash: cd: ", 10);
	printf("Error: cannot change directory to %s\n", arg);
	perror(arg);
	return (1);
}

void	cd_go_arg(char *arg)
{
	if (chdir(arg) == -1)
	{
		cd_error(arg);
		arg = free_ptr(arg);
		return ;
	}
}

void	cd_go_home(t_data *data)
{
	if (chdir(data->val_home) == -1)
	{
		cd_error(data->val_home);
		//test = free_ptr(test);
		return ;
	}	
}

void	cd_builtin(t_data *data, char **cmd)
{
	get_pwd(data);
	//printf("%s\n%s\n%s\n", data->pwd, data->old_pwd, data->val_home); //DEBUG
	if (cmd[1] == NULL || (cmd[1][0] == '~'
		&& cmd[1][1] == '\0'))
		cd_go_home(data);
	else
		cd_go_arg(cmd[1]);
	free_ptr(data->pwd);
	free_ptr(data->old_pwd);
}
