/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:43:16 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/02 14:55:17 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 2048);
	if (cwd != NULL)
		printf("%s\n", cwd);
	else
		perror("pwd");
	if (cwd)
		free(cwd);
}
