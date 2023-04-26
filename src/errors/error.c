/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:24:09 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/26 15:37:55 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//ne pas oublier de recuperer dans le bash les numeros derreur pour que les erreurs de minishell coincident au bash;

void	ft_error_msg(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}
