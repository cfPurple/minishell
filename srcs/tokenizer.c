#include "minishell.h"

int	tokenizer(t_token *token)
{
    t_token	*current;
	int		last_token;

	current = token;
	last_token = -1;
	while (current)
	{
		current->type = add_type(current->word, last_token);
		last_token = add_type(current->word, last_token);
		current = current->next;
	}
	if (parsing_check(token) == ERROR)
		return (ERROR);
	else
		return (expander(token));
}