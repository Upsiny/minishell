/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:23:19 by tpaufert          #+#    #+#             */
/*   Updated: 2023/06/28 16:25:45 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_error_msg1(char *s1)
{
	write(2, s1, ft_strlen(s1));
}

void	ft_print_error_msg2(char *s1, char *s2)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
}

void	ft_print_error_msg3(char *s1, char *s2, char *s3)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
}

void	ft_print_error_msg4(char *s1, char *s2, char *s3, char *s4)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	write(2, s4, ft_strlen(s4));
}

void	ft_print_error_msg5(char *s1, char *s2, char *s3, char *s4, char *s5)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	write(2, s4, ft_strlen(s4));
	write(2, s5, ft_strlen(s5));
}
