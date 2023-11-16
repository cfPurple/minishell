#include <minishell.h>

int line_to_token(char *str)
{
    char    **tab;
    t_token *token;

    tab = line_to_tab(str);
    if (tab == NULL)
        return (ERROR);
    token = tab_to_token(tab);
    free(tab);
    if (token == NULL)
        return (ERROR);
    return (SUCCESS);
}