#include "minishell.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)*av;
    char* input;

    while ((input = readline("> ")) != NULL)
    {
       free(input);
    }
}
