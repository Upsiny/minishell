/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:08:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/03/07 13:28:57 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lenline(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_len(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tot;

	i = -1;
	j = -1;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tot = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!tot)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		tot[i] = s1[i];
	while (s2[++j])
		tot[i + j] = s2[j];
	tot[i + j] = '\0';
	free(s1);
	return (tot);
}

char	*ft_dup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1[i])
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_lenline(s1) + 2));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\n' && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
