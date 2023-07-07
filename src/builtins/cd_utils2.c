/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:22:28 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/07 17:26:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*recup_oldpwd(char **str)
{
	char	*oldpwd;
	int		i;

	i = 0;
	oldpwd = NULL;
	while (str[i])
	{
		if (ft_strncmp(str[i], "OLDPWD=", 7) == 0)
		{
			oldpwd = ft_strdup3(str[i]);
			break ;
		}
		i++;
	}
	return (oldpwd);
}

int	recup_new_pwd(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PWD=", 4) == 0)
		{
			while (str[i][j] != '\0')
				j++;
			if (str[i][j] == '\0')
				break ;
		}
		i++;
	}
	while (str[i][j] != '/')
		j--;
	return (j);
}

char	*verif_pwd(char *line)
{
	char	*tmp;

	if (ft_strcmp(line, "PWD=") == 0)
		tmp = ft_strjoin(line, "/");
	else
		tmp = ft_strdup3(line);
	return (tmp);
}

char	*join_var(char *str1, char *new_val)
{
	char	*dest;
	char	*cpy;
	int		i;
	int		j;

	j = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(new_val) + 1));
	i = 0;
	while (new_val[i] != '=')
		i++;
	i += 1;
	while (new_val[i])
		cpy[j++] = new_val[i++];
	cpy[j] = '\0';
	dest = ft_strjoin(str1, cpy);
	free(cpy);
	return (dest);
}

void	cpy_value(char *name_var, char **str, char *new_val)
{
	char	*ret;
	int		i;

	i = 0;
	ret = join_var(name_var, new_val);
	while (str[i])
	{
		if (ft_strncmp(str[i], name_var, ft_strlen(name_var)) == 0)
		{
			free(str[i]);
			str[i] = ft_strdup3(ret);
			break ;
		}
		i++;
	}
	free(ret);
}
