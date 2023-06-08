/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:22:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/08 15:57:00 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd_error(char *arg)
{
	write(2, "bash: cd: ", 10);
	printf("Error: cannot change directory to %s\n", arg);
	perror(arg);
	return (1);
}

void	cd_go_arg(char *arg)
{
	if (chdir(arg) == -1)
	{
		cd_error(arg);
		arg = free_ptr(arg);
		return ;
	}
}

void	cd_go_home(void)
{
	char	*test;

	test = ft_strdup("/Users/tpaufert");
	if (chdir(test) == -1)
	{
		cd_error(test);
		test = free_ptr(test);
		return ;
	}	
}

void	cd_builtin(char **cmd)
{
	if (cmd[1] == NULL || (cmd[1][0] == '~'
		&& cmd[1][1] == '\0'))
		cd_go_home();
	else
		cd_go_arg(cmd[1]);
}
