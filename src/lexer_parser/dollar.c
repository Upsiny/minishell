/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:18:37 by hguillau          #+#    #+#             */
/*   Updated: 2023/07/03 16:24:58 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_prompt(t_data *data, char *value, int start, int end)
{
	char	*first_part;
	char	*last_part;
	char	*new_prompt;
	int		i;
	int		j;

	i = 0;
	j = end;
	first_part = malloc(start + 1 * sizeof(char *));
	last_part = malloc((ft_strlen(data->prompt) - end + 1) * sizeof(char *));
	if (!value)
		value = "";
	while (i < start)
	{
		first_part[i] = data->prompt[i];
		i++;
	}
	i = 0;
	while (data->prompt[j])
	{
		last_part[i] = data->prompt[j];
		i++;
		j++;
	}
	new_prompt = ft_strdup3(first_part);
/*	if (!ft_strcmp(value, ""))
		new_prompt = ft_strjoin(new_prompt, "");
	else*/
	new_prompt = ft_strjoin(new_prompt, value);
	new_prompt = ft_strjoin(new_prompt, last_part);
//	printf("first part : %s\n", first_part);
//	printf("new_promp : %s\n", new_prompt);
	data->prompt = ft_strdup3(new_prompt);
	free(new_prompt);
	free(first_part);
	free(last_part);
}

int	ft_isinside(char c)
{
	int	i;

	i = 0;
	while (DOLLAR_STOP[i])
	{
		if (DOLLAR_STOP[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	get_dollar(t_data *data)
{
	int		i;
	int		j;
	int		k;
	char	*dol_value;
	i = data->lexer_check;
	j = 0;
	k = 1;
	while (data->prompt[i + j])
	{
		j++;
		if (!ft_isspace(data->prompt[i + j]) || !ft_isinside(data->prompt[i+j]))
			break ;
	//	lexer_advance(data);
	}
	dol_value = malloc(j * sizeof(char *));
	while (k < j)
	{
		dol_value[k - 1] = data->prompt[i + 1];
		k++;
		i++;
	}
//	printf("valeur dollar : %s\n", dol_value);
	replace_prompt(data, getenv(dol_value), data->lexer_check, data->lexer_check + j);
//	printf("%s\n", getenv(dol_value)); //remplacer par un autre getenv
	free(dol_value);
}
