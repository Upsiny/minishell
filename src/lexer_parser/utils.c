/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/25 15:56:12 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}

void	print_list(t_data *data)
{
	printf("lexer result : \n");
	while (data->s_lex)
	{
		if (data->s_lex->content)
		{
			printf("(%zu) ", ft_strlen(data->s_lex->content));
			printf("%s\n", data->s_lex->content);
		}
		data->s_lex = data->s_lex->next;
	}
}
