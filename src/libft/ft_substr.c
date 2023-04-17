/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:29:22 by tpaufert          #+#    #+#             */
/*   Updated: 2023/03/10 16:01:18 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_len(char const *s, size_t len)
{
	if (len >= ft_strlen(s))
		return (ft_strlen(s));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(1 * sizeof(char));
		str[i] = 0;
		return (str);
	}
	str = (char *)malloc((ft_check_len(s + start, len) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = start;
	while (s[j] && i < len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
/*#include <stdio.h>
int main()
{
	char *str = ft_substr("tripouille", 100, 1);
	printf("%s", str); 
}*/
