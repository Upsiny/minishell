/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:22:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 17:20:09 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_home_value(char	**cp_env)
{
	char	*home;
	int		i;
	int		j;
	int		z;

	i = 0;
	j = 0;
	z = 0;
	while (cp_env && cp_env[i++])
	{
		if (ft_strncmp(cp_env[i], "HOME=", 5) == 0)
			break ;
	}
	home = malloc(sizeof(char) * (ft_strlen(cp_env[i]) + 1));
	while (cp_env && cp_env[i][j] != '=')
		j++;
	j++;
	while (cp_env && cp_env[i][j])
	{
		home[z] = cp_env[i][j];
		j++;
		z++;
	}
	home[z] = '\0';
	return (home);
}

int	cd_error_arg(char *arg)
{
	write(2, "bash: cd: ", 10);
	ft_print_error_msg2(arg, ": No such file or directory%s\n");
	return (1);
}

int	cd_go_arg(char *arg)
{
	if (chdir(arg) == -1)
	{
		cd_error_arg(arg);
		return (0);
	}
	else
		return (1);
}

void	cd_builtin(t_data *data, char **cmd)
{
	get_pwd(data);
	if (cmd[1] == NULL || (cmd[1][0] == '~'
		&& cmd[1][1] == '\0'))
	{
		free_ptr(data->pwd);
		free_ptr(data->oldpwd);
		return ;
	}
	else if (cd_go_arg(cmd[1]) == 0)
	{
		data->ret_err = 1;
		free_ptr(data->pwd);
		free_ptr(data->oldpwd);
	}
	else
	{
		change_value_env(data, cmd);
		change_value_exp(data, cmd);
		free_ptr(data->pwd);
		free_ptr(data->oldpwd);
		data->ret_err = 0;
	}
}
