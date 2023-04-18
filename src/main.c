#include "../includes/minishell.h"

//helian est passe par la

void sigint_handler(int sig)
{
	(void)sig;
	return ;
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)*av;
	(void)*env;
    char* input;

	while (1)
	{
		signal(SIGINT, sigint_handler);
    	while ((input = readline("minishell $> ")) != NULL)
    	{
 	      	free(input);
    	}
	}
}
