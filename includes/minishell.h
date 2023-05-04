/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:47:27 by hguillau          #+#    #+#             */
/*   Updated: 2023/05/04 14:27:39 by tpaufert         ###   ########.fr       */
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

enum
{
	TOKEN_PIPE,
	TOKEN_STRING,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_REDIR,
}	e_type;

typedef struct s_cmd
{
	char	**cmd;
	char	**stdin;
	char	**stdout;
}	t_cmd;

/*typedef struct s_lexer
{
	char			*content;
	int				token_type;
	int				index;
	struct s_lexer	*next;
}	t_lexer;*/

typedef struct s_data
{
	t_cmd	*st_cmd;
	pid_t	pid;
	char	*prompt;
	char	**cp_env;
	t_list	*s_lex;
	int		lexer_check;
	char	lexer_char;
	int		index_lexer;
}	t_data;

//////////// Lexer_Parser //////////////////

t_data	*init_struct(char **envp);
char	**ft_tabcpy(char **tab);
void	lexer_advance(t_data *data);
void	init_lexer(t_data *data);
int		lexer_work(t_data *data);
void	ft_lexer_alpha(t_data *data);
int		ft_lexer_quotes(t_data *data);
int		ft_lexer_redir(t_data *data);
int		ft_lexer_pipe(t_data *data);
void	implement_list(t_data *data, int type, int index, int start);
//char	*verif_pipes(char *prompt);

//////////// Signaux ////////////////

void	ft_signaux(void);

//////////// Erreurs ///////////////

void	ft_error_msg(char *msg);
void	error_lexer(t_data *data, char *msg);

//////////// BUILTINS //////////////

void	pwd(void);

//////////// UTILS /////////////////

void	*free_ptr(void *ptr);
void	print_list(t_data *data);
int		ft_isspace(char c);

#endif
