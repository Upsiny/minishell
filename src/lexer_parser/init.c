/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:11:27 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/18 16:27:33 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/lexer_parser.h"
#include "../../includes/minishell.h"

t_data	*init_struct(char **envp)
{
	t_data	*data;

    data = malloc(sizeof(t_data));
    if (envp[0] == NULL)
        printf("...");
    data->pid = -1;
	return (data);
}
