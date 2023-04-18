#include "minishell.h"

//thomas et tosh est passe par la

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
