/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:23:44 by tpaufert          #+#    #+#             */
/*   Updated: 2023/04/24 14:36:11 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)*av;
	data = init_struct(envp);
	if (ac != 1)
		ft_error_msg("no arguments accepted"); // passer par une fonction erreur
	if (!data)
		ft_error_msg("Malloc Error"); // passer par une fonction erreur
	while (1)
	{
		ft_signaux();
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
			data->st_cmd->cmd = my_split(data->prompt); //split modifier pour minishell, on enregistre les cmds...
//			if (data->cmd != NULL) //!! actions du minishell !!
//			{
//				check_cmd(data.cmd);//controle des cmds -> rapport aux builtins.
//				redir_pipe(data, data.cmd);//actions pipes et execve des builtins... MINISHELL QUOI
//				free_cmd(data.cmd);//fonction free cmds
//			}
		}
		free(data->prompt);
	}
	rl_clear_history();
//	free_minishell(data);
}
