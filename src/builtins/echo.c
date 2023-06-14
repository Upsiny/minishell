/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:50 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:30 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_option(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i] && cmd[i][0] != '\0' && (cmd[i][0] >= 32
				&& cmd[i][0] <= 126))
	{
		if (cmd[i + 1] != NULL)
				printf("%s ", cmd[i]);
		else
				printf("%s", cmd[i]);
		i++;
	}
	return ;
}

void	echo_builtin(char **cmd)
{
	int	i;

	i = 1;
	if (cmd[1] == NULL || cmd[1][0] == '\0')
		printf("\n");
	if ((ft_strncmp((cmd[1]), "-n", 2)) == 0)
		check_option(cmd);
	else
		while (cmd[i] && cmd[i][0] != '\0' && (cmd[i][0] >= 32
				&& cmd[i][0] <= 126))
		{
			if (cmd[i][0] == '$')
			{
				//found_dollar(cmd[i]);
				i++;
			}
			if (cmd[i + 1] != NULL)
					printf("%s ", cmd[i]);
			else
					printf("%s\n", cmd[i]);
			i++;
		}
	return ;
}
