/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 17:30:49 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_value_oldpwd(char **str, char *pwd, char *oldpwd)
{
    char	*name_var;
    int		i;
    int		y;

	i = 0;
	y = 0;
	while (oldpwd[y] != '=')
		y++;
	name_var = malloc(sizeof(char) * (y + 2));
	while (i <= y)
	{
		name_var[i] = oldpwd[i];
		i++;
	}
	name_var[i] = '\0';
	cpy_value(name_var, str, pwd);
	free(name_var);
}


void	change_value_pwd(char **str)
{
    char	*new_val;
    int		i;
    int		j;
    int		w;

	i = 0;
	j = 0;
	w = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
			break;
		i++;
	}
	j = recup_new_pwd(str);
	new_val = malloc(sizeof(char) * (j + 1));
	while (str[i][w] && w < j)
	{
		new_val[w] = str[i][w];
		w++;
	}
	new_val[w] = '\0';
	free(str[i]);
	str[i] = verif_pwd(new_val);
	free(new_val);
}

void	change_val(char **str, char *new_pwd, char *pwd, char *oldpwd)
{
	int	i;

	i = 0;
	change_value_oldpwd(str, pwd, oldpwd);
	while (str[i])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
			break;
		i++;
	}
	free(str[i]);
	str[i] = ft_strjoin("PWD=", new_pwd);
}

void	add_reponame(char **str, char *repo)
{
	char	*new_pwd;
	char	*all_addup;
	int		i;

	i = 0;
	new_pwd = NULL;
	while (str[i++])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
		{
			new_pwd = ft_strdup3(str[i]);
			break;
		}
	}
	free(str[i]);
	if (new_pwd[4] == '/' && new_pwd[5] == '\0')
		str[i] = ft_strjoin(new_pwd, repo);
	else
	{
		all_addup = ft_strjoin(new_pwd, "/");
		str[i] = ft_strjoin(all_addup, repo);
		free(all_addup);
	}
	free(new_pwd);
}

void	change_val_pwdpath(char **str, char **cmd)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_split(cmd[1], '/');
	while (path[i])
	{
		if (ft_strcmp(path[i], "..") == 0)
			change_value_pwd(str);
		if (ft_strcmp(path[i], "..") != 0 && ft_strcmp(path[i], ".") != 0)
			add_reponame(str, path[i]);
		i++;
	}
	free_tab(path);
}
