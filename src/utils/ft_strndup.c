/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:22:29 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/05 17:10:29 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t		len;
	const char	*ptr;
	char		*dup; 
	size_t		i;

	i = 0;
	len = 0;
	ptr = src;
	dup = NULL;
	while (*ptr && len < n)
	{
		ptr++;
		len++;
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return NULL;
	ptr = src;
	while (*ptr && i < len)
	{
		dup[i] = *ptr;
		ptr++;
		i++;
	}
	dup[i] = '\0';
    return (dup);
}
