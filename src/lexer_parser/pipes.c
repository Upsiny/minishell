/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:40:32 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/02 15:52:24 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//est-ce que le char de str[i] est dans des quotes fermes ou non:
int	ft_closed_quote(char *s, int i)
{
	int	closed_quote;
	int	j;

	closed_quote = 0;
	j = 0;
	while (j <= i)
	{
		if (s[j] == '\'' || s[j] == '"')
			closed_quote = (closed_quote + 1) % 2;
		j++;
	}
	return (closed_quote);
}

//supprime les char en double qui ne sont pas dans les doubles quotes:
char	*remove_double_char_quote(char *str, char c)
{
	char	*new_line;
	int		i;
	int		j;

	i = ft_strlen(str) + 1;
	new_line = ft_calloc(i, sizeof(*new_line));
	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] != c) || ft_closed_quote(str, i) == 1)
		{
			new_line[j] = str[i];
			j++;
		}
		i++;
	}
	return (new_line);
}

//retourne 1 si '| |':
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

// va retourner un prompt vide si le pipe est tout devant, a la fin, ou en double
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
