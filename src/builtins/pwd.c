/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:43:16 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/08 15:56:53 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_builtin(void)
{
	char	*cwd;

	cwd = getcwd(NULL, sizeof(char *));
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		cwd = free_ptr(cwd);
	}
	else
		perror("pwd");
}
