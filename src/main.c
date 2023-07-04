/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:23:44 by tpaufert          #+#    #+#             */
/*   Updated: 2023/07/04 13:29:47 by hguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
//ne pas oublier de stocker dans nb_cmds le nombre de cmds, sinon le builtin exit ne fonctionne pas pareil
//bah fait le
int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	(void)*av;
	data = init_struct(envp);
	if (ac != 1)
		ft_error_msg("no arguments accepted");
	if (!data)
		ft_error_msg("Malloc Error");
	ft_signaux();
	while (1)
	{
		data->pid = -1;
		data->prompt = readline("minishell de mort (҂◡_◡) > ");
		add_history(data->prompt);
		if (data->prompt == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		init_lexer(data);
	//	data->st_cmd->cmd = ft_split(data->prompt, ' '); //A supprimer, juste pour test builtins
		if (!lexer_work(data))// Dans token type strings: supprimer les quotes (si circuit fermer)
		{
			ft_check_lst(data); // a supprimer quand la condition ci dessous est complete
		//	print_list(data); // erreur dans s_lex, le premier maillon a un content vide
		//	if (!ft_check_lst(data)) // securiter a valider quqnd les free seront fait !
		//	{
		//		data->nb_cmds = 1; // pour exit, il faut indiquer que cest la seule cmds
		//		redir_builtins_or_execve(data, data->st_cmd->cmd); // mettre tout la fin dans ces quotes
		//		free_ptr(data->s_lex);
		//	}
		}
		ft_free_lst(data);
		free(data->content_here);
		free(data->prompt);
	}
//	free_minishell(data);
}
