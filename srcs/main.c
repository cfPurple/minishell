#include "minishell.h"

int	g_error;

int main(int ac, char **av)
{
    char *str;

    (void)av;
    if (ac != 1)
        return (0);
    while(1)
    {
        str = readline("minishell $> ");
        if (str == NULL)
            break;
        parse_line(str);
        add_history(str);
        rl_on_new_line();
        free(str);
    }
    return (0);
}