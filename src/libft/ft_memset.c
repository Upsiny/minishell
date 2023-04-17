/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:33:49 by tpaufert          #+#    #+#             */
/*   Updated: 2022/04/01 16:09:22 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *b, int c, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)b;
	while (len)
	{
		str[i] = c;
		len--;
		i++;
	}
	return (b);
}
/*int main()
{
	void *n = "oui";
	int c = 1;
	size_t len = 2;
	ft_memset(n, c, len);
}*/
