/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:41:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/28 15:31:19 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*free_ptr(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
    if (tab == NULL)
    	return ;
    while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
    }
    free(tab);
}
