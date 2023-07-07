/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:50 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 18:46:48 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_option(char **cmd)
{
	int	i;

	i = 2;
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
	if (!cmd[1] || cmd[1] == NULL || cmd[1][0] == '\0')
		{
			printf("\n");
			return ;
		}
	if ((ft_strncmp((cmd[1]), "-n", 2)) == 0 && ft_strlen(cmd[1]) == 2)
		check_option(cmd);
	else if (ft_strlen(cmd[0]) == 4)
		while (cmd[i] && cmd[i][0] != '\0' && (cmd[i][0] >= 32
				&& cmd[i][0] <= 126))
		{
	//		if (cmd[i][0] == '$')
	//			i++;
			if (cmd[i + 1] != NULL)
					printf("%s ", cmd[i]);
			else
					printf("%s\n", cmd[i]);
			i++;
		}
	return ;
}
