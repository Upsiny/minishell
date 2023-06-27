/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:18:20 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/27 14:33:40 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void	change_value_exp(t_data *data, char **cmd)
{
	if (cmd[1][0] == '/')
		change_val(data->cp_exp, cmd[1], pwd, oldpwd);
	else if ((ft_strncmp(cmd[1], ".", 1) == 0 || ft_strncmp(cmd[1], "./", 2)
		== 0))
		change_value_oldpwd(data->cp_exp, pwd, oldpwd);
	else if ((ft_strncmp(cmd[1], "..", 2) == 0 || ft_strncmp(cmd[1],
			"../", 3) == 0))
	{
		change_value_pwd(data->cp_exp);
		change_value_oldpwd(data->cp_exp, pwd, oldpwd);
	}
	else if (ft_strncmp(cmd[1], "./", 2) > 0
		|| ft_strncmp(cmd[1], "../", 3) > 0)
	{
		change_value_oldpwd(data->cp_exp, pwd, oldpwd);
		change_val_pwdpath(data->cp_exp, cmd);
	}
}

void	change_value_env(t_data *data, char **cmd)
{
	if (cmd[1][0] == '/')
		change_val(data->cp_env, cmd[1], pwd, oldpwd);
	else if ((ft_strncmp(cmd[1], ".", 1) == 0 || ft_strncmp(cmd[1], "./", 2)
		== 0))
		change_value_oldpwd(data->cp_env, pwd, oldpwd);
	else if ((ft_strncmp(cmd[1], "..", 2) == 0 || ft_strncmp(cmd[1],
			"../", 3) == 0))
	{
		change_value_pwd(data->cp_env);
		change_value_oldpwd(data->cp_env, pwd, oldpwd);
	}
	else if (ft_strncmp(cmd[1], "./", 2) > 0
		|| ft_strncmp(cmd[1], "../", 3) > 0)
	{
		change_value_oldpwd(data->cp_env, pwd, oldpwd);
		change_val_pwdpath(data->cp_env, cmd);
	}
}*/

void	get_pwd(t_data *data)
{
	int		i;

	i = 0;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "PWD=", 4) == 0)
		{
			data->pwd = ft_strdup3(data->cp_env[i]);
			break ;
		}
		i++;
	}
	i = 0;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], "OLDPWD=", 7) == 0)
		{
			data->old_pwd = ft_strdup3(data->cp_env[i]);
			break ;
		}
		i++;
	}
}

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
