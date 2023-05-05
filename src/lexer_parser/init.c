/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:27 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/05 14:41:25 by tpaufert         ###   ########.fr       */
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
		printf("...");
	else
		data->cp_env = ft_tabcpy(envp);
	data->pid = -1;
	return (data);
}
