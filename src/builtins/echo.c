/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:10:50 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/13 16:27:01 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	echo_builtin(char **cmd)
{
	int	i;

	i = 1;
	if (cmd[1] == NULL || cmd[1][0] == '\0')
		printf("\n");
	//if (cmd[1][0] == '-')
	//	check_option(cmd);
	while (cmd[i] && cmd[i][0] != '\0' && (cmd[i][0] >= 32
			&& cmd[i][0] <= 126))
	{
		if (cmd[i + 1] != NULL)
				printf("%s ", cmd[i]);
		else
				printf("%s\n", cmd[i]);
		i++;
	}
	return ;
}
