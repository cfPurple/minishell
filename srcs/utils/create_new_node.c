#include "minishell.h"

t_token	*create_new_node(char *str)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (0);
	node->word = str;
	node->next = NULL;
	return (node);
}