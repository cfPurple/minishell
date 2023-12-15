#include "minishell.h"

int display_and_read(void)
{
    char *str;

    while(1)
    {
        str = readline("minishell $> ");
        if (str == NULL)
            break;
        line_parsing(str);
        add_history(str);
        rl_on_new_line();
        free(str);
    }
    return (SUCCESS);
}