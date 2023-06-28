/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:47:27 by hguillau          #+#    #+#             */
/*   Updated: 2023/06/28 16:39:58 by tpaufert         ###   ########.fr       */
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
# include <stdbool.h>

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
	char	**cmd; //2 string max (la commande et option eventuel)
	char	**stdin;
	char	**stdout;
}	t_cmd;

/*typedef struct s_lexer
{
	char			*content;
	int				token_type;
	int				index;
	char			**cmd;
	char			**stdin;
	char			**stdout;
	struct s_lexer	*next;
}	t_lexer;*/

typedef struct s_data
{
	t_cmd	*st_cmd;
	pid_t	pid;
	char	*prompt;
	char	**cp_env;
	char	**cp_exp;
	t_list	*s_lex;
	int		lexer_check;
	char	lexer_char;
	int		index_lexer;
	bool	in_pipe;
	int		nb_cmds;
	char	*val_home;
	char	*pwd;
	char	*old_pwd;
	int		ret_err; //rends cette variable en globale ! merci helian on est oblige. CEST BEN QUI LE DIT
}	t_data;

//////////// Lexer_Parser //////////////////

t_data	*init_struct(char **envp);
char	**ft_tabcpy(char **tab);
void	lexer_advance(t_data *data);
void	init_lexer(t_data *data);
int		lexer_work(t_data *data);
int		ft_lexer_alpha(t_data *data);
int		ft_lexer_quotes(t_data *data);
int		ft_check_endquote(t_data *data, char c);
int		ft_lexer_redir(t_data *data);
int		ft_lexer_pipe(t_data *data);
void	implement_list(t_data *data, int type, int index, int start);
//char	*verif_pipes(char *prompt);
int		ft_check_lst(t_data *data);
void	ft_free_lst(t_data *data);

//////////// Signaux ////////////////

void	ft_signaux(void);

//////////// Erreurs ///////////////

void	ft_error_msg(char *msg);
int		ft_error_parsing(char *msg);
void	error_lexer(char *msg);
void	ft_print_error_msg3(char *s1, char *s2, char *s3);

//////////// BUILTINS //////////////

int		ft_nb_slash(char *str);
void	pwd_builtin(void);
char	*get_home_value(char	**cp_env);
void	get_pwd(t_data *data);
void	cd_builtin(t_data *data, char **cmd);
void	cd_go_home(t_data *data);
int		cd_go_arg(char *arg);
void	echo_builtin(char **cmd);
void	exit_builtin(t_data *data, char **cmd);
void	env_builtin(t_data *data, char **cmd);
void	unset_builtin(t_data *data, char **cmd);

//////////// EXECUTION /////////////

int		ft_strcmp(char *s1, char *s2);
void	ft_set_path_and_execve(t_data *data, char **cmd);
char	**verif_cmd_struct(char **cmd);
void	redir_builtins_or_execve(t_data *data, char **cmd);

//////////// UTILS /////////////////

void	*free_ptr(void *ptr);
void	free_tab(char **tab);
void	print_list(t_data *data);
int		ft_isspace(char c);
int 	ft_count_list(t_list *head);
int		ft_tab_len(char **tab);
char	**ft_cpytab(char **tab);

#endif
