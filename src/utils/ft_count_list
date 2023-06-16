/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_list                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:54:39 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/16 15:58:43 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_count_list(t_list *head)
{
    if (head == NULL)
	{
        return 0;
    }
	else
	{
        return 1 + ft_count_list(head->next);
    }
}
