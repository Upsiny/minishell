/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:43:16 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/02 15:44:09 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(void)
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
