/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:40:32 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/25 16:21:17 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*remove_double_char_quote(char *str, char c)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = NULL;
	i = 0;
	j = ft_strlen(str);
	return (new_line)
}

int	is_there_double_pipe(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len < 3)
		return (0);
	i = 2;
	while (i < len)
	{
		if (str[i - 2] == '|' && str[i - 1] == ' ' && str[i] == '|')
			return (1);
		else if (str[i - 2] == '|' && str[i - 1] == '|')
			return (1);
		i++;
	}
	return (0);
}

char	*verif_pipes(char *prompt)
{
	char	*new_prompt;
	int		len;

	new_prompt = NULL;
	new_prompt = remove_double_char_quote(prompt, ' ');
	free(prompt);
	len = ft_strlen(new_prompt);
	if (new_prompt[0] == '|' || is_there_double_pipe(new_prompt) == 1)
	{
		//message derreur + code derreur a gerer
		free(new_prompt);
		new_prompt = ft_calloc(1, sizeof(char));
		return (new_prompt);
	}
	if (new_prompt[len - 1] == '|')
	{
		//code derreur a chercher et afficher
		write(2, "minishell: syntax error `|'\n", 50);
		free(new_prompt);
		new_prompt = ft_calloc(1, sizeof(char));
		return (new_prompt);
	}
	return (new_prompt);
}
