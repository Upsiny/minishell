/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec_builtins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:43:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/28 16:29:05 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*recup_real_cmd(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	while (i != 0 && line[i] != '/')
		i--;
	tmp = malloc(sizeof(char) * ((ft_strlen(line) - i) + 1));
	i += 1;
	while (line[i])
	{
		tmp[j] = line[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*check_cmd(char *str)
{
	char	*real_cmd;
	int		nb_slash;

	nb_slash = ft_nb_slash(str);
	real_cmd = NULL;
	if (nb_slash >= 2)
	{
		if (str[0] == '/')
		{
			if (access(str, R_OK) == 0)
				real_cmd = recup_real_cmd(str);
			else
			{
				real_cmd = NULL;
				perror(NULL);
			}
		}
	}
	else if (nb_slash < 2)
		real_cmd = ft_strdup(str);
	return (real_cmd);
}

void	verif_and_modif_cmd_if_slash_or_quote(char **cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (cmd[0] == NULL)
		return ;
	while (cmd[i])
	{
		if (ft_strlen(cmd[i]) > 0 && (cmd[i][0] == '\'' || cmd[i][0] == '\"'))
		{
			cmd[i][ft_strlen(cmd[i]) - 1] = '\0';
			tmp = ft_strdup(&(cmd[i][1]));
			free(cmd[i]);
			cmd[i] = tmp;
		}
		i++;
	}
	tmp = cmd[0];
	cmd[0] = check_cmd(tmp);
	free(tmp);
}

char	**verif_cmd_struct(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		verif_and_modif_cmd_if_slash_or_quote(&cmd[i]);
		i++;
	}
	return (cmd);
}

// envoie une commande soit dans builtins, soit dans execve
void	redir_builtins_or_execve(t_data *data, char **cmd)
{
	verif_cmd_struct(cmd);
	if (cmd[0] == NULL)
			return ;
	if (ft_strcmp(ft_tolower(cmd[0]), "cd") == 0)
		cd_builtin(data, cmd);
	else if (ft_strcmp(ft_tolower(cmd[0]), "pwd") == 0)// a modifier en utilisant cp_env;
		pwd_builtin();
	else if (ft_strcmp(cmd[0], "exit") == 0)
		exit_builtin(data, cmd);
	else if (ft_strcmp(ft_tolower(cmd[0]), "echo") == 0)
		echo_builtin(cmd);
	else if (ft_strcmp(ft_tolower(cmd[0]), "env") == 0)
		env_builtin(data, cmd);
//	else if (ft_strcmp(ft_tolower(cmd[0]), "export") == 0)
//		export_builtin(data, cmd);
	else if (ft_strcmp(ft_tolower(cmd[0]), "unset") == 0)
		unset_builtin(data, cmd);
//	else
//		ft_set_path_and_execve(data, cmd);
}
