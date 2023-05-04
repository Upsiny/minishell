/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:22:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/04 13:50:02 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd(const char *path)
{
	if (chdir(path) != 0)
	{
		printf("Error: cannot change directory to %s\n", path);
	}
}
