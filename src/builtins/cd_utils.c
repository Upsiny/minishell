/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:18:20 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 17:25:32 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void change_value_exp(t_data *data, char **cmd)
{
    if (cmd[1][0] == '/')
        change_val(data->cp_exp, cmd[1], data->pwd, data->oldpwd);
    else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./") == 0)
        change_value_oldpwd(data->cp_exp, data->pwd, data->oldpwd);
    else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1], "../") == 0)
    {
        change_value_pwd(data->cp_exp);
        change_value_oldpwd(data->cp_exp, data->pwd, data->oldpwd);
    }
    else if ((ft_strcmp(cmd[1], "./") > 0 || ft_strcmp(cmd[1], "../") > 0))
    {
        change_value_oldpwd(data->cp_exp, data->pwd, data->oldpwd);
        change_val_pwdpath(data->cp_exp, cmd);
    }
}

void change_value_env(t_data *data, char **cmd)
{
    if (cmd[1][0] == '/')
        change_val(data->cp_env, cmd[1], data->pwd, data->oldpwd);
    else if (ft_strcmp(cmd[1], ".") == 0 || ft_strcmp(cmd[1], "./") == 0)
        change_value_oldpwd(data->cp_env, data->pwd, data->oldpwd);
    else if (ft_strcmp(cmd[1], "..") == 0 || ft_strcmp(cmd[1], "../") == 0)
    {
        change_value_pwd(data->cp_env);
        change_value_oldpwd(data->cp_env, data->pwd, data->oldpwd);
    }
    else if ((ft_strcmp(cmd[1], "./") > 0 || ft_strcmp(cmd[1], "../") > 0))
    {
        change_value_oldpwd(data->cp_env, data->pwd, data->oldpwd);
        change_val_pwdpath(data->cp_env, cmd);
    }
}

char *get_env_value(char **env, const char *var)
{
    int i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
            return ft_strdup3(env[i]);
        i++;
    }
    return NULL;
}

void get_pwd(t_data *data)
{
    data->pwd = ft_strdup3(get_env_value(data->cp_env, "PWD="));
    data->oldpwd = ft_strdup3(get_env_value(data->cp_env, "OLDPWD="));
}
