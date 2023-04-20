#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	(void)*av;
	t_data	*data;

	data = init_struct(envp);
	if (ac != 1)
		return (1); // passer par une fonction erreur
	if (!data)
		return (1); // passer par une fonction erreur
	while (1)
	{
		ft_signaux();// faire une fonction pour les signaux
		data->pid = -1;
    	data->prompt = readline("minishell $> ");
		if (data->prompt == NULL)
		{
			printf("exit\n");
			exit(0);
		}
//		add_history(data->prompt); //enregistrer prompt
//		check_line(data); //check la ligne du prompt;
//		verif_cmdcotes(data); //check les cotes des cmds;
//		data->prompt = verif_pipes(data->prompt); //check les pipes du prompt
		if (data->prompt[0] != '\0')
		{
			add_history(data->prompt);
//			data->cmd = my_split(); //split modifier pour minishell, on enregistre les cmds...
//			if (data->cmd != NULL) //!! actions du minishell !!
//			{
//				check_cmd(data.cmd);//controle des cmds -> rapport aux builtins.
//				redir_pipe(data, data.cmd);//actions pipes et execve des builtins... MINISHELL QUOI
//				free_cmd(data.cmd);//fonction free cmds
//			}
		}
		free(data->prompt);
	}
//	free_minishell(data);
}
