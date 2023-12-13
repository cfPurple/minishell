#include "minishell.h"

void print_pars_err(char *str)
{
    g_error = 2;
    ft_putstr_fd(ERROR_PARSING, STDERR_FILENO);
    write(STDERR_FILENO, " '", 2);
    ft_putstr_fd(str, STDERR_FILENO);
    write(STDERR_FILENO, "'\n", 2);
}