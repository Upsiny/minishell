/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:00:33 by tpaufert          #+#    #+#             */
/*   Updated: 2022/03/30 19:08:23 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_ftft(int n, char *str, int i)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n == -2147483648)
	{
		free(str);
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i--;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nbrlen(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	*str = 0;
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str = ft_ftft(n, str, i);
	return (str);
}
/*#include <stdio.h>
#include <limits.h>
int	main()
{
	printf("%s", ft_itoa(INT32_MIN));
}*/
