/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:13 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 18:09:20 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
char	*search_in_env(t_data *data, char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	while (data->cp_env[i])
	{
		if (ft_strncmp(data->cp_env[i], str, ft_strlen(str)) == 0)
		{
			cpy = ft_strdup3(data->cp_env[i] + ft_strlen(str) + 1);
			if (!cpy)
				return (NULL);
			break ;
		}
		i++;
	}
	return (cpy);
}
*/

char	*search_in_env(t_data *data, char *str) {
	
	int i = 0;
	char**	env = data->cp_env;
	
	while (env[i] && ft_strncmp(env[i], str, ft_strlen(str)))
		i++;
	return ft_strchr(env[i], '=') + 1;
}


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
			printf("index : %d | ", data->s_lex->index);
			printf("token type : %d | ", data->s_lex->token_type);
			printf("len : (%zu) | ", ft_strlen(data->s_lex->content));
			printf("content : %s\n", data->s_lex->content);
		}
		else
			printf("NULL\n");
		data->s_lex = data->s_lex->next;
	}
}
