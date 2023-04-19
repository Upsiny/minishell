#include "../includes/minishell.h"
// #include "../includes/lexer_parser.h"

void sigint_handler(int sig)
{
	if (sig == 2)
		printf("\n");
	return ;
}

int	main(int ac, char **av, char **envp)
{
	(void)*av;
	(void)*envp;
	t_data	*data;

	data = init_struct(envp);
	if (ac != 1)
		return (1); // passer par une fonction erreur
	if (!data)
		return (1); // passer par une fonction erreur
	while (1)
	{
	//	ft_signal();// faire une fonction pour les signaux
		signal(SIGINT, sigint_handler);
    	data->prompt = readline("minishell $> ");
		if (data->prompt == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		/*else if (data->prompt != NULL)
		{
			//travail
		}*/
		free(data->prompt);
	}
}
