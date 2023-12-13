#include "minishell.h"

void print_token_list(t_token *lst)
{
    while (lst)
    {
        printf("%s\n", lst->word);
        printf("%i\n", lst->type);
        lst = lst->next;
    }
}