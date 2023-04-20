#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

void rl_replace_line(const char *text, int clear_undo);

void	ft_ctrl_c(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	ft_signaux()
{
	signal(SIGINT, ft_ctrl_c);
}
