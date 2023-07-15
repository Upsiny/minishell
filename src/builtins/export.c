/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:22:09 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 18:29:20 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Vérifie si une variable existe déjà dans l'environnement
int	variable_exists(char **env, char *variable)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (variable[j] != '=' && variable[j] != '\0')
		j++;
    while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], variable, j) == 0)
			return (1);
	i++;
	}
	return (0);
}

void	update_variable(char **env, char *variable)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (variable[j] != '=' && variable[j] != '\0')
		j++;
	while (env[i] != NULL) 
	{
		if (ft_strncmp(env[i], variable, j) == 0)
		{
			free(env[i]);
			env[i] = ft_strdup3(variable);
			if (env[i] == NULL)
				return;
		}
		i++;
	}
}

// Ajoute une variable à l'environnement
void	add_variable(char ***env, char *variable)
{
	int		count;
	char	**new_env;
	int		i;
//	int		j;

	i = 0;
//	j = 0;
	count = count_variables(*env);
	new_env = malloc(sizeof(char *) * (count + 2));
	if (new_env == NULL)
		return ;
	while (i < count)
	{
		new_env[i] = ft_strdup3((*env)[i]);
		if (new_env[i] == NULL)
		{
			free_tab(new_env);
			return ;
		}
		i++;
	}
	new_env[count] = ft_strdup3(variable);
	if (new_env[count] == NULL)
	{
		free_tab(new_env);
		return ;
	}
	new_env[count + 1] = NULL;
	// Libérer l'ancien environnement et mettre à jour le pointeur
	i = 0;
	while ((*env)[i] != NULL)
	{
		free((*env)[i]);
		i++;
	}
	free(*env);
	*env = new_env;
}

// Fonction principale pour exporter une variable
void	export_builtin2(t_data *data, char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i] != NULL)
	{
		/*if (check_var(cmd[i]) || cmd[1][0] == '\0')
		{
			ft_print_error_msg3("minishell: export: `",
				cmd[1], "': not a valid identifier\n");
			data->ret_err = 1;
			return ;
		}
		else*/ if (is_valid_exp(cmd[1]) && is_valid_exp2(cmd[1]))
		{
			ft_print_error_msg3("minishell: export: `",
				cmd[1], "': not a valid identifier\n");
			data->ret_err = 1;
		}		
		else if (variable_exists(data->cp_env, cmd[i]))
			update_variable(data->cp_env, cmd[i]);
		else
			add_variable(&(data->cp_env), cmd[i]);
		i++;
	}
}

void	export_builtin(t_data *data, char **cmd)
{
	if (cmd[1] == NULL)
	{
		print_export(data->cp_exp);
	}
	else
	{
		export_builtin2(data, cmd);
		free_tab(data->cp_exp);
		data->cp_exp = order_exp(data->cp_env);
		data->ret_err = 0;
	}
}
