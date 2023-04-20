/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:47:27 by hguillau          #+#    #+#             */
/*   Updated: 2023/04/17 18:35:12 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../src/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char 	**cmd;
	char	**stdin;
	char	**stdout;
} t_cmd;

typedef struct s_data
{
	t_cmd	**cmd;
	pid_t	pid;
	char	*prompt;
} t_data;

//////////// Lexer_Parser //////////////////

t_data	*init_struct(char **envp);

//////////// Signaux /////////////////

void	ft_signaux();

#endif
