#include "minishell.h"

int	ft_print_error_msg(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (0);
}

void    print_pars_err(char *str)
{
	g_error = 2;
	ft_print_error_msg("$> bash : syntax error near unexpected token");
	write(STDERR_FILENO, " '", 2);
	ft_putstr_fd(str, STDERR_FILENO);
	write(STDERR_FILENO, "'", 1);
	write(STDERR_FILENO, "\n", 1);
}
