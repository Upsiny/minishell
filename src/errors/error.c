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

void	error_lexer(t_data *data, char *msg)
{
	(void)data;
	printf("%s\n", msg);
//	data->prompt = "";
//	data->index_lexer = 0;
//	data->lexer_check = 0;
//	data->lexer_char = data->prompt[data->lexer_check];
//	free(data->s_lex);
}

int	ft_error_parsing(char *msg, t_data *data)
{
	printf("%s\n", msg);
	free_ptr(data->s_lex);
	return (1);
}

void	ft_error_msg(char *msg)
{
	printf("%s\n", msg);
	exit(0);
}
