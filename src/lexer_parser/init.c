/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:27 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 13:10:28 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/lexer_parser.h"
#include "../../includes/minishell.h"

char	**ft_tabcpy(char **tab)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	tmp = malloc(sizeof(char *) * (j + 1));
	while (tab[i])
	{
		tmp[i] = ft_strdup3(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

t_data	*init_struct(char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		ft_error_msg("malloc error");
	data->st_cmd = malloc(sizeof(data->st_cmd));
	if (!data->st_cmd)
		ft_error_msg("malloc error");
	if (envp[0] == NULL)
		printf("No envp. get only new pwd and the old.");
	else
		data->cp_env = ft_tabcpy(envp);
	data->cp_exp = ft_cpytab(data->cp_env);
	data->cp_exp = order_exp(data->cp_exp);
	data->content_here = NULL;
//	int i = 0;
/*	while (data->cp_env[i])
	{
		printf("%s\n", data->cp_env[i]);
		i ++;
	}
	printf("\n\n\n");
	i = 0;
	while (data->cp_exp[i])
	{
		printf("%s\n", data->cp_exp[i]);
		i ++;
	}*/
	data->pid = -1;
	data->in_pipe = 0;
	data->ret_err = 0;
	data->val_home = get_home_value(data->cp_env);
	data->pwd = NULL;
	data->old_pwd = NULL;
	return (data);
}
