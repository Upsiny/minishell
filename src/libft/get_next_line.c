/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:07:36 by tpaufert          #+#    #+#             */
/*   Updated: 2023/03/09 17:09:43 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fin(char *fin, char *reserve, int i)
{
	int	j;

	j = 0;
	while (reserve[i + j] != '\0')
	{
		fin[j] = reserve[i + j];
		j++;
	}
	fin[j] = '\0';
	free(reserve);
	return (fin);
}

char	*ft_nettoyage(char *reserve)
{
	int		i;
	char	*fin;

	if (reserve[0] == '\0')
	{
		free(reserve);
		return (NULL);
	}
	i = ft_lenline(reserve);
	if (reserve[i] == '\n')
		i++;
	fin = (char *) malloc(sizeof(char) * ((ft_len(reserve) - i + 1)));
	if (!fin)
	{
		free(reserve);
		return (NULL);
	}
	fin = ft_fin(fin, reserve, i);
	return (fin);
}

int	retour_a_la_ligne(char *reserve)
{
	int	i;

	i = 0;
	if (reserve == NULL)
		return (0);
	while (reserve[i] != '\0')
	{
		if (reserve[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*lire_et_reserve(int fd, char *reserve, int lecture)
{
	char	*buff;

	buff = malloc(sizeof(buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!(retour_a_la_ligne(reserve)) && lecture != 0)
	{
		lecture = read(fd, buff, BUFFER_SIZE);
		if (lecture == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[lecture] = '\0';
		reserve = ft_join(reserve, buff);
	}
	free(buff);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*ligne;
	int			lecture;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lecture = 1;
	reserve = lire_et_reserve(fd, reserve, lecture);
	if (reserve == NULL)
		return (NULL);
	ligne = ft_dup(reserve);
	if (!ligne && !reserve)
	{
		free(reserve);
		return (NULL);
	}
	reserve = ft_nettoyage(reserve);
	return (ligne);
}
/*#include <fcntl.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	int		fd;
	int i = 200;
	
	fd = open(av[1], O_RDONLY);
	char *get;
	get=get_next_line(fd);
	while (i)
	{
		printf("%s", get);
		get=get_next_line(fd);
		i--;
	}
	free(get);
}*/
