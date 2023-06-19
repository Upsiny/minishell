/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:58:11 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/16 18:34:56 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	int				i;
	long long int	neg;
	long long int	res;

	if (!ft_strncmp("-99999999999999999999999999", str, ft_strlen(str)))
		return (0);
	if (!ft_strncmp("99999999999999999999999999", str, ft_strlen(str)))
		return (-1);
	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
/*int main(int ac, char **av)
{
	printf("%d",ft_atoi(av[1]));
}*/
