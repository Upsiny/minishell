#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "../src/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h> //to delete and Vendor
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
	char	*line;
} t_data;

t_data	*init_struct(char **envp);

#endif
