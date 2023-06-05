/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:23:44 by tpaufert          #+#    #+#             */
/*   Updated: 2023/05/05 15:06:51 by tpaufert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)*av;
	data = init_struct(envp);
	if (ac != 1)
		ft_error_msg("no arguments accepted");
	if (!data)
		ft_error_msg("Malloc Error");
	while (1)
	{
		ft_signaux();
		data->pid = -1;
		data->prompt = readline("minishell de mort (҂◡_◡) > ");
		add_history(data->prompt);
		if (data->prompt == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		init_lexer(data);
		//data->st_cmd->cmd = ft_split(data->prompt, ' '); //A supprimer, juste pour test builtins
		if (!lexer_work(data))// Dans token type strings: supprimer les quotes (si circuit fermer)
		{
	//		print_list(data); // erreur dans s_lex, le premier maillon a un content vide
			ft_check_lst(data);
			//exec_builtins(data->st_cmd->cmd); // mettre tout la fin dans ces quotes
		}
//		check_line(data); //check la ligne du prompt si $ est present;
//		verif_cmdquotes(data); //gerer les cotes en pleinmilieux des cmds;
//		data->prompt = verif_pipes(data->prompt); //check les doubles pipes du prompt
//		if (data->prompt != '\0')
//		{
//			data->st_cmd->cmd = my_split(data->prompt); //transformer le char ** en structure de cmd;
//			if (data->cmd != NULL) //!! actions du minishell !!
//			{
//				do_cmd(data.cmd);//controle des cmds -> rapport aux builtins, ou, commandes existantes du PATH;
//				redir_pipe(data, data.cmd);//fonction qui gere les redir si il y a des pipes et plusieurs cmds;
//				free_cmd(data.cmd);//fonction free cmds
//			}
//		}
//		free(data->prompt);
	}
//	clear_history();
//	free_minishell(data);
}
