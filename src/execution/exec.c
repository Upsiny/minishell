/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:31:09 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/10 17:19:36 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	verif_cmd(char **all_path, char **pathcmd, char **cmd)
{
	char	*gd_path;
	int		i;
	int		z;


	i = 0;
	z = 0;
	gd_path = NULL;
	while (all_path[i])
	{
		gd_path = ft_strjoin(all_path[i], pathcmd[0]);
		if (access(gd_path, R_OK) == 0)
		{
			free(gd_path);
			return (0);
		}
		else
			i++;
		free(gd_path);
		z++;
	}
	if (z == i)
		aff_errcmd(cmd);
	return (0);
}

int	aff_errcmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
		{
			ft_print_error_msg3("minishell: ", cmd[0], ": No such file or directory\n");
			return (127);
		}
		i++;
	}
	ft_print_error_msg3("minishell: ", cmd[0], ": command not found\n");
	return (127);
}

void	ft_execve(t_data *data, char **all_path, char **pathcmd, char **cmd)
{
	char	*gd_path;
	int		i;
//	int		z;

	i = 0;
//	z = 0;
	gd_path = NULL;
	while (all_path[i])
	{
		gd_path = ft_strjoin(all_path[i], pathcmd[0]);
		if (access(gd_path, R_OK) == 0)
		{
			if (execve(gd_path, pathcmd, data->cp_env) == -1)
			{
				perror("Execve : ");
				exit(EXIT_FAILURE);
			}
		}
		else
			i++;
		free(gd_path);
//		z++;
	}
	(void)cmd;
	//if (z == i)
	//	aff_errcmd(cmd);
}

void	ft_execution(t_data *data, char **all_path, char **pathcmd, char **cmd)
{
	if(access(cmd[0], X_OK) == 0)
	{
		if(execve(cmd[0], pathcmd, data->cp_env) == -1)
		{
			perror("Execve : ");
			exit(EXIT_FAILURE);
		}
		return ;
	}
	if (verif_cmd(all_path, pathcmd, cmd) != 0)
	{
		free_tab(all_path);
		free_tab(pathcmd);
		exit(data->ret_err);
	}
	else
	{
		ft_execve(data, all_path, pathcmd, cmd);
		free_tab(all_path);
		free_tab(pathcmd);
	}
}
