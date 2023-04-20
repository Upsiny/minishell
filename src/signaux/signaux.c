#include "../../includes/minishell.h"

void	ft_ctrl_c(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_replace_line("", 0);
	}
}

void	ft_signaux()
{
	signal(SIGINT, ft_ctrl_c);
}
