#include "minishell.h"

void    print_pars_err(char *str)
{
	g_error = 2;
    ft_putstr_fd("ERROR_PARSING '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
}