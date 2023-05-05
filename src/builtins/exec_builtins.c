/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:43:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/05 12:01:16 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtins(char **cmd)
{
	if ((ft_strncmp(cmd[0], "cd", 2)) == 0)
		cd(cmd);
	else if ((ft_strncmp(cmd[0], "pwd", 3)) == 0)
		pwd();
}
