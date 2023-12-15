#include "minishell.h"

int	g_error;

int main(int ac, char **av, char **env)
{
    (void) av;

    if (ac != 1)
        return (0);
    minishell(ac, av, env);
    return (0);
}