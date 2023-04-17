#include "../includes/minishell.h"

//helian est passe par la

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)*av;
	(void)*env;
    char* input;

    while ((input = readline("Coquille Minuscule > ")) != NULL)
    {
       free(input);
    }
}
